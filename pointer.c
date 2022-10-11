#include <stdio.h>

int main() {
  int num = 0;
  char *ptr = (char *)&num;
  char a = 'A';
  char b = 'B';
  char *ptr1 = &a;
  char **ptr2 = &ptr1;
  printf("Write a number: ");
  scanf("%d", &num);
  printf("Hexadecimal representation of this number: 0x%x\n", num);
  ptr += 2;
  *ptr = 0xdd;
  printf("After changing the third byte: 0x%x\n", num);
  (*ptr2)++;
  printf("%c\n", **ptr2);

  return 0;
}