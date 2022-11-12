#include <stdio.h>
#include <math.h>
#include "point.h"

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P)=X;
    Ordinat(*P)=Y;
}

void BacaPOINT (POINT * P){
    float a,b;
    scanf("%f %f",&a,&b);
    CreatePoint(P,a,b);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
    return (!EQ(P1,P2));
}

boolean IsOrigin (POINT P){
    return (Absis(P)==0 && Ordinat(P)==0);
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P)==0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P)==0);
}

int Kuadran (POINT P){
    if (Absis(P)>0 && Ordinat(P)>0){
        return 1;
    }else if (Absis(P)<0 && Ordinat(P)>0){
        return 2;
    }else if (Absis(P)<0 && Ordinat(P)<0){
        return 3;
    }else if (Absis(P)>0 && Ordinat(P)<0){
        return 4;
    }else{
        return 0;
    }
}

POINT NextX (POINT P){
    Absis(P)++;
    return P;
}

POINT NextY (POINT P){
    Ordinat(P)++;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P)+=deltaX;
    Ordinat(P)+=deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (SbX){
        Ordinat(P)*=-1;
    }else{
        Absis(P)*=-1;
    }
    return P;
}

float Jarak0 (POINT P){
    return (sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
    return (sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2))+(Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2))));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P)+=deltaX;
    Ordinat(*P)+=deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P)=0;
}

void GeserKeSbY (POINT *P){
    Absis(*P)=0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX){
        Ordinat(*P)*=-1;
    }else{
        Absis(*P)*=-1;
    }
}

void Putar (POINT *P, float Sudut){
    Sudut *= -acos(-1)/180;
    float x = Absis(*P);
    float y= Ordinat(*P);
    Absis(*P)=x*cos(Sudut)-y*sin(Sudut);
    Ordinat(*P)=x*sin(Sudut)+y*cos(Sudut);
}