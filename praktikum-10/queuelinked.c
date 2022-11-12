/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 6 November 2022
Topik praktikum : Queue dan Stack dengan struktur berkait
Deskripsi       : Implementasi dari queuelinked.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"

Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(Node));
    if(p!=NULL){
        INFO(p)=x;
        NEXT(p)=NULL;
    }
    return p;
}

boolean isEmpty(Queue q){
    return ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL;
}

int length(Queue q){
    int res=0;
    Address p = ADDR_HEAD(q);
    while(p!=NULL){
        res++;
        p=NEXT(p);
    }
    return res;
}

void CreateQueue(Queue *q){
    ADDR_HEAD(*q)=NULL;
    ADDR_TAIL(*q)=NULL;
}

void DisplayQueue(Queue q){
    int i;Address p = ADDR_HEAD(q);
    printf("[");
    for(i=0;i<length(q);i++){
        printf("%d",INFO(p));
        if(i!=length(q)-1){
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

void enqueue(Queue *q, ElType x){
    Address p = newNode(x);
    if(p!=NULL){
        if(!isEmpty(*q)){
            NEXT(ADDR_TAIL(*q))=p;
        } else {
            ADDR_HEAD(*q)=p;
        }
        ADDR_TAIL(*q)=p;
    }
}

void dequeue(Queue *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    *x=INFO(p);
    if(ADDR_HEAD(*q)==ADDR_TAIL(*q)){
        ADDR_TAIL(*q)=NULL;
    }
    ADDR_HEAD(*q)=NEXT(ADDR_HEAD(*q));
    free(p);
}