/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 10 November 2022
Topik praktikum	: Queue dan Stack dengan Struktur Berkait
Deskripsi		: Soal 
*/

#include <stdio.h>
#include "charmachine.h"
#include "queuelinked.h"

boolean isElement(Queue q, int x){
	int i;Address p =ADDR_HEAD(q);
	for(i=0;i<length(q);i++){
		if(INFO(p)==x)return true;
		p=NEXT(p);
	}
	return false;
}

int main(){
	Queue q,qNum,sand;CreateQueue(&q);CreateQueue(&qNum);CreateQueue(&sand);int mk=0,mb=0,num=1,dump, now,nb=0,nk=0;
	START();
	while(currentChar!=','){
		if(currentChar=='B'){
			enqueue(&q,0);mb++;
		} else if(currentChar=='K'){
			enqueue(&q,1);mk--;
		}
		enqueue(&qNum,num);num++;
		ADV();
	}
	ADV();
	while(currentChar!=MARK){
		if(currentChar=='B'){
			enqueue(&sand,0);nb++;
		}
		else if(currentChar=='K'){
			enqueue(&sand,1);nk++;
		}
		ADV();
	}
	while(!isEmpty(q)){
		//printf("q:%d\nqNum:%d\n,sand:%d\n",HEAD(q),HEAD(qNum),HEAD(sand));
		if(HEAD(q)==HEAD(sand)){
			dequeue(&q,&num);
			dequeue(&qNum,&now);
			dequeue(&sand,&dump);
			if(num==0){
				printf("%d -> bulat\n",now);
				nb--;mb--;
			} else{
				printf("%d -> kotak\n",now);
				nk--;mk--;
			}
		} else if(isElement(q,HEAD(sand))){
			dequeue(&q,&now);enqueue(&q,now);
			dequeue(&qNum,&num);enqueue(&qNum,num);
		} else{
			dequeue(&q,&dump);
			dequeue(&qNum,&dump);
		}
		// else{
		// 	dequeue(&q,&num);
		// 	dequeue(&qNum,&now);
		// 	if(num==0){
		// 		if(nb>0){
		// 			enqueue(&q,num);enqueue(&qNum,now);
		// 		}
		// 	} else if(num==1){
		// 		if(nk>0){
		// 			enqueue(&q,num);enqueue(&qNum,now);
		// 		}
		// 	}
		// }
	}
	printf("%d\n",length(sand));
	return 0;
}