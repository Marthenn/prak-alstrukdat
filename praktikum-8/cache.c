/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 27 Oktober 2022
Topik praktikum	: ADT Linked List
Deskripsi		: Soal Cache
*/

#include <stdio.h>
#include "listlinier.h"

boolean found(List l, int x){
	Address p=FIRST(l);
	while(p!=NULL){
		if(INFO(p)==x){
			return true;
		}
		p=NEXT(p);
	}
	return false;
}

int main(){
	int n,nOps,x,y,idx;scanf("%d",&n);scanf("%d",&nOps);
	int nHit=0,nMiss=0;
	List l;CreateList(&l);
	while(nOps--){
		scanf("%d",&x);
		if(n>0){
			if(found(l,x)){
				int idx=indexOf(l,x);
				deleteAt(&l,idx,&y);
				printf("hit ");
				nHit++;
			} else {
				if(length(l)==n){
					deleteLast(&l,&y);
				}
				printf("miss ");
				nMiss++;
			}
			insertFirst(&l,x);displayList(l);printf("\n");
		} else {
			printf("miss ");displayList(l);printf("\n");nMiss++;
		}
	}
	if(nHit+nMiss==0){
		nMiss=1;
	}
	printf("hit ratio: %.2f\n",((float)nHit/(float)(nMiss+nHit)));
	return 0;
}