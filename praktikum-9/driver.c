#include <stdio.h>
#include "list_circular.h"

int main(){
    List l;
    CreateList(&l);
    displayList(l);printf("\n");
    printf("Kosong: %d\n",isEmpty(l));
    insertFirst(&l,5);
    insertFirst(&l,4);
    insertFirst(&l,3);
    insertLast(&l,6);
    insertLast(&l,7);
    displayList(l);printf("\n");
    printf("Kosong: %d\n",isEmpty(l));
    Address p = search(l, 5);
    Address q;
    q->info = 3;
    q->next = p;
    printf("Ada address 5: %d\n",addrSearch(l,p));
    printf("Ada address q: %d\n",addrSearch(l,q));
    int x;
    deleteFirst(&l,&x);
    printf("%d\n",x);
    deleteLast(&l,&x);
    printf("%d\n",x);
    displayList(l);printf("\n");
}