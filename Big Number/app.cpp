#include "app.h"


void app::factorial(const bnum& b){
  bnum numero(b);
  int menos = stoi(numero.toStr());
  for(int i = 1; i < menos;i++){
    numero = numero*i;
  }
  ofstream arqv;
  arqv.open("fatorial.txt");

  arqv << "Fatorial é: " << numero.toStr();
  arqv.close();
}

void app::frequencetable(const bnum& number){
  bnum aux = number;
  string numero = aux.toStr(); 
  int cont0 = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, 
  cont6 = 0, cont7 = 0, cont8 = 0, cont9 = 0;
  for(int i = 0; i < numero.length(); i++){
      if(numero[i] == '1'){
        cont1++;
      }else if(numero[i] == '2'){
        cont2++;
      }else if(numero[i] == '3'){
        cont3++;
      }else if(numero[i] == '4'){
        cont4++;
      }else if(numero[i] == '5'){
        cont5++;
      }else if(numero[i] == '6'){
        cont6++;
      }else if(numero[i] == '7'){
        cont7++;
      }else if(numero[i] == '8'){
        cont8++;
      }else if(numero[i] == '9'){
        cont9++;
      }else{
        cont0++;
      }
  }  
  ofstream arqv;
  arqv.open("contCarac.txt");

  arqv << "Quantidade de números: " <<"\n0: " << cont0 << " \n1: " << cont1 << " \n2: " << cont2 <<" \n3: " << cont3 << " \n4: " << cont4 << " \n5: " << cont5 << " \n6: " << cont6 << " \n7: " << cont7 << " \n8: "<< cont8 << " \n9: "<< cont9;
  arqv.close();
}