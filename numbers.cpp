#include <iostream>
#include <stdio.h>

// void getNumbers(int * numbers) {
//   char c;
//   int i = 0;
//   numbers[i] = 0;
//
//   while ((c = getchar()) != '\n') {
//     if ((int)c == 32) {
//       i++;
//       numbers[i] = 0;
//     } else {
//       numbers[i] = (numbers[i] * 10) + (c - '0');
//     }
//   }
// }

int getSum() {
  char c;
  unsigned int sum = 0;
  int current = 0;

  while ((c = getchar()) != EOF) {
    if ((int)c == 32) {
      sum = sum + current;
      current = 0;
    } else {
      current = (current * 10) + (c - '0');
    }
  }

  return sum;
}

int getNumber() {
  char c;
  int value = 0;

  while ((c = getchar()) != ' ' && c != EOF) {
    value = (value * 10) + (c - '0');
  }

  return value;
}

int main ()
{
  int n;
  int d;
  int result = 1;
  unsigned int sum = 0;

  n = getNumber();
  d = getNumber();
  sum = getSum();

  if( d == 1 ) {
    // System jedynkowy

    result = sum;
  } else {
    // Inne systemy

    while( (sum = (sum / d)) > 0 ) {
      result++;
    }
  }

  std::cout << result;
  return 0;
}
