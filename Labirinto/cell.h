#ifndef _CELL_
#define _CELL_


#define NORTE 0
#define SUL   1
#define LESTE 2
#define OESTE 3

class cell {
    bool walls[4];
    int col, row;
    bool visited;
public:
   cell(int col, int row);
   void drop (char d);
   bool isDroped (char d);      
   bool& visit(); 
   bool isVisited();
   int getLinha();
   int getColuna();
}; 

#endif