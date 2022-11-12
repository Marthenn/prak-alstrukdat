/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 12 November 2022
Topik Praktikum : ADT List Rekursif
Deskripsi       : Implementasi ADT List Rekursif
*/

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(Node));
    if(p!=NULL){
        INFO(p)=x;
        NEXT(p)=NULL;
    }
    return p;
}

boolean isEmpty(List l){
    return l==NULL;    
}

boolean isOneElmt(List l){
    return isEmpty(l) ? false : isEmpty(NEXT(l));
}

ElType head(List l){
    return INFO(l);
}

List tail(List l){
    return NEXT(l);
}

List konso(List l, ElType e){
    Address new = newNode(e);
    if(new!=NULL){
        NEXT(new) = l;
        return new;
    }
    return l;
}

List konsb(List l, ElType e){
    return isEmpty(l) ? konso(l, e) : konso(konsb(tail(l), e), head(l));
}

List copy(List l){
    if(isEmpty(l)) return NULL;
    return konso(copy(tail(l)),head(l));
}

List concat(List l1, List l2){
    return isEmpty(l1) ? copy(l2) : konso(concat(tail(l1),l2),head(l1));
}

int length(List l){
    return isEmpty(l) ? 0 : 1+length(tail(l));
}

boolean isMember(List l, ElType x){
    return isEmpty(l) ? false : (INFO(l)==x || isMember(tail(l),x));
}

void displayList(List l){
    if(!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}