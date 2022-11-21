#include "listrec copy.h"

int main(){
    List l=NULL; char c; int x;
    scanf("%c",&c);
    while(c!='X'){
        switch(c){
            case 'B':
                scanf("%d",&x);
                l = konsb(l,x);
                break;
            case 'F':
                scanf("%d",&x);
                l = konso(l,x);
                break;
            case 'R':
                l = inverseList(l);
                break;
            case 'P':
                scanf("%d",&x);
                l - listBeforeX(l,x);
                break;
            case 'O':
                l = takeOddIndex(l);
                break;
            case 'E':
                l = takeEvenIndex(l);
                break;
        }
        scanf("%c",&c);
    }
    if(isEmpty(l))printf("Semua gugur\n");
    else displayList(l);
    return 0;
}