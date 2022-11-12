/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 21 Oktober 2022
Topik praktikum : ADT Stack
Deskripsi       : Soal Ekspresi
*/

#include <stdio.h>
#include <math.h>
#include "wordmachine.h"
#include "stack.h"

boolean operand(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int operate(int a, int b, char c){
    switch(c){
        case'+':
            return a+b;break;
        case'-':
            return a-b;break;
        case'*':
            return a*b;break;
        case'/':
            return a/b;break;
        case'^':
            return pow(a,b);break;
        default:
            return -1;break;
    }
}

int integerize(char c){
    return c-48;
}

int main(){
    STARTWORD();
    if(endWord){
        printf("Ekspresi kosong\n");
    }
    else{
        Stack s;int a,b;char c;
        CreateEmpty(&s);
        do{
            if(currentWord.Length==1&&operand(currentWord.TabWord[0])){
                Pop(&s,&b);Pop(&s,&a);
                printf("%d %c %d\n",a,currentWord.TabWord[0],b);
                a=operate(a,b,currentWord.TabWord[0]);
                printf("%d\n",a);
                Push(&s,a);
            }
            else{
                a=0;
                for(b=0;b<currentWord.Length;b++){
                    a*=10;a+=integerize(currentWord.TabWord[b]);
                }
                printf("%d\n",a);
                Push(&s,a);
            }
            ADVWORD();
        }while(!endWord);
        Pop(&s,&a);
        printf("Hasil=%d\n",a);
    }
    return 0;
}