#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
void shellsort(T L[], int n) {
  int i = 0, gap = 0, aux = 0, p = 1;              // c0
  do{                                              // c1 * floor(log2n)
    gap =floor(n/pow(2, p+1))*2+1; p++;            // c2 * floor(log2n)
    for(i = gap; i < n; i++){                      // c3 * E i = 1, floor(log2n) F(n-2*floor(n/2^(i+1)+2))
      int x = L[i], j;                             // c4 * E i = 1, floor(log2n) F(n-2*floor(n/2^(i+1)+1))
      for(j = i; j >= gap && L[j-gap] > x; j-=gap){// c5 * E i = gap, (n-1) F([i/floor(n/2^(i+1)+1)])
        L[j] = L[j-gap];                           // c7 *
      }
      L[j] = x;                                    // c7 * E i = 1, floor(log2n) F(n-2*floor(n/2^(i+1)+1))
    }
  }while(gap != 1);                                
}

int main() {
   int n = 18; 
   int L[] = {2, -1, 11, 8, 6, -6, 32, 21, 5, 7, 12, 13, 14, 0, 24, -10, 4, 3};
   shellsort(L, n);
}