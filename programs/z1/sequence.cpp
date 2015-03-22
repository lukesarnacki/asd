#include <stdio.h>
#include <stdlib.h>

inline void calculate(char & c, unsigned int & current, unsigned int & latest, unsigned int & length, unsigned int & ascLength, unsigned int & descLength, unsigned long long int & sum, unsigned long long int & ascSum, unsigned long long int & descSum)
{
  if (c == ' ') {

    if(current >= latest) {
      ascSum = ascSum + current;
      ascLength++;
    }

    if(current <= latest) {
      descSum = descSum + current;
      descLength++;
    }

    if(current > latest) {
      descLength = 1;
      descSum = current;
    }

    if(current < latest) {
      ascLength = 1;
      ascSum = current;
    }

    if(descLength > length){
      length = descLength;
      sum = descSum;
    }

    if(ascLength > length){
      length = ascLength;
      sum = ascSum;
    }

    latest = current;
    current = 0;
  } else {
    current = ((current << 3) + (current << 1)) + (c - '0');
  }
}


int main ()
{
  unsigned long long int sum = 0;
  unsigned int length = 0;

  unsigned long long int ascSum = 0;
  unsigned int ascLength = 0;

  unsigned long long int descSum = 0;
  unsigned int descLength = 0;

  char c;

  unsigned int current = 0;
  unsigned int latest = 0;

  const int SIZE = 1024;
  char buffer[SIZE];

  int i, size;

  do {
    size = fread(buffer, sizeof(char), SIZE, stdin);

    if (size == 0) {
      c = ' ';
      calculate(c, current, latest, length, ascLength, descLength, sum, ascSum, descSum);
    }

    for(i = 0; i < size; i++) {
      c = buffer[i];
      calculate(c, current, latest, length, ascLength, descLength, sum, ascSum, descSum);
    }
  } while (size > 0);

  printf("%u %llu", length, sum);
  return 0;
}
