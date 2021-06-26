#include <stdio.h>

int soma(int a, int b)
{
  return a+b;
}

int main() 
{
  int (*pf)(int,int) = &soma;
  printf("%d\n",pf(3,3));
  return 0;
}
