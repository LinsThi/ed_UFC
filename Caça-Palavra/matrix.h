#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

struct mPair { // letter = caractera ou letra / marked = estado da letra
   char letter;
   bool marked;
};

class matrix {
   mPair *data; // vetor das celulas da matrix
   int ncols, nrows;
   list<string> words;
public:
   void reset();
   matrix(int, int, list<string>&);
   mPair& cell(int, int);
   void atribuir(mPair* matr);
   void save(string); // salva o conteudo da matrix
   ~matrix();
};




