#include <stdio.h>

int main(void) {
  char name[50];

  printf("Enter your name: ");
  fgets(name, 50, stdin);
  printf("hello, %s", name);
  
  return 0;
}
