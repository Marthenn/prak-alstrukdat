/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 8 September 2022
Topik praktikum : ADT Sederhana
Deskripsi       : Program mtime.c
*/

#include <stdio.h>
#include "time.h"

int main(){
    int n,i;scanf("%d",&n);
    TIME awal,akhir;
    CreateTime(&awal,23,59,59);
    CreateTime(&akhir,0,0,0);
    for(i=1;i<=n;i++){
        printf("[%d]\n",i);
        TIME t1,t2;
        BacaTIME(&t1);BacaTIME(&t2);
        //t1 > t2
        if(TGT(t1,t2)){
            if(TGT(t1,akhir)){
                akhir=t1;
            }
            if(TLT(t2,awal)){
                awal=t2;
            }
            printf("%ld\n",Durasi(t2,t1));
        }
        //t2 > t1
        else{
            if(TGT(t2,akhir)){
                akhir=t2;
            }
            if(TLT(t1,awal)){
                awal=t1;
            }
            printf("%ld\n",Durasi(t1,t2));
        }
    }
    TulisTIME(awal);printf("\n");
    TulisTIME(akhir);printf("\n");
    return 0;
}