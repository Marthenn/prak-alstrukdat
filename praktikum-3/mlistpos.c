#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);
    printList(l);printf("\n");
    int x;scanf("%d",&x);
    if(indexOf(l,x)==IDX_UNDEF){
        printf("%d tidak ada\n",x);
    }
    else{
        printf("%d\n",indexOf(l,x));
        sortList(&l,true);
        int max = ELMT(l,getLastIdx(l));
        int min = ELMT(l,getFirstIdx(l));
        int mid;
        if (listLength(l)%2){
            mid = ELMT(l,listLength(l)/2);
        }
        else{
            mid = ELMT(l,listLength(l)/2+1);
        }
        if(x==max)printf("maksimum\n");
        if(x==min)printf("minimum\n");
        if(x==mid)printf("median\n");
    }
}