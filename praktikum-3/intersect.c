/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 16 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Soal intersect (soal keempat)
*/

#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l1,l2,l3;
    CreateListStatik(&l1);CreateListStatik(&l2);CreateListStatik(&l3);
    readList(&l1);readList(&l2);
    int i;
    for(i=0;i<listLength(l1);i++){
        if(indexOf(l2,ELMT(l1,i))!=IDX_UNDEF){
            insertLast(&l3,ELMT(l1,i));
        }
    }
    sortList(&l3,true);
    printf("%d\n",listLength(l3));
    printList(l3);printf("\n");
    return 0;
}