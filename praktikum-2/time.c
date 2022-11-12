#include <stdio.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S){
    return (0<=H && H<=23 && 0<=M && M<=59 && 0<=S && S<=59);
}

void CreateTime (TIME * T, int HH, int MM, int SS){
    Hour(*T)=HH;
    Minute(*T)=MM;
    Second(*T)=SS;
}

void BacaTIME (TIME * T){
    int a,b,c;
    do{
        scanf("%d %d %d",&a,&b,&c);
        if(!IsTIMEValid(a,b,c)){
            printf("Jam tidak valid\n");
        }
    }while(!IsTIMEValid(a,b,c));
    CreateTime(T,a,b,c);
}

void TulisTIME (TIME T){
    printf("%d:%d:%d",Hour(T),Minute(T),Second(T));
}

long TIMEToDetik (TIME T){
    return (Hour(T)*3600L+Minute(T)*60L+Second(T)*1L);
}

TIME DetikToTIME (long N){
    TIME T;
    N%=86400;
    CreateTime(&T,N/3600,(N%3600)/60,(N%3600)%60);
    return T;
}

boolean TEQ (TIME T1, TIME T2){
    return (TIMEToDetik(T1)==TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return (TIMEToDetik(T1)!=TIMEToDetik(T2));
}

boolean TLT (TIME T1, TIME T2){
    return (TIMEToDetik(T1)<TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2){
    return (TIMEToDetik(T1)>TIMEToDetik(T2));
}

TIME NextDetik (TIME T){
    return NextNDetik(T,1);
}

TIME NextNDetik (TIME T, int N){
    return DetikToTIME(TIMEToDetik(T)+(1L*N));
}

TIME PrevDetik (TIME T){
    return PrevNDetik(T,1);
}

TIME PrevNDetik (TIME T, int N){
    return DetikToTIME(TIMEToDetik(T)-(1L*N)+86400L);
}

long Durasi (TIME TAw, TIME TAkh){
    return ((TIMEToDetik(TAkh)-TIMEToDetik(TAw)+86400)%86400);
}