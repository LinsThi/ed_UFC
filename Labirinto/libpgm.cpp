#include "libpgm.h"

point::point(int x, int y) {
  _x = x;
  _y = y;
}

int& point::x(){
   return _x;
}

int& point::y(){
   return _y;
}
 
pgm::pgm(char color,  int nc, int nr) {  
   data = 0;
   ncols = nc;
   nrows = nr;
   int len = nc*nr;   
   data = new char[len];
   for (int k=0; k<len; k++)
      data[k] = color;  
}

void pgm::copyFrom(const pgm& p){
    ncols = p.ncols;
    nrows = p.nrows;    
    int len = p.ncols*p.nrows;
    delete [] data;
    data = new char[len];
    for (int k=0; k<len; k++)
        data[k] = p.data[k];     
} 

pgm::pgm(const pgm& p) { copyFrom(p); }

pgm& pgm::operator=(const pgm& p) { 
    copyFrom(p); 
    return *this;
}

pgm::pgm(const char* filename) 
{   FILE* file = fopen(filename, "r");    
    char s[100], ch; 
    fscanf(file, "%[^\n]",  s);
    int v;   
    fscanf(file, "%d %d %d", &ncols, &nrows, &v);    
    if (v!=255) {
        printf("arquivo invalido\n");
        return;
    } 
    int len = ncols * nrows;
    data = new char[len];
    for (int k = 0; k < len; k++) {
        fscanf(file, "%c", &ch);
        data[k] = ch; 
    }
    fclose(file);
}

char& pgm::pixel(int col, int row) {
   int p = row * ncols + col;
   if (col>=0 && col<ncols &&
       row>=0 && row<nrows)
      return data[p];
   else
      return data[0];
}

void pgm::saveAs(const char* filename) 
{
   FILE * file = fopen(filename, "w");

   fprintf(file,"P5\n%d %d\n255\n", ncols, nrows);
   int len = ncols * nrows;

   for (int k = 0; k<len; k++)
       fprintf(file, "%c", data[k] );      
   fclose(file);     
}

int pgm::nCols()const {
   return ncols;
}

int pgm::nRows()const {
   return nrows;
}

pgm pgm::trans() {
   char color = 0;
   pgm out(color, nrows, ncols);   
   for (int col=0; col<ncols; col++)
      for (int row=0; row<nrows; row++)
         out.pixel(row, col)=pixel(col,row);
   return out;
}

pgm::~pgm() {
   if (data != 0)
       delete [] data;
}