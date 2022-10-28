#include <stdio.h>
#include "wordmachine.h"
#include "boolean.h"

Word currentWord;
boolean EndWord;

boolean strcmp(char* str, const char* str2, int len);
boolean tonum(char* str, int len, int* buffer);

int main(){
    STARTWORD();
    boolean isNumber;
    int buffer = 0;
    while (!EndWord) {
        /************************************************************/
        isNumber = tonum(currentWord.TabWord,currentWord.Length,&buffer);

        if(!isNumber) {
            int i;
            for(i=0;i<currentWord.Length;i++){
                printf("%c",currentWord.TabWord[i]);
            }
        }

        ADVWORD();
        if(!EndWord && !isNumber){
            printf(" ",0);
        }
    }
    if(buffer!=0){
        printf("%d",buffer);
    }
    printf("\n",0);
}

boolean strcmp(char* str, const char* str2, int len) {
    int len2=0;
    while(str2[len2]!='\0'){
        len2++;
    }
    boolean gas=len==len2;
    int i = 0;
    while(gas && i<len2){
        gas=str[i]==str2[i]; 
        i++;
    }
    return gas;
}

boolean tonum(char* str, int len, int* buffer) {
    if(strcmp(str,"satu",len)){
        *buffer+=1;
        return true;
    } else if (strcmp(str,"nol",len)){
        *buffer=0;
        printf("%d ",*buffer);
        return true;
    } else if (strcmp(str,"dua",len)){
        *buffer+=2;
        return true;
    } else if (strcmp(str,"tiga",len)){
        *buffer+=3;
        return true;
    } else if (strcmp(str,"empat",len)){
        *buffer+=4;
        return true;
    } else if (strcmp(str,"lima",len)){
        *buffer+=5;
        return true;
    } else if (strcmp(str,"enam",len)){
        *buffer+=6;
        return true;
    } else if (strcmp(str,"tujuh",len)){
        *buffer+=7;
        return true;
    } else if (strcmp(str,"delapan",len)){
        *buffer+=8;
        return true;
    } else if (strcmp(str,"sembilan",len)){
        *buffer+=9;
        return true;
    } else if (strcmp(str,"sepuluh",len)){
        *buffer+=10;
        return true;
    } else if (strcmp(str,"seratus",len)){
        *buffer+=100;
        return true;
    } else if (strcmp(str,"sebelas",len)){
        *buffer+=11;
        return true;
    } else if (strcmp(str,"belas",len)){
        *buffer+=10;
        return true;
    } else if (strcmp(str,"puluh",len)){
        *buffer+=((*buffer%10)*10)-(*buffer%10);
        return true;
    } else if (strcmp(str,"ratus",len)){
        *buffer+=(*buffer*100)-*buffer;
        return true;
    } else {
        if(*buffer!=0){
            printf("%d ",*buffer);
            *buffer=0;
        }    
        return false;
    }
}