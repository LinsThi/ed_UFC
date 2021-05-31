#ifndef BNUM
#define BNUM

#include <string>
#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;

struct nodo {
   int key;
   nodo* next;
   nodo(int x); 
   nodo(int x, nodo* next){
      this->key  = x;
      this->next = next;
   }
};

class bnum {
bnum* resultado;
protected:
   //Numero de digitos
   int d;
   //nodo raiz
   nodo* number;
public:
   bnum();
   /**
    * Inicializa um BigNumber com um inteiro
    * */
   bnum(int x, int d);
   /**
    * Inicializa um BigNumber com uma String
    * */
   bnum(string s, int d);
   /**
    * Inicializa um BigNumber com um BigNumber
    * */
   bnum(const bnum& b);
   /**
    * Atribui um BigNumber ao BigNumber origem
    * @param b BigNumber para atribuição 
    * */
   bnum& operator=(const bnum& b);
   /**
    * Soma um BigNumber com um inteiro
    * */
   bnum& operator+(int x);
   /**
    * Soma um BigNumber com um BigNumber
    * */
   bnum& operator+(const bnum& b);
   /**
    * Multiplica um BigNumber com um inteiro
    * */
   bnum& operator*(int x);
   /**
    * Multiplica um BigNumber com um BigNumber
    * */
   bnum& operator*(const bnum& b);
   /**
    * Retorna se dois BigNumbers são iguais
    * */
   bool operator==(const bnum& b);
   /**
    * Retorna a String de um BigNumber
    * */
   string toStr();
   void igualaNodo(nodo* num, nodo* resultado, bnum* result);
   ~bnum();
};

#endif