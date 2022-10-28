/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 10 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Implementasi dari File Header liststatik.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
    int i;
    for(i=0;i<CAPACITY;i++){
        ELMT(*l,i) = MARK;
    }
}

int listLength(ListStatik l){
    int res=0;
    while(res<CAPACITY && ELMT(l,res)!=MARK){
        res++;
    }
    return res;
}

IdxType getFirstIdx(ListStatik l){
    if (!isEmpty(l))return IDX_MIN;
    return IDX_UNDEF;
}

IdxType getLastIdx(ListStatik l){
    return listLength(l)-1;
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (IDX_MIN<=i && i<CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i){
    return (0<=i && i<(listLength(l)-1));
}

boolean isEmpty(ListStatik l){
    return ELMT(l,0)==MARK;
}

boolean isFull(ListStatik l){
    return ELMT(l,CAPACITY-1)!=MARK;
}

void readList(ListStatik *l){
    int n,i;
    do{
        scanf("%d",&n);
    }while(n<0 || n>CAPACITY);
    CreateListStatik(l);
    for(i=0;i<n;i++){
        scanf("%d",&ELMT(*l,i));
    }
}

void printList(ListStatik l){
    printf("[");

    int i;
    for(i=0;i<listLength(l);i++){
        printf("%d",ELMT(l,i));
        if(i!=getLastIdx(l))printf(",");
    }

    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    int i;
    ListStatik res;
    CreateListStatik(&res);
    for(i=0;i<listLength(l1);i++){
        ELMT(res,i)=ELMT(l1,i);
        if(plus) ELMT(res,i)+=ELMT(l2,i);
        else ELMT(res,i) -=ELMT(l2,i);
    }
    return res;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    if(listLength(l1)!=listLength(l2)){
        return false;
    }
    int i;
    for(i=0;i<listLength(l1);i++){
        if(ELMT(l1,i)!=ELMT(l2,i)){
            return false;
        }
    }
    return true;
}

int indexOf(ListStatik l, ElType val){
    int i;
    for(i=0;i<listLength(l);i++){
        if(ELMT(l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    int i;
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for(i=1;i<listLength(l);i++){
        if(ELMT(l,i)>*max)*max=ELMT(l,i);
        if(ELMT(l,i)<*min)*min=ELMT(l,i);
    }
}

void insertFirst(ListStatik *l, ElType val){
    insertAt(l,val,0);
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    if(listLength(*l)<CAPACITY){
        int i;
        for(i=idx+1;i<(listLength(*l)+1);i++){
            ELMT(*l,i)=ELMT(*l,i-1);
        }
        ELMT(*l,idx)=val;
    }
}

void insertLast(ListStatik *l, ElType val){
    insertAt(l,val,getLastIdx(*l)+1);
}

void deleteFirst(ListStatik *l, ElType *val){
    deleteAt(l,val,0);
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val=ELMT(*l,idx);
    int i;
    for(int i=idx;i<listLength(*l)-1;i++){
        ELMT(*l,i)=ELMT(*l,i+1);
    }
    ELMT(*l,listLength(*l))=MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    deleteAt(l,val,getLastIdx(*l));
}

void sortList(ListStatik *l, boolean asc){
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