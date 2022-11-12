#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin l;
    int cap;scanf("%d",&cap);
    CreateListDin(&l,cap);
    readList(&l);
    scanf("%d",&cap);while(cap--){
        int x,op;
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d",&x);
                if(isFull(l))printf("List sudah penuh\n");
                else{
                    insertLast(&l,x);
                    printf("%d ",CAPACITY(l));
                    printList(l);printf("\n");
                }
                break;
            case 2:
                scanf("%d",&x);
                expandList(&l,x);
                printf("%d ",CAPACITY(l));
                printList(l);printf("\n");
                break;
            case 3:
                scanf("%d",&x);
                if(listLength(l)<x)printf("list terlalu kecil\n");
                else{
                    shrinkList(&l,x);
                    printf("%d ",CAPACITY(l));
                    printList(l);printf("\n");
                }
                break;
            case 4:
                compressList(&l);
                printf("%d ",CAPACITY(l));
                printList(l);printf("\n");
        }
    }
    return 0;
}