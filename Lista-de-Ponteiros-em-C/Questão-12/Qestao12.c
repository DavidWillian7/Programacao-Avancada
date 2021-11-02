#include <stdio.h>

int sub(int a, int b)
{
  return a - b;
}

int main() 
{
  int (*pf)(int,int) = &sub;
  printf("%d\n",pf(3,3));
  return 0;
}
