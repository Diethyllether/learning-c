#include <stdbool.h>
#include <stdio.h>

float celcius_fahrenheit(float inTemp, bool inverse);
float celcius_kelvin(float inTemp, bool inverse);
float kelvin_fahrenheit(float inTemp, bool inverse);

int main(void) {
  int input;
  float inTemp;
  char tempScale;

  printf("What temperatures are you converting?\n");
  printf("1. Celcius and Fahrenheit\n");
  printf("2. Celcius and Kelvin\n");
  printf("3. Kelvin and Fahrenheit\n");
  printf("0. Quit\n");

  scanf("%d", &input);

  switch (input) {
  case 1:
    printf("Insert temperature and scale:\n");
    scanf("%f", &inTemp);
    scanf("%c", &tempScale);
    printf("Converted temperature is: %.2f",
           celcius_fahrenheit(inTemp, tempScale == 'F'));
    break;
  case 2:
    printf("Insert temperature and scale:\n");
    scanf("%f", &inTemp);
    scanf("%c", &tempScale);
    printf("Converted temperature is: %.2f",
           celcius_kelvin(inTemp, tempScale == 'F'));
    break;
  case 3:
    printf("Insert temperature and scale:\n");
    scanf("%f", &inTemp);
    scanf("%c", &tempScale);
    printf("Converted temperature is: %.2f",
           kelvin_fahrenheit(inTemp, tempScale != 'K'));
    break;
  case 0:
    return 0;
    break;
  default:
    printf("Wrong\n");
    break;
  }

  return 0;
}

float celcius_fahrenheit(float inTemp, bool inverse) {
  return (!inverse) ? (inTemp * (9.0 / 5.0) + 32)
                    : ((inTemp - 32) * (5.0 / 9.0));
}

float celcius_kelvin(float inTemp, bool inverse) {
  return (!inverse) ? (inTemp + 273.15) : (inTemp - 273.15);
}

float kelvin_fahrenheit(float inTemp, bool inverse) {
  return (!inverse) ? celcius_fahrenheit(inTemp - 273.15, false)
                    : celcius_fahrenheit(inTemp, true) - 273.15;
}
