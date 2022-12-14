/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 26 September 2022
Topik praktikum : ADT Mesin Kata
Deskripsi       : Implementasi dari wordmachine.h
*/

#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
   /* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while(currentChar==BLANK)ADV();
}

void STARTWORD()
{ 
   /* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
   START();
   IgnoreBlanks();
   if(currentChar==MARK){
      endWord=true;
   }
   else{
      endWord=false;
      ADVWORD();
   }
}

void ADVWORD()
{  
   /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
   IgnoreBlanks();
   if(currentChar==MARK & !endWord){
      endWord=true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
{
   /* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int i=0;
   while((currentChar!=MARK) && (currentChar!=BLANK) && (i<NMax)){
      currentWord.TabWord[i]=currentChar;
      ADV();
      i++;
   }
   currentWord.Length=i;
}

void LowerCase(){
  int i;
  for(i=0;i<currentWord.Length;i++){
    if(currentWord.TabWord[i]<=90 && currentWord.TabWord[i]>=65){
      currentWord.TabWord[i]+=32;
    }
  }
}