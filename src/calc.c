#include <stdio.h>

int main(void) {
  int choice = -1;
  float a;
  float b;
  float c;

  while (choice != 0) {
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
        c = a/b;
        printf("The result is: %.2f\n", c);
        break;
      default:
        printf("wrong");
        break;
    }
  }
  printf("Goodbye");

  return 0;
}
