/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 22 September 2022
Topik praktikum : ADT Matrix
Deskripsi       : Soal Pertama, Ekspansi dari Matrix.c
*/

#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m)=nRows;COL_EFF(*m)=nCols;
}

boolean isMatrixIdxValid(int i,int j){
    return (0<=i&&i<ROW_CAP&&0<=j&&j<COL_CAP);
}

IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (0<=i&&i<ROW_EFF(m)&&0<=j&&j<COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m,i,i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
   *mOut=mIn;
}

//23
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow, nCol, m);
    int i,j;
    for (i=0;i<nRow;i++) {
        for (j=0;j<nCol;j++) {
        scanf("%d",&ELMT(*m,i,j));
        }
    }
}

//24
void displayMatrix(Matrix m) {
  int i,j;
  for (i=0;i<ROW_EFF(m);i++) {
    printf("%d",ELMT(m,i,0));
    for (j=1;j<COL_EFF(m);j++) {
      printf(" %d",ELMT(m,i,j));
    }
    printf("\n"); 
  }
}

//25-27
Matrix addMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0;i<ROW_EFF(m1);i++){
        for(j=0;j<COL_EFF(m1);j++){
            ELMT(m1,i,j)+=ELMT(m2,i,j);
        }
    }
    return m1;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0;i<ROW_EFF(m1);i++){
        for(j=0;j<COL_EFF(m1);j++){
            ELMT(m1,i,j)-=ELMT(m2,i,j);
        }
    }
    return m1;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3;createMatrix(ROW_EFF(m1),COL_EFF(m2),&m3);
    int i,j,k;
    for(i=0;i<ROW_EFF(m1);i++){
        for(j=0;j<COL_EFF(m2);j++){
            ELMT(m3,i,j)=0;
            for(k=0;k<COL_EFF(m1);k++){
                ELMT(m3,i,j)+=ELMT(m1,i,k)*ELMT(m2,k,j);
            }
        }
    }
    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x){
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            ELMT(m,i,j)*=x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k){
    int i,j;
    for(i=0;i<ROW_EFF(*m);i++){
        for(j=0;j<COL_EFF(*m);j++){
            ELMT(*m,i,j)*=k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    if(isMatrixSizeEqual(m1,m2)){
        int i,j;
        for(i=0;i<ROW_EFF(m1);i++){
            for(j=0;j<COL_EFF(m2);j++){
                if(ELMT(m1,i,j)!=ELMT(m2,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !isMatrixEqual(m1,m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1)==ROW_EFF(m2) && COL_EFF(m1)==COL_EFF(m2));
}

int countElmt (Matrix m){
    return ROW_EFF(m)*COL_EFF(m);
}

boolean isSquare(Matrix m){
    return ROW_EFF(m)==COL_EFF(m);
}

boolean isSymmetric(Matrix m){
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            if(ELMT(m,i,j)!=ELMT(m,j,i)){
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m){
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            if(i==j){
                if(ELMT(m,i,j)!=1){
                    return false;
                }
            }
            else{
                if(ELMT(m,i,j)!=0){
                    return false;
                }
            }
        }
    }
    return true;
}

boolean isSparse (Matrix m){
    float count=0.0f;
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            if(ELMT(m,i,j)!=0){
                count+=1.0f;
            }
        }
    }
    if(count/(float) countElmt(m) <=0.05f){
        return true;
    }
    return false;
}

Matrix negation(Matrix m){
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            ELMT(m,i,j)*=-1;
        }
    }
    return m;
}

void pNegation(Matrix *m){
    int i,j;
    for(i=0;i<ROW_EFF(*m);i++){
        for(j=0;j<COL_EFF(*m);j++){
            ELMT(*m,i,j)*=-1;
        }
    }
}

Matrix transpose(Matrix m){
    int i,j;Matrix res;createMatrix(ROW_EFF(m),COL_EFF(m),&res);
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            ELMT(res,i,j)=ELMT(m,j,i);
        }
    }
    return res;
}

void pTranspose(Matrix *m){
    int i,j;Matrix m1;copyMatrix(*m,&m1);
    for(i=0;i<ROW_EFF(*m);i++){
        for(j=0;j<COL_EFF(*m);j++){
            ELMT(*m,i,j)=ELMT(m1,j,i);
        }
    }
}

Matrix subMatrix(Matrix m1, IdxType row, IdxType col){
    Matrix m2;createMatrix(ROW_EFF(m1)-1,COL_EFF(m1)-1,&m2);
    int i,j;int rowNow=0, colNow=0;
    for(i=0;i<ROW_EFF(m1);i++){
        for(j=0;j<COL_EFF(m1);j++){
            if(i!=row&&j!=col){
                ELMT(m2,rowNow,colNow)=ELMT(m1,i,j);
                colNow++;
                if(colNow==COL_EFF(m2)){
                    colNow=0;rowNow++;
                }
            }
        }
    }
    return m2;
}

float determinant(Matrix m){
    if(ROW_EFF(m)==1){
        return ELMT(m,0,0);
    }
    float res=0.0;
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        if(i%2){
            res-=ELMT(m,i,0)*determinant(subMatrix(m,i,0));
        }
        else{
            res+=ELMT(m,i,0)*determinant(subMatrix(m,i,0));
        }
    }
    return res;
}

float AvgRow(Matrix m, IdxType i){
	float res=0.0f;
	int k;
	for(k=0;k<ROW_EFF(m);k++){
		res+=(float) ELMT(m,i,k);
	}
	return res/(float) ROW_EFF(m);
}

float AvgCol(Matrix m,IdxType j){
	float res=0.0f;
	int k;
	for(k=0;k<COL_EFF(m);k++){
		res+=(float) ELMT(m,k,j);
	}
	return res/(float) COL_EFF(m);
}

void MinMaxRow(Matrix m, IdxType i, ElType* max, ElType* min){
	*max = ELMT(m,i,0);
	*min = ELMT(m,i,0);
	int k;
	for(k=1;k<ROW_EFF(m);k++){
		if(ELMT(m,i,k)>*max)*max=ELMT(m,i,k);
		if(ELMT(m,i,k)<*min)*min=ELMT(m,i,k);
	}
}

void MinMaxCol(Matrix m, IdxType j, ElType* max, ElType* min){
	*max = ELMT(m,0,j);
	*min = ELMT(m,0,j);
	int k;
	for(k=1;k<COL_EFF(m);k++){
		if(ELMT(m,k,j)>*max)*max=ELMT(m,k,j);
		if(ELMT(m,k,j)<*min)*min=ELMT(m,k,j);
	}
}

int CountNumRow(Matrix m, IdxType i, ElType x){
	int res=0;int k;
	for(k=0;k<ROW_EFF(m);k++){
		if(ELMT(m,i,k)==x)res++;
	}
	return res;
}

int CountNumCol(Matrix m, IdxType j, ElType x){
	int res=0;int k;
	for(k=0;k<COL_EFF(m);k++){
		if(ELMT(m,k,j)==x)res++;
	}
	return res;
}

void RotateMat(Matrix *m){
	Matrix n;createMatrix(ROW_EFF(*m),COL_EFF(*m),&n);
	int i,j;
	for(i=0;i<ROW_EFF(*m);i++){
		for(j=0;j<COL_EFF(*m);j++){
			
		}
	}
}