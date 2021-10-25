#include <stdio.h>
#include <stdlib.h>
void imprime(int **m,int nl,int nc);
// void aloca_mat(int **m1,int nl, int nc);    
void MultMat(int **m1, int **m2,int **m3, int nl1, int nc2,int n );

int main(){

    int **m1,**m2,**m3;
    int nl1, nc1,nl2, nc2;


  scanf("%d %d %d %d",&nl1,&nc1,&nl2,&nc2);


    
    m1 = malloc(nl1*sizeof(int*));
    m1[0] = malloc(nl1*nc1*sizeof(int));
    
    for(int i=1; i<nl1; i++){
        m1[i] = m1[i-1]+nc1;

    }
  
    m2 = malloc(nl2*sizeof(int*));
     m2[0] = malloc(nl2*nc2*sizeof(int));

     for(int i=1; i<nl2; i++){
         m2[i] = m2[i-1]+nc2;
    }
     m3 = malloc(nl1*sizeof(int*));
      m3[0] = malloc(nl1*nc2*sizeof(int));

     for(int i=1; i<nl1; i++){
       m3[i] = m3[i-1]+nc2;

      }

    
  printf("Entre com a matriz 1:");
  for(int i = 0; i<nl1; i++){
        for(int j =0; j<nc1; j++){
             scanf("%d",&m1[i][j]);
        }
        
    }
    //aloca_mat(m2,nl2,nc2);

    //  m2 = malloc(nl2*sizeof(int*));
    //  m2[0] = malloc(nl2*nc2*sizeof(int));

    //  for(int i=1; i<nl2; i++){
    //      m2[i] = m2[i-1]+nc2;
    // }
     
    printf("Entre com a matriz 2:");
    for(int i = 0; i<nl2; i++){
        for(int j =0; j<nc2; j++){
             scanf("%d",&m2[i][j]);
        }
        
    }

    // //aloca_mat(m3,nl1,nc2);
    //   // m3 = malloc(nl1*sizeof(int*));
    //   // m3[0] = malloc(nl1*nc2*sizeof(int));

    //  for(int i=1; i<nl1; i++){
    //    m3[i] = m3[i-1]+nc2;

    //   }

    imprime(m1,nl1,nc1);
    imprime(m2,nl2,nc2);
    
    MultMat(m1,m2,m3,nl1,nc2,nl2);
    
    imprime(m3,nl1,nc2);;

    free(m3);
    free(m2);
    free(m1);

    }




// void aloca_mat(int **m,int nl, int nc){
//     m = malloc(nl*sizeof(int*));
//     m[0] = malloc(nl*nc*sizeof(int));

//     for(int i=1; i<nl; i++){
//         m[i] = m[i-1]+nc;
//    }
// }

void imprime(int **m,int nl, int nc){
   for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
}

void MultMat(int **m1, int **m2,int **m3, int nl1, int nc2,int n ){
    int i, j, k;
    for(i = 0; i < nl1; i++){
        for(j = 0; j < nc2; j++){
            m3[i][j] = 0;
            for(k = 0; k<n; k++){
                m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }

}
