#include "matrix.h"
#include <string>
matrix::matrix(int nc, int nr, list<string> &mywords)     {
    ncols = nc;
    nrows = nr; 
    data = new mPair[ncols * nrows];
    list<string>::iterator it; 
    words = mywords;
}
mPair& matrix::cell(int i, int j) {
    int m = ncols * nrows;
    int p = ncols * j + i;
    return data[p];    
}
void matrix::atribuir(mPair mat[]){
    data = mat;
}
void matrix::save(string file) {
    ofstream stream(file.c_str(), ofstream::out);
    stream << ncols << endl;
    for(int col=0; col<ncols; col++)
       for(int row=0; row<nrows; row++) 
       {
           mPair pair = cell(col, row);   
           stream << col << " " 
                  << row << " "
                  << pair.letter << " "
                  << pair.marked << "\n";
    }
    stream.close();
}
void matrix::matrix::reset() {
    for (int col = 0; col < ncols; col++)
       for(int row = 0; row < nrows; row++) 
       {
           mPair pair = cell(col, row);
           pair.marked = 0;
           cell(col, row) = pair;    
       }
}        
matrix::~matrix() {
   delete [] data;
}