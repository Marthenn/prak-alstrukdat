/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 3 November 2022
Topik praktikum	: ADT Variasi List Linier
Deskripsi		: Soal Pemain Terakhir
*/

#include <stdio.h>
#include "list_circular.h"

void delete(List *l, int idx, int *cur){
	int i=0;Address p,q;
	p=FIRST(*l);
	for(i=1;i<idx;i++){
		p=NEXT(p);
	}
	FIRST(*l) = p;
	deleteFirst(l,cur);
}

int main(){
	int n;scanf("%d",&n);
	int k;scanf("%d",&k);
	List l;
	CreateList(&l);
	int i,cur;
	for(i=0;i<n;i++){
		insertLast(&l,i+1);
	}
	while(!isEmpty(l)){
		delete(&l, k, &cur);
		if(!isEmpty(l)){
			printf("%d\n",cur);
		}
	}
	printf("Pemenang %d\n",cur);
	return 0;
}