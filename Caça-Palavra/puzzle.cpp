#include <list>
#include <string>
#include <cstdlib>

#include "puzzle.h"

using namespace std;

char altAlfa(){
   char alfa[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
   return alfa[rand()%26];
}

char altLado(){
   char lado[4] = {'c', 'b', 'e', 'd'};
   return lado[rand()%4];
}

void preencheMatriz(int nr, int nc, mPair* mt){
   for(int x1 = 0; x1 < nr; x1++){
       for(int x2 = 0; x2 < nc; x2++){
         mt[nc * x1 + x2].letter = altAlfa();
         mt[nc * x1 + x2].marked = false;
       }
   }
}

bool isRange(int i, int j, int nrows, int ncols, char dire, int aux){
   bool c;
   switch(dire){
      case 'c':
         c = (i - aux - 1 >= 0);
      break;
      case 'b':
         c = (i + aux - 1 < nrows);
      break;
      case 'd':
         c = (j + aux - 1 < ncols);
      break;
      case 'e':
         c = (j - aux - 1 >= 0);
      break;
   }
   return c;
}
bool consegue(int nc, int l, int c, mPair mt[], char dir, int cot, string palavra){
   int ct = 0; int ct2 = cot; int auxPl = 0;
   if(dir == 'c'){
      for(int i = l; cot > 0; i--, cot--, auxPl++){
         if(mt[nc * i + c].marked == 0 || mt[nc * i + c].letter == palavra[auxPl]){
            ct++;
         }
      }
   }else if(dir == 'b'){
      for(int i = l; cot > 0; i++, cot--, auxPl++){
         if(mt[nc * i + c].marked == 0 || mt[nc * i + c].letter == palavra[auxPl]){
            ct++;
         }
      }
   }else if(dir == 'e'){
      for(int i = c; cot > 0; i--, cot--, auxPl++){
         if(mt[nc * l + i].marked == 0 || mt[nc * l + i].letter == palavra[auxPl]){
            ct++;
         }
      }
   }else{
      for(int i = c; cot > 0; i++, cot--, auxPl++){
         if(mt[nc * l + i].marked == 0 || mt[nc * l + i].letter == palavra[auxPl]){
            ct++;
         }
      }
   }
   if(ct == ct2){
      return true;
   }else{
      return false;
   }
}

void createPuzzle(int ncols, int nrows, list<string> &words, string matrixFile, matrix& m){
   // IMPLEMENTAR PARTE I
   mPair *matriz = new mPair[ncols * nrows]; mPair elem;
   preencheMatriz(nrows, ncols, matriz);
   list<string>::iterator it;
   for(it = words.begin(); it != words.end(); ++it){
      int cont = 0; int col, lin, auxLs = 0;
      string a = *it;
      cont = a.length();
      if(cont <= ncols){
         int repetir = 0;
         while(repetir < (ncols*nrows)/2){
            bool contaux = false;
            char ld = altLado();
            col = rand()%ncols;
            lin = rand()%nrows;
            repetir++;
            if(!isRange(lin, col, nrows, ncols, ld, cont)){
               continue;
            }
            if(!consegue(ncols, lin, col, matriz, ld, cont, a)){
               continue;
            }
            elem.letter = a[auxLs];
            elem.marked = true;   
            matriz[ncols * lin + col] = elem;
            cont--;
            if(ld == 'c'){
               for(int i = lin - 1; cont > 0; i--, cont--){
                  elem.letter = a[++auxLs];
                  elem.marked = true;
                  matriz[ncols * i + col] = elem;
               }
            }else if(ld == 'b'){
               for(int i = lin + 1; cont > 0; i++, cont--){
                  elem.letter = a[++auxLs];
                  elem.marked = true;
                  matriz[ncols * i + col] = elem;
               }
            }else if(ld == 'e'){
               for(int j = col - 1; cont > 0; j--, cont--){
                  elem.letter = a[++auxLs];
                  elem.marked = true;
                  matriz[ncols * lin + j] = elem;
               }
            }else{
               for(int j = col + 1; cont > 0; j++, cont--){
                  elem.letter = a[++auxLs];
                  elem.marked = true;
                  matriz[ncols * lin + j] = elem;
               }
            }
            break;
         }
      }
   }
   m.atribuir(matriz);
}

void formaMatriz(int n, char vt[], mPair matriz[]){
   int aux = 0;
   
}

void solvePuzzle(list<string> &words, string inputFileMatrix, string outputFileMatrix, matrix& m){
   // IMPLEMENTAR PARTE II
   ifstream arqv(inputFileMatrix.c_str()); string linha, conversao; int cont = 0, c = 0, l = 0;
   arqv >> linha;
   int nc = stoi(linha);
   char vt[nc*nc];
   mPair *matriz = new mPair[nc * nc];
   for(int i = 0; i < nc; i++){ 
      for(int j = 0; j < nc; j++){
         arqv >> linha;
         arqv >> linha;
         arqv >> linha;
         vt[nc * j + i] = linha[0];
         arqv >> linha;
      }
   }

   cont = 0;
   arqv.close();
   for(int i = 0; i < nc; i++){ // Aqui a matriz inteira fica zerada!
      for(int j = 0; j < nc; j++){
         matriz[nc * i + j].letter = vt[cont++];
         matriz[nc * i + j].marked = false;
      }
   }
   list<string>::iterator it;
   for(it = words.begin(); it != words.end(); ++it){ // Aqui vai resolver a matriz;
      string a = *it; int pl = 0, auxLs = 0; cont = 0;
      pl = a.length();
      int aux3 = pl;
      for(int i = 0; i < nc; i++){
         for(int j = 0; j < nc; j++){
               int aux2 = pl;
               for(int e = j; pl > 0; e--, pl--){// Para esquerda
                  if(matriz[nc * i + e].letter == a[auxLs++]){
                     cont++;
                  }
               }
               if(cont == aux3){
                  for(int l2 = j; cont > 0; cont--, l2--){
                     matriz[nc * i + l2].marked = true;
                  }
                  continue;
               }else{
                  cont = 0; pl = aux2; auxLs = 0;
               }
               for(int d = j; pl > 0; d++, pl--){ // Para direita
                  if(matriz[nc * i + d].letter == a[auxLs++]){
                     cont++;
                  }
               }
               if(cont == aux3){
                  for(int l2 = j; cont > 0; cont --, l2++){
                     matriz[nc * i + l2].marked = true;
                  }
                  continue;
               }else{
                  cont = 0; pl = aux2; auxLs = 0;
               }
               for(int c = i; pl > 0; c--, pl--){ // Para cima
                  if(matriz[nc * c + j].letter == a[auxLs++]){
                     cont++;
                  }
               }
               if(cont == aux3){
                  for(int l2 = i; cont > 0; cont--, l2--){
                     matriz[nc * l2 + j].marked = true;
                  }
                  continue;
               }else{
                  cont = 0; pl = aux2; auxLs = 0;
               }
               for(int b = i; pl > 0; b++, pl--){ // Para baixo
                  if(matriz[nc * b + j].letter == a[auxLs++]){
                     cont++;
                  }
               }
               if(cont == aux3){
                  for(int l2 = i; cont > 0; cont--, l2++){
                     matriz[nc *l2 + j].marked = true;
                  }
                  continue;
               }else{
                  cont = 0; pl = aux2; auxLs = 0;
               }
         }
      }
   }
   m.atribuir(matriz);
}

/* formato

col lin letra status

status:
  0: normal
  1: destacada

*/
