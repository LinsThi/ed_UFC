#include <iostream>
#include <string>
#include <fstream>
#include "listaord.h"

using namespace std;

struct nodoTree{
   int frequencia;
   char valor;
   string code;
   nodoTree *left, *right;

   nodoTree(){

   }

   nodoTree(int frequencia, char valor){
      this->frequencia = frequencia;
      this->valor = valor;
      this->left = this->right = 0;
   }

   nodoTree(nodoTree* antiga){
      this->frequencia = antiga->frequencia;
      this->valor = antiga->valor;
      this->left = antiga->left; this->right = antiga->right;
   }

   nodoTree(nodoTree um, nodoTree dois){
      this->frequencia = um.frequencia+dois.frequencia;
      this->left = new nodoTree(um); 
      this->right = new nodoTree(dois);
   }

   bool operator<=(nodoTree c) {
      return (frequencia<=c.frequencia);
   }
   bool operator>(nodoTree c) {
      return (frequencia>c.frequencia);
   }
   bool operator==(nodoTree c) {
      return (frequencia==c.frequencia);
   }
   bool operator!=(nodoTree c) {
      return (frequencia!=c.frequencia);
   }
};

class huffman{
   
public:
   void generateTree(string arquivo);
};