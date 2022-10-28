/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 13 Oktober 2022
Topik praktikum : ADT Queue
Deskripsi       : Soal SJF
*/

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

int main(){
    PrioQueueTime q;infotype x,y;int t, i, now=0,run=0, a; char b;
    scanf("%d",&t);
    infotype *res=(infotype *)malloc(t*sizeof(infotype));
    int cnt=0;
    MakeEmpty(&q, t);
    for(i=0;i<t;i++){
        scanf("%d %c",&a,&b);
        x.time=a;x.info=b;
        Enqueue(&q, x);
        if(run==0){
            Dequeue(&q, &y);
            run+=y.time;
            y.time=now;
            res[cnt++]=y;
        }
        run--;
        now++;
    }
    while(!IsEmpty(q)){
        if(run==0){
            Dequeue(&q, &y);
            run+=y.time;
            y.time=now;
            res[cnt++]=y;
        }
        run--;
        now++;
    }
    for(i=0;i<cnt;i++){
        printf("%d %c\n",res[i].time,res[i].info);
    }
}