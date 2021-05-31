#include "maze.h"
#include "matriz.h"

//
#define COR_FUNDO 255	
#define COR_LINHA 0

maze::maze(int nc, int nr):mat(nc,nr)
{
   ncols = nc;
   nrows = nr;  
   for (int col=0; col < ncols; col++)
      for(int row=0; row < nrows; row++)
         mat(col, row)=new cell(col, row);                           


}

cell* maze::takecell(int col, int row) 
{ 
    static cell x(1,1);
    if (col>=0 && col<ncols &&
        row>=0 && row<nrows)
       return mat(col, row);
    else
       return &x; 
}

void maze::line(pgm* img,
    int x, int y, char ort, 
    int L, char color) 
{ 
    for (int d=0; d<L; d++) { 
      switch(ort) {
      case NORTE:
         img->pixel(x+d,y) =color;
      break;
      case SUL:
        img->pixel(x+d,y+L) = color;
      break;
      case LESTE:
        img->pixel(x+L,y+d)=color;
      break;  
      case OESTE: 
         img->pixel(x,y+d);
      }
    }
}	

void maze::saveAsImage(int L, const char* filename) 
{
    pgm* img = new pgm(COR_FUNDO, ncols*L, nrows*L);
    int cnt = 0;
    for (int col=0; col<ncols; col++)
        for (int row=0; row<nrows; row++) 
           for (char ort=0; ort<4; ort++) {
               int x = L * col; 
               int y = L * row;
               if (!isStriked(col,row,ort)) {
                   line(img, x, y, ort, L, COR_LINHA);
               }                
           }
   img->saveAs(filename);
   delete img;
}

void maze::strike(int col, int row, char ort) 
{ //@@@  
    takecell(col,row)->drop(ort);

    switch(ort) {
    case NORTE: takecell(col,row+1)->drop(SUL);
         break; 
    case SUL:   takecell(col,row-1)->drop(NORTE);
         break;
    case LESTE: takecell(col+1,row)->drop(OESTE);
         break;
    case OESTE: takecell(col-1,row)->drop(LESTE);
    }
}

bool maze::isStriked(int col, int row, char ort) 
{  
  return takecell(col,row)->isDroped(ort);
}

bool maze::haveFriend(int col, int lin){
    if(isRanged(col, lin+1) && !mat(col,lin+1)->isVisited()){
        return true;
    }
    if(isRanged(col, lin-1) && !mat(col,lin-1)->isVisited()){
        return true;
    }
    if(isRanged(col+1, lin) && !mat(col+1,lin)->isVisited()){
        return true;
    }
    if(isRanged(col-1, lin) && !mat(col-1,lin)->isVisited()){
        return true;
    }
    return false; 
}

bool maze::isFriend(int col, int lin, char pos){
    if(isRanged(col, lin-1) && pos == 0 && !mat(col,lin-1)->isVisited()){
        return true;
    }
    if(isRanged(col, lin+1) && pos == 1 && !mat(col,lin+1)->isVisited()){
        return true;
    }
    if(isRanged(col+1, lin) && pos == 2 && !mat(col+1,lin)->isVisited()){
        return true;
    }
    if(isRanged(col-1, lin) && pos == 3 &&!mat(col-1,lin)->isVisited()){
        return true;
    }
    return false; 
}

bool maze::isRanged(int col, int lin){
    return (col>=0 && col<ncols)&&(lin>=0 && lin<nrows);
}

/* IMPLEMENTAR */
void maze::generate() {
    int lin = clock()%(nrows);  // Escolhendo linha sempre aleatória quando excecutar
    int col = clock()%(ncols);  // Escolhendo coluna sempre aleatória quando excecutar
    cell* cellInit = mat.operator()(col,lin);
    cellInit->visit();

    std::stack<cell*> pil;
    pil.push(cellInit);
    do{
        cell* c = pil.top();
        pil.pop();
        int colu = c->getColuna();
        int linh = c->getLinha();
        bool next = false;
        if(haveFriend(colu, linh)){
            pil.push(c);
            while(!next){ 
                int pos = clock()%4;    // Escolhendo lado sempre aleatório quando excecutar mesmo executando o mesmo arquivo
                switch(pos){
                    case 0:
                        if((linh != 0) && isFriend(colu, linh, pos)){
                            c->drop(NORTE);
                            c->visit();
                            c = mat(colu, (linh-1));
                            c->drop(SUL);
                            c->visit();
                            pil.push(c);
                            next = true;
                        }
                    break;
                    case 1:
                        if((linh != (nrows-1)) && isFriend(colu, linh, pos)){
                            c->drop(SUL);
                            c->visit();
                            c = mat(colu, (linh+1));
                            c->drop(NORTE);
                            c->visit();
                            pil.push(c);
                            next = true;
                        }
                    break;
                    case 2:
                        if((colu != (ncols-1)) && isFriend(colu, linh, pos)){
                            c->drop(LESTE);
                            c->visit();
                            c = mat((colu+1), linh);
                            c->drop(OESTE);
                            c->visit();
                            pil.push(c);
                            next = true;
                        }
                    break;
                    case 3:
                        if((colu != 0) && isFriend(colu, linh, pos)){
                            c->drop(OESTE);
                            c->visit();
                            c = mat((colu-1), linh);
                            c->drop(LESTE);
                            c->visit();
                            pil.push(c);
                            next = true;
                        }
                    break;
                }
            }
        }
    }while(!pil.empty());
}

std::string maze::isContinue(int col, int lin){
    std::string result;
    if(isStriked(col, lin, NORTE) && !mat(col, lin-1)->isVisited()){
        result += "0";
    }
    if(isStriked(col, lin, SUL) && !mat(col, lin+1)->isVisited()){
        result += "1";
    }
    if(isStriked(col, lin, LESTE) && !mat(col+1, lin)->isVisited()){
        result += "2";
    }
    if(isStriked(col, lin, OESTE) && !mat(col-1, lin)->isVisited()){
        result += "3";
    }
    return result; 
}

void maze::zeraVisited(){
    for(int i = 0; i < ncols; i++){
        for(int j = 0; j < nrows; j++){
            mat(i,j)->visit()=false;
        }
    }
}

bool maze::isBroken(int col, int lin, char pos){
    if(isRanged(col, lin-1) && pos == 0 && isStriked(col, lin, pos)){
        return true;
    }
    if(isRanged(col, lin+1) && pos == 1 && isStriked(col, lin, pos)){
        return true;
    }
    if(isRanged(col+1, lin) && pos == 2 && isStriked(col, lin, pos)){
        return true;
    }
    if(isRanged(col-1, lin) && pos == 3 && isStriked(col, lin, pos)){
        return true;
    }
    return false; 
}

node* maze::getway(cell* A, cell* B)
{
    zeraVisited();
    node* ptRaiz = new node();
    ptRaiz->pt = A;
    int coluInit = ptRaiz->pt->getColuna(); // Pegando coluna da celula de saida.
    int linhInit = ptRaiz->pt->getLinha();  // Pegando linha da celula de saida.

    node* ptFinal = new node();
    ptFinal->pt = B;
    int coluFinal = ptFinal->pt->getColuna();// Pegando coluna da celula de chegada.
    int linhFinal = ptFinal->pt->getLinha(); // Pegando coluna da celula de chegada.

    if((coluInit == coluFinal) && (linhInit == linhFinal)){
        std::cout << "Coluna: " << coluFinal << " Linha: " << linhFinal << std::endl;
        return ptRaiz;
    }

    std::stack<cell*> pila;
    A->visit();
    pila.push(A);
    while(pila.top() != B){
        cell* c = pila.top();
        pila.pop();
        int colu = c->getColuna();
        int linh = c->getLinha();
        pila.push(c);

        std::string parede = isContinue(colu, linh);
        if(parede.empty()){
            pila.pop();
            continue;
        }
        int pos = clock()%parede.length();
        switch(parede[pos]){
            case '0':
                c = mat(colu, (linh-1));
                c->visit();
                pila.push(c);
            break;
            case '1':
                c = mat(colu, (linh+1));
                c->visit();
                pila.push(c);
            break;
            case '2':
                c = mat((colu+1), linh);
                c->visit();
                pila.push(c);
            break;
            case '3':
                c = mat((colu-1), linh);
                c->visit();
                pila.push(c);
            break;
         }
    }
    cell* auxCell; std::stack<cell*> pilha;
    while(!pila.empty()){
        pilha.push(pila.top());
        pila.pop();
    }
    node* No = new node();
    ptRaiz->next = No;
    pilha.pop();
    No->pt = pilha.top();
    pilha.pop();
    for(;!pilha.empty();No = No->next, pilha.pop()){
        node* aux = new node(pilha.top(), nullptr);
        No->next = aux;
    }
    
    for(node* almi = ptRaiz; almi != nullptr; almi = almi->next){
        std::cout << "Coluna: " << almi->pt->getColuna() << " " 
        << " Linha: " << almi->pt->getLinha() << std::endl;
    }
    return ptRaiz;
}