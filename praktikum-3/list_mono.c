#include <stdio.h>
#include "liststatik.h"

boolean mono_asc(ListStatik l){
    int i;
    for(i=0;i<listLength(l)-1;i++){
        if(ELMT(l,i)>ELMT(l,i+1))return false;
    }
    return true;
}

boolean mono_des(ListStatik l){
    int i;
    for(i=0;i<listLength(l)-1;i++){
        if(ELMT(l,i)<ELMT(l,i+1))return false;
    }
    return true;
}

boolean mono_stat(ListStatik l){
    int i;
    for(i=0;i<listLength(l)-1;i++){
        if(ELMT(l,i)!=ELMT(l,i+1))return false;
    }
    return true;
}

int main(){
    ListStatik l;
    readList(&l);
    if(mono_des(l))printf("Non-ascending Monotonic List\n");
    else if(mono_asc(l))printf("Non-descending Monotonic List\n");
    else if(mono_stat(l)) printf("Static Monotonic List\n");
}