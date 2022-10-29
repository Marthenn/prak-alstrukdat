/*
NIM				: 13521144
Nama			: Bintang Dwi Marthen
Tanggal			: 22 September 2022
Topik praktikum	: ADT Matrix
Deskripsi		: Soal Kedua, subMatrix
*/

#include <stdio.h>
#include "matrix.h"

Matrix subMatrixa(Matrix m1, IdxType row, IdxType col, int M){
    Matrix m2;createMatrix(M,M,&m2);
    int i,j,rowNow=row,colNow=col;
    for(i=0;i<M;i++){
    	for(j=0;j<M;j++){
    		ELMT(m2,i,j)=ELMT(m1,rowNow,colNow);
    		colNow++;	
    	}
    	rowNow++;colNow=col;
    }
    return m2;
}

int count(Matrix m){
	int res=0;int i,j;
	for(i=0;i<ROW_EFF(m);i++){
		for(j=0;j<COL_EFF(m);j++){
			if(ELMT(m,i,j))res++;
		}
	}
	return res;
}

int main(){
	Matrix m;int N,M;
	scanf("%d %d",&N,&M);
	createMatrix(N,N,&m);
	readMatrix(&m,N,N);
	int subcount = (N-M+1)*(N-M+1);
	int i,j,now=1,maxNow=1,maxCnt=0;
	for(i=0;i<=(N-M);i++){
		for(j=0;j<=(N-M);j++){
			Matrix n = subMatrixa(m,i,j,M);
			if(count(n)>maxCnt){
				maxNow = now;
				maxCnt = count(n);
			}
			now++;
		}
	}
	printf("%d\n",maxNow);
	return 0;
}