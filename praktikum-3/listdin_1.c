/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 10 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Implementasi dari File Header listdin.h
*/

#include <stdio.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l)=capacity;
    NEFF(*l)=0;
    BUFFER(*l)= (ElType*)malloc(capacity*sizeof(ElType));
}

void dealocateList(ListDin *l){
    CAPACITY(*l)=0;
    NEFF(*l)=0;
    free(BUFFER(*l));
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return 0;
}

IdxType getLastIdx(ListDin l){
    return listLength(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i){
    return (0<=i && i<CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (0<=i && i<listLength(l));
}

boolean isEmpty(ListDin l){
    return NEFF(l)==0;
}

boolean isFull(ListDin l){
    return NEFF(l)==CAPACITY(l);
}

void readList(ListDin *l){
    int n,i,x;
    do{
        scanf("%d",n);
    }while(n<0 || n>CAPACITY(*l));
    NEFF(*l)=0;
    for(i=0;i<n;i++){
        scanf("%d",x);
        ELMT(*l,i)=x;
    }
}

void printList(ListDin l){
    printf("[");

    int i;
    for(i=0;i<listLength(l);i++){
        printf("%d",ELMT(l,i));
        if(i!=getLastIdx(l))printf(",");
    }

    pritnf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    int i;ListDin res;
    CreateListDin(&res,NEFF(l1));
    NEFF(res) = NEFF(l1);
    for(i=0;i<listLength(res);i++){
        if(plus){
            ELMT(res,i)=ELMT(l1,i)+ELMT(l2,i);
        }
        else{
            ELMT(res,i)=ELMT(l1,i)-ELMT(l2,i);
        }
    }
    return res;
}

boolean isListEqual(ListDin l1, ListDin l2){
    if(listLength(l1)!=listLength(l2))return false;
    int i;
    for(i=0;i<listLength(l1);i++){
        if(ELMT(l1,i)!=ELMT(l2,i))return false;
    }
    return true;
}

IdxType indexOf(ListDin l, ElType val){
    int i;
    for(i=0;i<listLength(l);i++){
        if(ELMT(l,i)==val)return i;
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
    *max=ELMT(l,0);*min=ELMT(l,0);
    int i;
    for(i=1;i<listLength(l);i++){
        if(ELMT(l,i)>*max){
            *max=ELMT(l,i);
        }
        if(ELMT(l,i)<*min){
            *min=ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut)=NEFF(lIn);
    int i;for(i=0;i<listLength(lIn);i++){
        ELMT(*lOut,i)=ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
    int i;ElType res=0;
    for(i=0;i<listLength(l);i++){
        res+=ELMT(l,i);
    }
    return res;
}

int countVal(ListDin l, ElType val){
    int res=0,i;
    for(i=0;i<listLength(l);i++){
        if(ELMT(l,i)==val)res++;
    }
    return res;
}

void sort(ListDin *l, boolean asc){
    int i,j;
    for(i=0;i<(listLength(*l)-2);i++){
        for(j=0;j<(listLength(*l)-i-1);i++){
            if(asc){
                if(ELMT(*l,j)>ELMT(*l,j+1)){
                    ELMT(*l,j)=ELMT(*l,j)^ELMT(*l,j+1);
                    ELMT(*l,j+1)=ELMT(*l,j)^ELMT(*l,j+1);
                    ELMT(*l,j)=ELMT(*l,j)^ELMT(*l,j+1);
                }
            }
            else{
                if(ELMT(*l,j)<ELMT(*l,j+1)){
                    ELMT(*l,j)=ELMT(*l,j)^ELMT(*l,j+1);
                    ELMT(*l,j+1)=ELMT(*l,j)^ELMT(*l,j+1);
                    ELMT(*l,j)=ELMT(*l,j)^ELMT(*l,j+1);
                }
            }
        }
    }  
}

void insertLast(ListDin *l, ElType val){
    if (listLength(*l)<CAPACITY(*l)){
        NEFF(*l)++;
        ELMT(*l,getLastIdx(*l))=val;
    }
}

void deleteLast(ListDin *l, ElType *val){
    *val=ELMT(*l,getLastIdx(*l));
    NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    ListDin temp;
    CreateListDin(&temp,CAPACITY(*l)+num);
    NEFF(temp)=NEFF(*l);

    int i;
    for(i=0;i<listLength(temp);i++){
        ELMT(temp,i)=ELMT(*l,i);
    }
    dealocateList(l);
    BUFFER(*l)=BUFFER(temp);
    CAPACITY(*l)=CAPACITY(temp);
    NEFF(*l)=NEFF(temp);
}

void shrinkList(ListDin *l, int num){
    ListDin temp;
    CreateListDin(&temp,CAPACITY(*l)-num);
    NEFF(temp)=NEFF(*l);
    int i;
    for(i=0;i<NEFF(temp);i++){
        ELMT(temp,i)=ELMT(*l,i);
    }
    dealocateList(l);
    CAPACITY(*l)=CAPACITY(temp);
    BUFFER(*l)=BUFFER(temp);
    NEFF(*l)=NEFF(temp);
}

void compressList(ListDin *l){
    ListDin temp;
    CreateListDin(&temp,NEFF(*l));
    NEFF(temp)=NEFF(*l);

    int i;
    for(i=0;i<NEFF(temp);i++){
        ELMT(temp,i)=ELMT(*l,i);
    }
    dealocateList(l);
    BUFFER(*l)=BUFFER(temp);
    CAPACITY(*l)=CAPACITY(temp);
    NEFF(*l)=NEFF(temp);
}