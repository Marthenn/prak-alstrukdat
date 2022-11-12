#include <stdio.h>
#include "listlinier.h"

int main(){
    List l;
    CreateList(&l);
    displayList(l);
    insertFirst(&l,8);
    insertFirst(&l,7);
    insertLast(&l,9);
    displayList(l);
    printf("%d\n",length(l));

    List l2;
    CreateList(&l2);
    insertLast(&l2,1);
    insertLast(&l2,2);
    insertLast(&l2,3);
    List l3 = concat(l,l2);
    displayList(l3);
    insertAt(&l3,10,2);
    displayList(l3);
    int res;
    deleteAt(&l3,2,&res);
    printf("%d\n",res);
    displayList(l3);printf("\n");

    printf("-----------\n");
    printf("max: %d\n",max(l3));
    printf("min: %d\n",min(l3));
    inverseList(&l3);
    displayList(l3);printf("\n");
    splitList(&l,&l2,l3);
    displayList(l);printf("\n");
    displayList(l2);printf("\n");
    copyList(&l,&l2);
    displayList(l);printf("\n");
    displayList(l2);printf("\n");
    deleteAll(&l);displayList(l);printf("\n");
    inverseList(&l);displayList(l);printf("\n");
    return 0;
}