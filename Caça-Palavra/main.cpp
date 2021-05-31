#include "puzzle.h"

#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

   /*char letter;
   ifstream input;
   input.open("file.txt");
   input >> letter;
   cout << letter;
   ofstream output;
   output.open("file.txt");
   output << "Eu sou o Douglas";
   output.close();
   */
  
   mPair element;
   list<string> ls;
   ls.push_front("backs");
   ls.push_front("ilha");
   ls.push_front("colibri");
   ls.push_front("gato");
   ls.push_front("casa");
   matrix m(100, 100, ls);
   createPuzzle(100, 100, ls, "file.txt", m);
   m.save("file.txt");
   solvePuzzle(ls, "file.txt", "resolvido.txt", m);
   m.save("resolvido.txt");
   return 0;
}