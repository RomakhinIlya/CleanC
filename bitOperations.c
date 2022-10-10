#include <stdio.h>

int main() {
  int num = 0;
  printf("Write a decimal number: ");
  scanf("%d", &num);
  printf("Hexadecimal representation of this number: 0x%x\n", num);
  for (int i = 0; i < 4; ++i) {
    printf("%d byte: 0x%x\n", i + 1, (num >> (i * 8)) & 0x000000ff);
  }
  printf("Change third byte to dd: 0x%x\n", num & 0xff00ffff | 0x00dd0000);

  return 0;
}