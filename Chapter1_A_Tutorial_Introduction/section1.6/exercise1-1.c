// Pretty good stuff I guess, although the double loop could be replaced by
// recursion. Will look into it some time later.
#include <stdio.h>

int main() {
  int list[20];
  for (int i = 0; i < 20; i++) {
    list[i] = 0;
  }
  int c;
  int len = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      if (len != 0) {
        ++list[len];
        len = 0;
      }
    } else {
      ++len;
    }
  }
  int max = 0;
  for (int i = 0; i < 20; i++) {
    if (list[i] > max) {
      max = list[i];
    }
  }
  printf(" ___________________________________________________\n");
  while (max != 0) {
    printf("|");
    for (int i = 0; i < 20; i++) {
      if (list[i] == max) {
        if (i >= 10) {
          printf(" x ");
          --list[i];
        } else {
          printf("x ");
          --list[i];
        }
      } else {
        if (i >= 10) {
          printf("   ");
        } else {
          printf("  ");
        }
      }
    }
    --max;
    printf(" |\n");
  }
  printf("|___________________________________________________|\n");
  printf("|0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19  |\n");
}