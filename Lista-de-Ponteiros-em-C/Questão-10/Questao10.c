#include <stdio.h>

int main() 
{
  char x_char[4];
  int x_int[4];
  float x_float[4];
  double  x_double[4];

  for(int i = 0; i < 4; i++)
  {
    printf("char pos %d = %p\n",i, x_char + i);
    printf("int pos %d = %p\n",i, x_int + i);
    printf("float pos %d = %p\n",i, x_float + i);
    printf("double pos %d = %p\n",i, x_double + i);
    printf("\n");
  }

  return 0;
}
