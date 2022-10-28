#include <stdio.h>
#include "prioqueuetime.h"

int main(){
	PrioQueueTime q;
	infotype x;x.time=8;x.info='3';
	MakeEmpty(&q, 10);
	PrintPrioQueueTime(q);
	printf("--------------\n");
	Enqueue(&q, x);
	PrintPrioQueueTime(q);
	x.time=1;x.info='7';
	Enqueue(&q, x);
	printf("--------------\n");
	PrintPrioQueueTime(q);
	x.time=2;x.info='0';
	Enqueue(&q, x);
	printf("--------------\n");
	PrintPrioQueueTime(q);
	Dequeue(&q, &x);
	printf("x: %c %d\n",x.info,x.time);
	printf("--------------\n");
	PrintPrioQueueTime(q);
	Dequeue(&q, &x);
	printf("x: %c %d\n",x.info,x.time);
	printf("--------------\n");
	PrintPrioQueueTime(q);
	Dequeue(&q, &x);
	printf("x: %c %d\n",x.info,x.time);
	printf("--------------\n");
	PrintPrioQueueTime(q);
	printf("%d\n",NBElmt(q));
}