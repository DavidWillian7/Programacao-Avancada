#include "gc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
    clock_t t1, t2;
    int *vetor1,*vetor2;
    int n = 10000;
    //sem coletor de lixo
    t1 = clock();
    vetor1 = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        vetor1[i] = 1; 
    }
    
    free(vetor1);
    t1 = clock() - t1;

     printf("\n Tempo sem coletor: %lf", ((double)t1)/((CLOCKS_PER_SEC/1000)));

   //com coletor

       t2 = clock();
    vetor2 = GC_MALLOC(n*sizeof(int));
    for(int i=0;i<n;i++){
        vetor2[i] = 1; 
    }
    t2 = clock() - t2;

    printf("\n Tempo com coletor: %lf", ((double)t2)/((CLOCKS_PER_SEC/1000)));


}
 
