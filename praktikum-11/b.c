#include <stdio.h>

int main(){
	printf("30000 5\n");
	int i;
	for(i=1;i<=30000;i++){
		if(i!=30000){
			printf("%d ",i);
		} else{
			printf("%d", i);
		}
	}
}