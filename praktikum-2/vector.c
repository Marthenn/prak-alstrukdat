/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 8 September 2022
Topik praktikum : ADT Sederhana
Deskripsi       : Implementasi dari Header File Vector
*/

#include <stdio.h>
#include "vector.h"

void CreateVector(VECTOR *v, float x, float y){
    AbsisComponent(*v)=x;
    OrdinatComponent(*v)=y;
}

void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>",AbsisComponent(v),OrdinatComponent(v));
}

float Magnitude(VECTOR v){
    return Jarak0(v);
}

VECTOR Add(VECTOR a, VECTOR b){
    VECTOR v;
    CreateVector(&v,AbsisComponent(a)+AbsisComponent(b),OrdinatComponent(a)+OrdinatComponent(b));
    return v;
}

VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR v;
    CreateVector(&v,AbsisComponent(a)-AbsisComponent(b),OrdinatComponent(a)-OrdinatComponent(b));
    return v;
}

float Dot(VECTOR a, VECTOR b){
    return (AbsisComponent(a)*AbsisComponent(b)+OrdinatComponent(a)*OrdinatComponent(b));
}

VECTOR Multiply(VECTOR v, float s){
    VECTOR res;
    CreateVector(&res,AbsisComponent(v)*s,OrdinatComponent(v)*s);
    return res;
}