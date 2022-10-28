/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 16 September 2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi       : Soal merge (soal kelima)
*/

#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin l1,l2;
    CreateListDin(&l1,400);CreateListDin(&l2,200);
    readList(&l1);readList(&l2);
    int i;
    for(i=0;i<listLength(l2);i++){
        if(indexOf(l1,ELMT(l2,i))==IDX_UNDEF){
            insertLast(&l1,ELMT(l2,i));
        }
    }
    sort(&l1,true);
    printf("%d\n",listLength(l1));
    printList(l1);printf("\n");
    return 0;
}