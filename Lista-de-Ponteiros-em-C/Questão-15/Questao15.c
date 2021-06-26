#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//disponivel no cplusplus
int compare( float a, float b)
{
  return(a-b);
}

void ordenar(int n, float *vet, int (*compare)(float, float))
{
    for(int i = 0; i < n-1; i++)
    {
      for( int j = i + 1; j < n; j++)
      {
        if(compare(vet[i], vet[j]) > 0) 
        {
          float a = vet[i];
          vet[i] = vet[j];
          vet[j] = a;
        }
      }
    }
}

int main() 
{
   float *vet;
   int n;
   clock_t t;

   scanf("%d", &n);

   vet = malloc(n * sizeof(float));

   for(int i = 0; i < n; i++)
   {
      scanf("%f", &vet[i]);
   }
  
   t = clock();
  
   ordenar(n, vet, compare);
  
   t = clock() - t;
  
   for(int i = 0; i < n; i++)
   {
     printf("%.2f ", vet[i]);
   }
  
  free(vet);
  
  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
  return 0;
}
