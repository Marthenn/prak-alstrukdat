#include <stdio.h>
#include "listlinier.h"

void solve(List *l,ElType x, int n){
    Address p=FIRST(*l),q=NULL; ElType y;
    int i=0;
    while(i<n&&INFO(FIRST(p))!=x){
        q = p;
        FIRST(p)=NEXT(p);
        i++;
    }
    if(i==n){
        deleteLast(l,&y);
        printf("miss ");
    } else{
        deleteAt(l,i,&y);
        printf("hit ");
    }
    insertFirst(l,x);
    displayList(*l);printf("\n");
}

int main(){
    int n,nOps;
    ElType x;
    List l;
    scanf("%d",&n);
    CreateList(&l);
    scanf("%d",&nOps);
    int i;
    for(i=0;i<nOps;i++){
        scanf("%d",&x);
        solve(&l,x,n);
    }
    return 0;
}