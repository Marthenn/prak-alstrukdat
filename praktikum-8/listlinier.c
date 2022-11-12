/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 23 Oktober 2022
Topik praktikum : ADT Linked List
Deskripsi       : Implementasi dari listlinier.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if(p!=NULL){
        INFO(p)=val;
        NEXT(p)=NULL;
    }
    return p;
}

void CreateList(List *l){
    FIRST(*l)=NULL;
}

boolean isEmpty(List l){
    return FIRST(l)==NULL;
}

ElType getElmt(List l, int idx){
    while(idx--){
        FIRST(l)=NEXT(l);
    } return INFO(l);
}

void setElmt(List*l,int idx,ElType val){
    List p=*l;
    while(idx--){
        FIRST(p)=NEXT(p);
    }
    INFO(p)=val;
}

int indexOf(List l, ElType val){
    boolean found=false;int idx=0;
    while(l!=NULL && !found){
        if(INFO(l)==val){
            found=true;
        } else {
            idx++;
            FIRST(l)=NEXT(l);
        }
    }
    if(found) return idx;
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if(p!=NULL){
        NEXT(p)=*l;
        *l=p;
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l,val);
    } else {
        Address p = newNode(val);
        if(p!=NULL){
            Address last = *l;
            while(NEXT(last)!=NULL){
                last = NEXT(last);
            }
            NEXT(last)=p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx==0){
        insertFirst(l,val);
    } else {
        Address p = newNode(val);
        if(p!=NULL){
            int ctr=0;Address loc=*l;
            while(ctr<idx-1){
                ctr++;
                loc=NEXT(loc);
            }
            NEXT(p)=NEXT(loc);
            NEXT(loc)=p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);
    *l=NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
    Address p = *l, loc = NULL;
    while(NEXT(p)!=NULL){
        loc = p;
        p = NEXT(p);
    }
    if(loc==NULL){
        *l=NULL;
    } else {
        NEXT(loc)=NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx==0){
        deleteFirst(l,val);
    } else {
        int ctr=0;Address loc=*l;
        while(ctr<idx-1){
            ctr++;
            loc=NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc)=NEXT(p);
        free(p);
    }
}

void displayList(List l){
    printf("[");
    while(!isEmpty(l)){
        printf("%d",INFO(l));
        if(NEXT(l)!=NULL){
            printf(",");
        }
        l=NEXT(l);
    }
    printf("]");
}

int length(List l){
    int cnt=0;
    while(l!=NULL){
        cnt++;
        l=NEXT(l);
    } return cnt;
}

List concat(List l1, List l2){
    List l3;CreateList(&l3);
    Address p = l1;
    while(p!=NULL){
        insertLast(&l3,INFO(p));
        p=NEXT(p);
    }
    p=l2;
    while(p!=NULL){
        insertLast(&l3,INFO(p));
        p=NEXT(p);
    }
    return l3;
}

boolean fSearch(List L, Address P){
    boolean found = false;
    while(!found && FIRST(L)!=NULL){
        if(FIRST(L)==P){
            found = true;
        } else {
            FIRST(L) = NEXT(L);
        }
    }
    return found;
}

Address searchPrec(List L, ElType X){
    Address prev = NULL;
    while(FIRST(L)!=NULL && INFO(FIRST(L))!=X){
        prev = FIRST(L);
        FIRST(L)=NEXT(L);
    }
    if(FIRST(L)==NULL){
        prev=NULL;
    }
    return prev;
}

ElType max(List l){
    int res = INFO(FIRST(l));
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))>res){
            res=INFO(FIRST(l));
        }
        FIRST(l)=NEXT(l);
    }
    return res;
}

Address adrMax(List l){
    int res = INFO(FIRST(l));
    Address p = FIRST(l);
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))>res){
            res=INFO(FIRST(l));
            p = FIRST(l);
        }
        FIRST(l)=NEXT(l);
    }
    return p;
}

ElType min(List l){
    int res = INFO(FIRST(l));
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))<res){
            res=INFO(FIRST(l));
        }
        FIRST(l)=NEXT(l);
    }
    return res;
}

Address adrMin(List l){
    int res = INFO(FIRST(l));
    Address p = FIRST(l);
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))<res){
            res=INFO(FIRST(l));
            p = FIRST(l);
        }
        FIRST(l)=NEXT(l);
    }
    return p;
}

//aman
void deleteAll(List *l){
    Address p = FIRST(*l),q;
    while(p!=NULL){
        q = p;
        p=NEXT(p);
        free(q);
    }
    FIRST(*l)=NULL;
}

//aman
void copyList(List *l1, List *l2){
    FIRST(*l2)=FIRST(*l1);
}

//aman
void inverseList(List *l){
    Address p=FIRST(*l),q=NULL,r;
    if(p!=NULL){
        do{
            r=q;q=p;p=NEXT(p);
            NEXT(q)=r;
        }while(p!=NULL);
        FIRST(*l)=q;
    }
}


//aman
void splitList(List *l1, List *l2, List l){
    int len=length(l)/2;
    CreateList(l1);CreateList(l2);
    int i;
    for(i=0;i<len;i++){
        insertLast(l1,INFO(FIRST(l)));
        FIRST(l)=NEXT(l);
    }
    while(FIRST(l)!=NULL){
        insertLast(l2,INFO(FIRST(l)));
        FIRST(l)=NEXT(l);
    }
}