#include <stdio.h>
#include <stdlib.h>

int main(){

  static char a[100] = "hello";
  printf("%s\n", a);
  return 0;

}
