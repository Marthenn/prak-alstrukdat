/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 10 November 2022
Topik praktikum	: Queue dan Stack dengan Struktur Berkait
Deskripsi		: Soal Parser Kurung
*/

#include <stdio.h>
#include "stacklinked.h"
#include "charmachine.h"

int main(){
	Stack s;CreateStack(&s);
	int dump,max=0,nSiku=0,nBulat=0,nTegak=0,nKurawal=0,nSegitiga=0;
	boolean stillValid=true;
	START();
	while(currentChar != MARK){
		if(currentChar=='['){
			push(&s,0);
			DisplayStack(s);printf("\n");
		} else if (currentChar==']'){
			if(!isEmpty(s) && TOP(s)==0){
				pop(&s,&dump);
				nSiku++;
			} else {
				stillValid=false;
			}
			DisplayStack(s);printf("\n");
		} else if (currentChar == '('){
			push(&s,1);
			DisplayStack(s);printf("\n");
		} else if (currentChar == ')'){
			if(!isEmpty(s) && TOP(s)==1){
				pop(&s,&dump);
				nBulat++;
			} else {
				stillValid=false;
			}
			DisplayStack(s);printf("\n");
		} else if (currentChar == '|'){
			if(!isEmpty(s) && TOP(s)==2){
				pop(&s,&dump);
				nTegak++;
			} else {
				push(&s,2);
			}
			DisplayStack(s);printf("\n");
		} else if (currentChar == '{'){
			push(&s,3);
			DisplayStack(s);printf("\n");
		} else if (currentChar == '}'){
			if(!isEmpty(s) && TOP(s)==3){
				pop(&s,&dump);
				nKurawal++;
			} else {
				stillValid=false;
			}
			DisplayStack(s);printf("\n");
		} else if (currentChar == '<'){
			push(&s,4);
			DisplayStack(s);printf("\n");
		} else if (currentChar == '>'){
			if(!isEmpty(s) && TOP(s)==4){
				pop(&s,&dump);
				nSegitiga++;
			} else {
				stillValid=false;
			}
			DisplayStack(s);printf("\n");
		}
		if(max<length(s))max=length(s);
		ADV();
	}
	if(stillValid && isEmpty(s)){
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n",nSiku,nBulat,nTegak,nKurawal,nSegitiga);
		printf("MAX %d\n",max);
	} else {
		printf("kurung tidak valid\n");
	}
	return 0;
}