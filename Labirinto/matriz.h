#ifndef _MATRIZ_
#define _MATRIZ_

#include <stdio.h>

template <typename T>
class matriz {
   T *data;
   int ncols, nrows; 
public:
   matriz(int nc, int nr) {
       ncols = nc;
       nrows = nr;
       data = new T[ncols*nrows];
   } 
   T& operator() (int col, int row) {
       return data[row*ncols + col];
   }
   ~matriz() {
        delete data;
   }
};

#endif