/*
    NIM				: 13521144
    Nama			: Bintang Dwi Marthen
    Tanggal			: 17 November 2022
    Topik praktikum	: ADT List Rekursif
    Deskripsi		: Soal Reverse
*/

#include "listrec.h"

void printAns(List l){
    if(!isEmpty(l)){
        if(isOneElmt(l))printf("%d", head(l));
        else printf("%d ", head(l));
        printAns(tail(l));
    }
}

List getKElmt(List l, int k){
    if(k<=0) return NULL;
    if(isEmpty(l)) return NULL;
    return konsb(getKElmt(tail(l),k-1),head(l));
}

List removeKElmt(List l, int k){
    if(k<=0) return l;
    if(isEmpty(l)) return NULL;
    if(length(l)<=k) return NULL;
    return removeKElmt(tail(l),k-1);
}

List buildList(List l, int k, int cur, List temp){
    if(cur==k){
        return concat(temp, buildList(l,k,0,NULL));
    }
    return buildList(tail(l),k,cur+1,konsb(temp,head(l)));
}

int main(){
    List l = NULL;
    int n,k,x;
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d",&x);
        l = konsb(l, x);
    };
    List res = buildList(l, k, 0, NULL);
    printAns(res);printf("\n");
    return 0;
}