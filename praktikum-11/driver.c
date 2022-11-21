#include <stdio.h>
#include "listrec.h"

int main(){
    List l=NULL;
    printf("empty: %d\n",isEmpty(l));
    l = konso(l,3);
    displayList(l);
    printf("empty: %d\noneEl: %d\n", isEmpty(l), isOneElmt(l));
    printf("3 : %d\n", isMember(l,3));
    printf("2 : %d\n", isMember(l,2));
    displayList(l);
    printf("\n");
    l = konso(l,1);
    l=konsb(l,4);
    displayList(l);printf("\n");
    List l2 = copy(l);
    l = concat(l,l2);
    displayList(l);
    printf("length:%d\n",length(l));
    printf("==================\n");
    printf("max: %d\n", maxList(l));
    printf("min: %d\n", minList(l));
    printf("sum: %d\n", sumList(l));
    printf("avg: %f\n", averageList(l));
    printf("==================\n");
    List lRev = inverseList(l);
    printf("l:\n");displayList(l);
    printf("lRev:\n");displayList(lRev);
    printf("==================\n");
    List lBaru = NULL;
    lBaru = konso(lBaru,-5);
    lBaru = konso(lBaru,-4);
    lBaru = konso(lBaru,-3);
    lBaru = konso(lBaru,-2);
    lBaru = konso(lBaru,-1);
    lBaru = konso(lBaru,0);
    lBaru = konso(lBaru,1);
    lBaru = konso(lBaru,2);
    lBaru = konso(lBaru,3);
    lBaru = konso(lBaru,4);
    lBaru = konso(lBaru,5);
    printf("lBaru:\n");displayList(lBaru);
    List lPos = NULL;List lNeg = NULL;splitPosNeg(lBaru, &lPos, &lNeg);
    printf("lPos:\n");displayList(lPos);
    printf("lNeg:\n");displayList(lNeg);
    List lBef3 = NULL; List lAfter3 = NULL;splitOnX(lBaru, 3, &lBef3, &lAfter3);
    printf("lBef3:\n");displayList(lBef3);
    printf("lAfter3:\n");displayList(lAfter3);
    printf("===============\n");
    printf("Compare: %d\n", compareList(l,lRev));
    printf("Compare: %d\n", compareList(lRev,l));
    printf("AllExist: %d\n", isAllExist(lRev, l));
    printf("AllExist: %d\n", isAllExist(lBaru, lRev));
    return 0;
}