/*
    NIM				: 13521144
    Nama			: Bintang Dwi Marthen
    Tanggal			: 17 November 2022
    Topik praktikum	: ADT List Rekursif
    Deskripsi		: Soal Reverse
*/

#include "listrec.h"

List inverseList (List l){
    if(isEmpty(l)) return l;
    return konsb(inverseList(tail(l)),head(l));
}

List getKElmt (List l, int k){
    if(isEmpty(l)||k==0) return NULL;
    return concat(newNode(head(l)),getKElmt(tail(l),k-1));
}

List removeKElmt (List l, int k){
    if(k==0) return l;
    if(length(l) <= k) return NULL;
    return removeKElmt(tail(l),k-1);
}

void printAns(List l){
    if(!isEmpty(l)){
        if(isOneElmt(l))printf("%d\n", head(l));
        else printf("%d ", head(l));
        printAns(tail(l));
    }
}

List buildList(List l, int k){
    if(isEmpty(l)) return NULL;
    return concat(inverseList(getKElmt(l,k)),buildList(removeKElmt(l,k),k));
}


int main(){
    List l = NULL;
    int n,k,x;
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d",&x);
        l = konsb(l, x);
    };
    List res = buildList(l, k);
    printAns(res);
    return 0;
}