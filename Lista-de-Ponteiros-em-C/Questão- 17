#include <stdio.h>
#include <stdlib.h>

void soma_vetores(int *v1,int *v2, int *v3, int n);
void imprime(int *vetor, int n);
int main(){

int n;
int *lista;
int *lista2; 
int *lista3; 

   //Entrada dados
    printf("Entre com n:\n ");
    scanf("%d",&n);
    //Alocação de memória
    lista = malloc(n*sizeof(int));
    lista2 = malloc(n*sizeof(int));
    lista3 = malloc(n*sizeof(int));
    //Inserindo dados no Array

    printf("Lista 1:");
    for(int i=0; i<n; i++){
      scanf("%d",&lista[i]);
    }
    printf("Lista 2:");
    for(int i=0; i<n; i++){
      scanf("%d",&lista2[i]);
    }
 
    soma_vetores(lista,lista2,lista3,n);
    
    imprime(lista3,n);
    
    
    free(lista3);
    free(lista2);
    free(lista);
    


   


}

void soma_vetores(int *v1,int *v2, int *v3, int n){



for(int i=0; i<n; i++){
      
  v3[i] = v2[i] + v1[i];

  }

}



void imprime(int *vetor, int n){
    for(int i=0; i<n; i++){
      printf("%d ",vetor[i]);
    }
}   
