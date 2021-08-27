#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

  int val1=INT_MAX;
  float val2=FLT_MAX;
  double val3=DBL_MAX;
  printf("Maximum possible value of  int=%d\nand size of int = %d\n", val1, sizeof(val1));
  printf("Maximum possible value of float=%f\nand size of float=%d\n", val2, sizeof(val2));
  printf("Maximum possible value of double=%f\nand size of double=%d\n", val3, sizeof(val3));
  return 0;
}
