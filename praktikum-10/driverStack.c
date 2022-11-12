#include <stdio.h>
#include "stacklinked.h"

int main(){
    Stack s;
    CreateStack(&s);
    DisplayStack(s);printf("\n");
    push(&s,1);
    DisplayStack(s);printf("\n");
    push(&s,2);
    DisplayStack(s);printf("\n");
    push(&s,3);
    DisplayStack(s);printf("\n");
    push(&s,4);
    DisplayStack(s);printf("\n");
    push(&s,5);
    DisplayStack(s);printf("\n");
    int x;
    pop(&s,&x);
    DisplayStack(s);printf("\n");
    pop(&s,&x);
    DisplayStack(s);printf("\n");
    pop(&s,&x);
    DisplayStack(s);printf("\n");
}