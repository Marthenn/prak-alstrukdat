#include <stdio.h>
#include "queue.h"

int main(){
    Queue q;int x;
    CreateQueue(&q);
    displayQueue(q);
    enqueue(&q,100);
    enqueue(&q,90);
    enqueue(&q,80);
    enqueue(&q,70);
    enqueue(&q,60);
    displayQueue(q);
    dequeue(&q,&x);printf("%d\n",x);
    dequeue(&q,&x);printf("%d\n",x);
    dequeue(&q,&x);printf("%d\n",x);
    enqueue(&q,50);
    enqueue(&q,40);
    enqueue(&q,30);
    displayQueue(q);
    dequeue(&q,&x);displayQueue(q);
    return 0;
}