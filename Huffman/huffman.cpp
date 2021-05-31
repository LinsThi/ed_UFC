#include "huffman.h"

void zeraVetor(int n[]){
  for(int i = 0; i < 256; i++){
    n[i] = 0;
  }
}

void huffman::generateTree(string arquivo){
///////////////////////////////////////Contagem dos caracteres
  char converter; unsigned char caract; int n[256];
  ifstream arquivoI; arquivoI.open(arquivo, ios::binary);
  zeraVetor(n);
  arquivoI.read(&converter,1);
  while(!(arquivoI.eof())){
    caract = converter;
    for(int i = 0; i < 256; i++){
      if(caract == i){
        n[i]++;
      }
    }
    arquivoI.read(&converter,1);
  }
  arquivoI.close();
///////////////////////////////////////Passagem para a lista ordenada
  listaord<nodoTree> lista;
  for(int i = 0; i < 256; i++){
    if(n[i]!= 0){
      nodoTree H(n[i], i);
      lista << H;
    }
  }
///////////////////////////////////////Montagem da arvore
  nodo<nodoTree>* aux; nodo<nodoTree>* aux2;
  for(aux=lista.printRaiz(),aux2=aux->next;aux2!=nullptr; 
  aux = lista.printRaiz(), aux2 = aux->next){
    nodoTree K(aux->key, aux2->key);
    lista.del(aux->key); lista.del(aux2->key);
    lista << K;
  }
  cout << lista.printRaiz()->key.frequencia << endl;
}