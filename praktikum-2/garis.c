/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 8 September 2022
Topik praktikum : ADT Sederhana
Deskripsi       : Implementasi dari Header File Garis
*/

#include <stdio.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2){
    PAwal(*L)=P1;
    PAkhir(*L)=P2;
}

void BacaGARIS (GARIS * L){
    POINT p1,p2;
    do{
        BacaPOINT(&p1);BacaPOINT(&p2);
        if(EQ(p1,p2))printf("Garis tidak valid\n");
    }while(EQ(p1,p2));
    CreateGaris(L,p1,p2);
}

void TulisGARIS (GARIS L){
    printf("(");TulisPOINT(PAwal(L));
    printf(",");TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS (GARIS L){
    return Panjang(PAwal(L),PAkhir(L));
}

float Gradien (GARIS L){
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    Geser(&PAkhir(*L),deltaX,deltaY);
    Geser(&PAwal(*L),deltaX,deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2)==-1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1)==Gradien(L2));
}