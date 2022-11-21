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

ElType maxList (List l){
    ElType max = head(l);
    if(isOneElmt(l)) return max;
    ElType temp = maxList(tail(l));
    if(temp>max) return temp;
    return max;
}

ElType minList (List l){
    ElType min = head(l);
    if(isOneElmt(l))return min;
    ElType temp = minList(tail(l));
    if(temp<min)return temp;
    return min;
}

ElType sumList(List l){
    ElType sum=head(l);
    if(isOneElmt(l))return sum;
    return sum+sumList(tail(l));
}

float averageList(List l){
    return sumList(l)/(float) length(l);
}

List inverseList(List l){
    if(isEmpty(l)) return l;
    return konsb(inverseList(tail(l)),head(l));
}

void splitPosNeg(List l, List *l1, List *l2){
    if(isEmpty(l)){
        *l1 = NULL; *l2 = NULL;
    } else if (isOneElmt(l)){
        *l1 = *l2 = NULL;
        if (head(l)>=0) *l1 = konso(*l1,head(l));
        else *l2 = konso(*l2,head(l));
    } else{
        if(head(l)>=0){
            splitPosNeg(tail(l),l1,l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l),l1,l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2){
    if(isEmpty(l)){
        *l1 = NULL; *l2 = NULL;
    } else if (isOneElmt(l)){
        *l1 = *l2 = NULL;
        if(head(l) < x) *l1 = konso(*l1, head(l));
        else *l2 = konso(*l2, head(l));
    } else {
        if(head(l)<x){
            splitOnX(tail(l),x,l1,l2);
            *l1 = konso(*l1, head(l));
        } else{
            splitOnX(tail(l),x,l1,l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

boolean isExist(ElType x, List l){
    if(isEmpty(l)) return false;
    if (head(l)==x) return true;
    return isExist(x,tail(l));
}

boolean isAllExist(List l1, List l2){
    if(isEmpty(l1)) return false;
    if(isOneElmt(l1)) return isExist(head(l1),l2);
    return isExist(head(l1),l2) && isAllExist(tail(l1),l2);
}

List listBeforeX(List l, ElType x){
    if(isEmpty(l)) return l;
    if(head(l)==x) return NULL;
    return konso(listBeforeX(tail(l),x),head(l));
}

List oddEven(List l, boolean odd){
    if(isEmpty(l)) return l;
    if(odd) return konso(oddEven(tail(l),!odd),head(l));
    return oddEven(tail(l),!odd);
}

List takeEvenIndex(List l){
    return oddEven(l,false);
}

List takeOddIndex(List l){
    return oddEven(l,true);
}

boolean isSame(List l1, List l2){
    if(length(l1)!=length(l2)) return false;
    if(isEmpty(l1)) return true;
    return (head(l1)==head(l2) && isSame(tail(l1),tail(l2)));
}

boolean isLess(List l1, List l2){
    if(isEmpty(l1) && isEmpty(l2)) return false;
    if(isEmpty(l1)) return true;
    if(isEmpty(l2)) return false;
    if(head(l1)<head(l2)) return true;
    if(head(l1)>head(l2)) return false;
    return isLess(tail(l1),tail(l2));
}

int compareList(List l1, List l2){
    if(isSame(l1,l2)) return 0;
    if(isLess(l1,l2)) return -1;
    return 1;
}