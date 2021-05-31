#include <iostream>
#include <math.h>

using namespace std;

int pegaGap(int n){
  int p = 1, gap = 0;
  for(int i = 1; pow(2, p)-1 < n;gap =pow(2, p)-1, p++);
  return gap;
}
template <typename T>
void printa(T L[], int n){
  for(int i = 0; i < n; i++){
    cout<< L[i] << " ";
  }
  cout << endl;
}

template <typename T>
void shellsort(T L[], int n) {
  int i = 0, gap = 0, aux = 0;
  gap = pegaGap(n);
  do{
    for(i = gap; i < n; i++){
      int x = L[i], j;
      for(j = i; j >= gap && L[j-gap] > x; j-=gap){
        L[j] = L[j-gap];
      }
      L[j] = x;
    }
    if(gap == 1){
      return;
    }
  }while(gap = gap/2);
}

int main(){
  int n = 18; 
  int L[] = {2, -1, 11, 8, 6, -6, 32, 21, 5, 7, 12, 13, 14, 0, 24, -10, 4, 3};
  shellsort(L, n);
}