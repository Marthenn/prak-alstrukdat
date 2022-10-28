/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 29 September 2022
Topik praktikum	: ADT Mesin Kata
Deskripsi		: longestword.c (soal pertama)
*/

#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

int main(){
	int longest=0;
	STARTWORD();
	while(!endWord){
		if(currentWord.Length>longest){
			longest=currentWord.Length;
		}
		ADVWORD();
	}
	printf("%d\n",longest);
	return 0;
}