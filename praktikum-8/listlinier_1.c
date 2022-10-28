/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 23 Oktober 2022
Topik praktikum : ADT Linked List
Deskripsi       : Implementasi dari listlinier.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier_1.h"

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

ElType maxList(List l){
    ElType res=INFO(FIRST(l));
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))>res){
            res=INFO(FIRST(l));
        }
        FIRST(l)=NEXT(l);
    }
    return res;
}

Address adrMax(List l){
    ElType res=INFO(FIRST(l));
    Address p=FIRST(l);
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))>res){
            res=INFO(FIRST(l));
            p=FIRST(l);
        }
        FIRST(l)=NEXT(l);
    }
    return p;
}

ElType minList(List l){
    ElType res=INFO(FIRST(l));
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))<res){
            res=INFO(FIRST(l));
        }
        FIRST(l)=NEXT(l);
    }
    return res;
}

Address adrMin(List l){
    ElType res=INFO(FIRST(l));
    Address p=FIRST(l);
    while(FIRST(l)!=NULL){
        if(INFO(FIRST(l))<res){
            res=INFO(FIRST(l));
            p=FIRST(l);
        }
        FIRST(l)=NEXT(l);
    }
    return p;
}

float average(List l){
    float sum=0.00f;
    int num=0;
    while(FIRST(l)!=NULL){
        sum+=INFO(FIRST(l));
        num++;
        FIRST(l)=NEXT(l);
    }
    return sum/num;
}

void delAll(List *l){
    Address p=FIRST(*l),q;
    while(FIRST(p)!=NULL){
        q=FIRST(p);
        FIRST(p)=NEXT(p);
        free(q);
    }
    FIRST(*l)=NULL;
}

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

List fInverseList(List l){
    boolean stat = true;
    Address new; List l1;
    CreateList(&l1);
    while(stat&&FIRST(l)!=NULL){
        new=newNode(INFO(FIRST(l)));
        if(new==NULL){
            delAll(&l1);
            stat=false;
        } else {
            NEXT(new)=FIRST(l1);
            FIRST(l1)=new;
        }
        FIRST(l)=NEXT(l);
    }
    return l1;
}

void copyList (List *l1, List *l2){
    FIRST(*l2)=FIRST(*l1);
}

List fCopyList(List l){
    boolean stat = true;
    Address new;List l1,p;
    CreateList(&l1);
    while(stat&&FIRST(l)!=NULL){
        new = newNode(INFO(FIRST(l)));
        if(new==NULL){
            stat=false;
            delAll(&l1);
        } else {
            p = l1;
            if(FIRST(l1)==NULL){
                FIRST(l1)=new;
            } else {
                while(NEXT(p)!=NULL){
                    FIRST(p)=NEXT(p);
                }
                NEXT(p)=new;
            }
        }
        FIRST(l)=NEXT(l);
    }
    return l1;
}

void cpAllocList(List lIn, List *lOut){
    boolean stat = true;
    Address new; List p;
    CreateList(lOut);
    while(stat&&FIRST(lIn)!=NULL){
        new = newNode(INFO(FIRST(lIn)));
        if(new==NULL){
            delAll(lOut);
            *lOut=NULL;
            stat=false;
        } else {
            p = *lOut;
            if(FIRST(*lOut)==NULL){
                FIRST(*lOut)=new;
            } else {
                while(NEXT(p)!=NULL){
                    FIRST(p)=NEXT(p);
                }
                NEXT(p)=new;
            }
        }
        FIRST(lIn)=NEXT(lIn);
    }
}

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