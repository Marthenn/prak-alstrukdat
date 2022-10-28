#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordmachine.h"

boolean elemenAngka(char s[]){
	if(strcmp(s,"nol")==0){
		return true;
	}
	else if(strcmp(s,"satu")==0){
		return true;
	}
	else if(strcmp(s,"dua")==0){
		return true;
	}
	else if(strcmp(s,"tiga")==0){
		return true;
	}
	else if(strcmp(s,"empat")==0){
		return true;
	}
	else if(strcmp(s,"lima")==0){
		return true;
	}
	else if(strcmp(s,"enam")==0){
		return true;
	}
	else if(strcmp(s,"tujuh")==0){
		return true;
	}
	else if(strcmp(s,"delapan")==0){
		return true;
	}
	else if(strcmp(s,"sembilan")==0){
		return true;
	}
	else if(strcmp(s,"seratus")==0){
		return true;
	}
	else if(strcmp(s,"sebelas")==0){
		return true;
	}
	else if(strcmp(s,"sepuluh")==0){
		return true;
	}
	else if(strcmp(s,"belas")==0){
		return true;
	}
	else if(strcmp(s,"ratus")==0){
		return true;
	}
	else if(strcmp(s,"puluh")==0){
		return true;
	}
	return false;
}

int convertion(int currentNum,char s[]){
	if(strcmp(s,"nol")==0){
		currentNum+=0;
	}
	else if(strcmp(s,"satu")==0){
		currentNum+=1;
	}
	else if(strcmp(s,"dua")==0){
		currentNum+=2;
	}
	else if(strcmp(s,"tiga")==0){
		currentNum+=3;
	}
	else if(strcmp(s,"empat")==0){
		currentNum+=4;
	}
	else if(strcmp(s,"lima")==0){
		currentNum+=5;
	}
	else if(strcmp(s,"enam")==0){
		currentNum+=6;
	}
	else if(strcmp(s,"tujuh")==0){
		currentNum+=7;
	}
	else if(strcmp(s,"delapan")==0){
		currentNum+=8;
	}
	else if(strcmp(s,"sembilan")==0){
		currentNum+=9;
	}
	else if(strcmp(s,"seratus")==0){
		currentNum+=100;
	}
	else if(strcmp(s,"sebelas")==0){
		currentNum+=11;
	}
	else if(strcmp(s,"sepuluh")==0){
		currentNum+=10;
	}
	else if(strcmp(s,"belas")==0){
		currentNum+=10;
	}
	else if(strcmp(s,"ratus")==0){
		currentNum*=100;
	}
	else if(strcmp(s,"puluh")==0){
		currentNum*=10;
		if(currentNum>999){
			int temp=currentNum%100;
			currentNum/=100;currentNum*=10;currentNum+=temp;
		}
	}
	return currentNum;
}

int main(){
	boolean angka=false,prevangka=false, awal=true;
	int res=0;
	int i;
	char a[]="Bandung";
	char b[]="Bondowoso";
	char c[]="membuat";
	char d[]="sembilan";
	char e[]="ratus";
	char f[]="sembilan";
	char g[]="puluh";
	char h[]="sembilan";
	char i[]="candi";
	return 0;
}