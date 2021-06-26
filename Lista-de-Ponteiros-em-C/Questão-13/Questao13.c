#include <stdio.h>
#include <stdlib.h>

void ordena(int n, float *vet)
{
    for(int i = 0; i < n-1; i++)
    {
      for( int j = i + 1; j < n; j++)
      {
        if(vet[i] > vet[j])
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
   float *vetor;
   int n;
   scanf("%d", &n);

   vet = malloc(n * sizeof(float));

   for(int i = 0; i < n; i++)
   {
     //recebendo os valores das posicoes do vetor
      scanf("%f", &vetor[i]);
   }
   ordena(n, vetor);
   for(int i = 0; i < n; i++)
   {
     printf("%.2f ", vetor[i]);
   }
  //liberar a memória
   free(vetor);
   return 0;
}
