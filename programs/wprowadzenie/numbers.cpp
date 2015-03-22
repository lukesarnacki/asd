#include <iostream>
#include <stdio.h>

int getNumber() {
  char c;
  unsigned long long int value = 0;

  while ((c = getchar()) != ' ' && c != EOF && c != '\n') {
    value = (value * 10) + (c - '0');
  }

  return value;
}

int main ()
{
  unsigned long int n;
  unsigned long int d;
  unsigned long int result = 0;

  n = getNumber();
  d = getNumber();

  char c;
  unsigned long long int sum = 0;
  unsigned  int current = 0;

  const int SIZE = 1024;
  char buffer[SIZE];
  int size;

  while(true) {
    size = fread(buffer, sizeof(char), SIZE, stdin);

      for(int i = 0; i < size; i++) {
        c = buffer[i];

        if (c == ' ') {
          sum = sum + current;
          current = 0;
        } else {
          current = (current * 10) + (c - '0');
        }
      }

    if(size < SIZE) { sum = sum + current; break; }
  }

  if( d == 1 ) {
    // System jedynkowy

    result = sum;
  } else {
    // Inne systemy
    //
    do {
      result++;
    } while( (sum = (sum / d)) > 0 );
  }

  printf("%lu", result);
  return 0;
}
