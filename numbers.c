#include <stdio.h>
#include <stdlib.h>

int * getNumbers(int n) {
  int *numbers;
  numbers = malloc(n * sizeof(int));

  char c;
  int i;

  while ((c = getchar()) != '\n')
  {
    if (c != ' ') {
        /* printf("- %d\n", numbers[i] * 10 + c - '0'); */
        numbers[i] = numbers[i] * 10 + c - '0';
    } else {
        i++;
    }
  }
  free(numbers);

  return numbers;
}

int main( )
{

  int * first;
  first = malloc(2 * sizeof(int));
  first = getNumbers(2);

  int n;
  int d;

  n = first[0];
  d = first[1];

  int *  numbers;
  numbers = malloc(n * sizeof(int));

  numbers = getNumbers(n);

  int i;
  for(i=0; i < n; i++) {
    printf("%d", numbers[i]);
  }

  free(numbers);
  free(first);

  return 0;
}
