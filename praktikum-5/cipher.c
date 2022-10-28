#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

char ciphering(char inp, int shift) {
  int temp = inp;
  temp = temp + shift - 65;
  temp %= 26;
  temp += 65;
  
  char res = temp;
  return res;
}
void display(Word input, int shift) {
  for (int i = 0; i <input.Length; i++) {
    printf("%c",ciphering(input.TabWord[i],shift));
  }
}

int main() {
  startWord();

  int shift = currentWord.Length;
  display(currentWord,shift);
  advWord();
  while (!EndWord) {
    printf(" ");
    display(currentWord, shift);
    advWord();
  }
  printf(".\n");
  return 0;
}