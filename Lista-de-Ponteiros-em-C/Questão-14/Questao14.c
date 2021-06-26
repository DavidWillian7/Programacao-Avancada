#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 //funcao parar comparar os valores dentro do vetor
 int compare (const void * a, const void * b)
{
  //retornando a diferenca entre os valores; menor que 0, igual a 0 ou maior que 0
  return ( *(float*)a - *(float*)b );
}

int main() 
{
   float *vetor;
   int n;
   clock_t t;

   scanf("%d", &n);

  //alocando dinamicamente o vetor
   vet = malloc(n * sizeof(float));

   for(int i = 0; i < n; i++)
   {
      scanf("%f", &vetor[i]);
   }
  
   //chamando a variavel do tempo
   t = clock();
  
   qsort(vetor, n, sizeof(float), compare);
  
   t = clock() - t;//diferenca de clock para resultar no tempo de execucao

   for(int i = 0; i < n; i++)
   {
     printf("%.3f ", vetor[i]);
   }
  
   //liberando o espaco da memoria alocado pelo vetor
   free(vet);
  
   printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

}
