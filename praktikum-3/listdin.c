/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 12 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Implementasi ADT List Dinamik
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l)=capacity;
    NEFF(*l)=0;
    BUFFER(*l)=(ElType*)malloc(capacity*sizeof(ElType));
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
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
    return NEFF(l)-1;
}

boolean isIdxValid(ListDin l,IdxType i){
    return (i >= 0 && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i >= 0 && i <= NEFF(l));
}

boolean isEmpty(ListDin l){
    return NEFF(l)==0;
}

boolean isFull(ListDin l){
    return NEFF(l)==CAPACITY(l);
}

//15
void readList(ListDin *l){
    int n,i,x;
    do{
        scanf("%d",&n);
    }while(n<0||n>CAPACITY(*l));
    NEFF(*l)=n;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        ELMT(*l,i)=x;
    }
}

//16-..
void printList(ListDin l){
    printf("[");
    if(NEFF(l)!=0){
        printf("%d",ELMT(l,0));
        int i;
        for(i=1;i<NEFF(l);i++)
            printf(",%d",ELMT(l,i));

    }
    printf("]");
}

//25-26
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    int i;
    ListDin l3;
  
    CreateListDin(&l3,NEFF(l1));
    NEFF(l3) = NEFF(l1);

    if (plus) {
        for (i=0;i<NEFF(l3);i++) {
            ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    } else {
        for (i=0;i<NEFF(l3);i++) {
            ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l3;
}

//..-30
boolean isListEqual(ListDin l1, ListDin l2){
    boolean equal;
    int i;

    equal = false;
    if (NEFF(l1) == NEFF(l2)) {
        i=0;
        equal = true;
        while (i<NEFF(l1) && equal) {
            if (ELMT(l1,i) != ELMT(l2,i))
                equal = false;
            else
                i++;
        }
    }
  return equal;
}

//31-36
IdxType indexOf(ListDin l, ElType val){
    IdxType i;
    if(NEFF(l)==0)i=IDX_UNDEF;
    else{
        i=0;
        while(ELMT(l,i)!=val&&i<NEFF(l)){
            i++;
        }
        if(i==NEFF(l))i=IDX_UNDEF;
    }
    return i;
}

//37
void extremeValues(ListDin l, ElType *max, ElType *min){
    *min=ELMT(l,0);
    *max=ELMT(l,0);
    int i;
    for(i=1;i<NEFF(l);i++){
        if(ELMT(l,i)>*max)
        *max=ELMT(l,i);
        if(ELMT(l,i)<*min)
        *min=ELMT(l,i);
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut)=NEFF(lIn);
    int i;
    for(i=0;i<listLength(lIn);i++){
        ELMT(*lOut,i)=ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
    ElType res=0;
    int i;
    for(i=0;i<listLength(l);i++){
        res+=ELMT(l,i);
    }
    return res;
}

int countVal(ListDin l, ElType val){
    int res = 0;
    int i;
    for(i=0;i<listLength(l);i++){
        if(ELMT(l,i)==val)res++;
    }
    return res;
}

void sort(ListDin *l,boolean asc){
    int i,j,idx;
    ElType temp;

    if(NEFF(*l)!=0){
        if(asc){
            for(i=0;i<listLength(*l)-1;i++){
                idx=i;
                for(j=i+1;j<listLength(*l);j++){
                    if(ELMT(*l,j)<ELMT(*l,idx))idx=j;
                }
                temp=ELMT(*l,idx);
                ELMT(*l,idx)=ELMT(*l,i);
                ELMT(*l,i)=temp;
            }
        }
        else{
            for(i=0;i<listLength(*l)-1;i++){
                idx=i;
                for(j=i+1;j<listLength(*l);j++){
                    if(ELMT(*l,j)>ELMT(*l,idx))idx=j;
                }
                temp=ELMT(*l,idx);
                ELMT(*l,idx)=ELMT(*l,i);
                ELMT(*l,i)=temp;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l,NEFF(*l))=val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val){
    *val=ELMT(*l,NEFF(*l)-1);
    NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    ListDin temp;
    CreateListDin(&temp,CAPACITY(*l)+num);
    NEFF(temp)=NEFF(*l);

    int i;
    for(i=0;i<listLength(*l);i++){
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
    for(i=0;i<listLength(*l);i++){
        ELMT(temp,i)=ELMT(*l,i);
    }
    dealocateList(l);
    BUFFER(*l)=BUFFER(temp);
    CAPACITY(*l)=CAPACITY(temp);
    NEFF(*l)=NEFF(temp);
}

void compressList(ListDin *l){
    ListDin temp;
    CreateListDin(&temp,listLength(*l));
    NEFF(temp)=NEFF(*l);

    int i;
    for(i=0;i<listLength(*l);i++){
        ELMT(temp,i)=ELMT(*l,i);
    }
    dealocateList(l);
    BUFFER(*l)=BUFFER(temp);
    CAPACITY(*l)=CAPACITY(temp);
    NEFF(*l)=NEFF(temp);
}