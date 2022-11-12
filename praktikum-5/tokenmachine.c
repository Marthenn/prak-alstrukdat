#include <stdio.h>
#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank(){
    while(currentChar = BLANK){
        adv();
    }
}

void startToken(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endToken=true;
    }
    else{
        endToken=false;
        advToken();
    }
}

void advToken(){
    ignoreBlank();
    if(currentChar==MARK){
        endToken=true;
    }
    else{
        salinToken();
        ignoreBlank();
    }
}

void salinToken(){
    if((currentChar>=48)&&(currentChar<=57)){
        currentToken.tkn = 'b';
        currentToken.val = 0;
        do{
            currentToken.val = (currentToken.val*10)+(currentChar-48);
            adv();
        }while((currentChar>=48)&&(currentChar<=57));
    }
    else{
        currentToken.val = -1;
        currentToken.tkn = currentChar;
        adv();
    }
}