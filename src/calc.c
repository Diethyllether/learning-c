#include <stdio.h>

int main(void) {
  while (1) {
    float a,b,c;
    int choice;
    printf("Select an option:\n");
    printf("1. Add\n");
    printf("2. Sub\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("0. Quit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter two numbers to add:\n");
        scanf("%f", &a);
        scanf("%f", &b);
        c = a+b;
        printf("The result is: %.2f\n", c);
        break;
      case 2:
        printf("Enter two numbers to subtract:\n");
        scanf("%f", &a);
        scanf("%f", &b);
        c = a-b;
        printf("The result is: %.2f\n", c);
        break;
      case 3:
        printf("Enter two numbers to multiply:\n");
        scanf("%f", &a);
        scanf("%f", &b);
        c = a*b;
        printf("The result is: %.2f\n", c);
        break;
      case 4:
        printf("Enter two numbers to divide:\n");
        scanf("%f", &a);
        scanf("%f", &b);
        if (b!=0) {
          c=a/b;
          printf("The result is: %.2f\n", c);
        } else {
          printf("Undefined, try another number\n");
        }
        break;
      default:
        printf("wrong");
        break;
    }
  }
  printf("Goodbye");

  return 0;
}
