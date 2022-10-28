/*
    NIM				: 13521144
    Nama			: Bintang Dwi Marthen
    Tanggal			: 6 Oktober 2022
    Topik praktikum	: ADT Queue
    Deskripsi		: soal pertama, antrianSix
*/

#include <stdio.h>
#include "queue.h"

int main(){
	Queue q;CreateQueue(&q);
    boolean running = true;
    int dilayani=0,minimal=1001,maksimal=-1;float average=0;
    while(running){
        int input,a;scanf("%d",&input);
        if(input==1){
            scanf("%d", &a);
            if(!isFull(q)){
                enqueue(&q,a);
            }
            else{
                printf("Queue penuh\n");
            }
        }
        else if(input==2){
            if(isEmpty(q)){
                printf("Queue kosong\n");
            }
            else{
                dequeue(&q,&a);
                dilayani++;
                average+=a;
                if(minimal>a)minimal=a;
                if(maksimal<a)maksimal=a;
            }
        }
        else{
            running = false;
        }
    }
    printf("%d\n",dilayani);
    if(dilayani==0){
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }
    else{
        printf("%d\n%d\n",minimal,maksimal);
        average/=dilayani;
        printf("%.2f\n",average);
    }
}