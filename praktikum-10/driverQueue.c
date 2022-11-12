#include <stdio.h>
#include "queuelinked.h"

int main(){
    Queue q;
    CreateQueue(&q);
    DisplayQueue(q);printf("\n");
    enqueue(&q,1);
    DisplayQueue(q);printf("\n");
    enqueue(&q,2);
    DisplayQueue(q);printf("\n");
    enqueue(&q,3);
    DisplayQueue(q);printf("\n");
    enqueue(&q,4);
    DisplayQueue(q);printf("\n");
    enqueue(&q,5);
    DisplayQueue(q);printf("\n");
    int x;
    dequeue(&q,&x);
    DisplayQueue(q);printf("\n");
    dequeue(&q,&x);
    DisplayQueue(q);printf("\n");
    dequeue(&q,&x);
    DisplayQueue(q);printf("\n");
}