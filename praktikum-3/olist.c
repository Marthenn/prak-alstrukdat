/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 16 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Soal olist (soal ketiga)
*/

#include <stdio.h>
#include "liststatik.h"

int occurence(ListStatik l,int x){
    int i,res=0;
    for(i=0;i<listLength(l);i++){
        if(ELMT(l,i)==x)res++;
    }
    return res;
}

int last(ListStatik l, int x){
    int i;
    for(i=getLastIdx(l);i>=0;i--){
        if(ELMT(l,i)==x)return i;
    }
    return IDX_UNDEF;
}

int main(){
    ListStatik l;CreateListStatik(&l);readList(&l);printList(l);printf("\n");
    int x;scanf("%d",&x);
    printf("%d\n",occurence(l,x));
    if(last(l,x)==IDX_UNDEF){
        printf("%d tidak ada\n",x);
    }
    else{
        printf("%d\n",last(l,x));
        sortList(&l,true);
        if(x==ELMT(l,getLastIdx(l)))printf("maksimum\n");
        if(x==ELMT(l,0))printf("minimum\n");
        if(listLength(l)%2){
            if(x==ELMT(l,listLength(l)/2))printf("median\n");
        }
        else{
            if(x==ELMT(l,listLength(l)/2 -1))printf("median\n");
        }
    }
    return 0;
    // if(x%2){
    //     x/=2;
    // }
    // else{
    //     x/=2;x--;
    // }
    // printf("%d\n",x);
}