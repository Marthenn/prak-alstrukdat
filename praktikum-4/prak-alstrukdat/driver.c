#include <stdio.h>
#include "matrix.h"

int main(){
	Matrix m;createMatrix(4,4,&m);
	readMatrix(&m,4,4);
	RotateMat(&m);
	displayMatrix(m);
}