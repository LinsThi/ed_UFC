#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

template <typename T>
int part(T L[], int p, int q) {
   int j = p-1;
   T pivo = L[q];
   for (int i=p; i < q; i++) {
       if (L[i] < pivo) {     
          j++;
          T x = L[i];
          L[i] = L[j];
          L[j] = x;
       }
   }
   int r = j+1;
   T x = L[r];
   L[r] = L[q];
   L[q] = x;
   return r;
}

template <typename T>
void quicksort(T L[], int p, int q) {
   if (p < q) {
       int r = part(L, p, q);
       quicksort(L, p, r-1);
       quicksort(L, r+1, q);
   }
}

int main() {
   clock_t ti, tf;
   double final = 0;
   int n = 5, cont = 0; 
   int L[] = {2, -1, -6, 5, 12};
   int M[n]; 
   quicksort(L, 0, n-1);
   ofstream arqv;
   arqv.open("file.md");
   do{
      for(int j = 0; j < 300; j++){
         for(int i = 0; i < n; i++){
            M[i] = L[i]; 
         }
         ti = clock();
         quicksort(M, 0, n-1);
         tf = clock();
         final += ((double)(tf - ti)*1000)/CLOCKS_PER_SEC;
      }
      cont++;
      if(cont % 10 == 0){
         arqv << cont << " " << final << endl;
      }
   }while(next_permutation(L, L+n));
   arqv.close();
}