#include <stdio.h>
#include "listrec.h"

int main(){
    List l=NULL;
    printf("empty: %d\n",isEmpty(l));
    l = konso(l,3);
    displayList(l);
    printf("empty: %d\noneEl: %d\n", isEmpty(l), isOneElmt(l));
    printf("3 : %d\n", isMember(l,3));
    printf("2 : %d\n", isMember(l,2));
    displayList(l);
    printf("\n");
    l = konso(l,1);
    l=konsb(l,4);
    displayList(l);printf("\n");
    List l2 = copy(l);
    l = concat(l,l2);
    displayList(l);
    printf("length:%d\n",length(l));
    return 0;
}