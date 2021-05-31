#ifndef _MAZE_
#define _MAZE_

//
#include <stdio.h>
#include "matriz.h"
#include "cell.h"
#include "libpgm.h"

#include <ctime>
#include <stack>
#include <iostream>

//
#define COR_FUNDO 255	
#define COR_LINHA 0

struct node {
   cell* pt;
   node* next;
   node(){

   }
   node(cell* pt, node* next){
      this->pt  = pt;
      this->next = next;
   }
};

class maze {
   int nrows, ncols;
   matriz<cell*> mat;
public:
   maze(int nc, int nr);
   void generate();
   cell* takecell(int col, int row);
   node* getway(cell* A, cell* B);
   void line(pgm* img, 
          int x, int y, char ort, 
          int L, char color);	
   void saveAsImage(int L, const char* filename);
   void strike(int col, int row, char ort);
   bool isStriked(int col, int row, char ort);
   bool haveFriend(int col, int lin);
   bool isFriend(int col, int lin, char pos);
   bool isRanged(int col, int lin);
   std::string isContinue(int col, int lin);
   void zeraVisited();
   bool isBroken(int col, int lin, char pos);
};

#endif