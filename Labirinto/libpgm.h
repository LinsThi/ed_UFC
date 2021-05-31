#ifndef __LIBPGM__
#define __LIBPGM__

#include <stdio.h>

class point {
   int _x, _y;
public:
   point(int x, int y);
   point(const point& p);
   point& operator=(const point& p);
   bool isNull();
   int& x();
   int& y();
};
	
class pgm {
   char *data;
   int ncols, nrows;
   void copyFrom(const pgm& p); 
public:
   pgm(const char* filename);
   pgm(char, int, int);
   
   pgm(const pgm& p);
   pgm& operator=(const pgm& p);

   char& pixel (int col, int row);
   void saveAs(const char* filename); 
   int nCols()const;
   int nRows()const;
  
   // TRANPOSIÇAO 
   pgm trans();
   // ***

   ~pgm();
};

#endif