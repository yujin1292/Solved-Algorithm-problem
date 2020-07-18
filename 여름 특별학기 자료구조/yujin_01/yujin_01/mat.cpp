#pragma warning(disable : 4996)
#include<stdio.h>
#include "sparse.h"

extern int n;
extern int** matA;
extern int** matB;
extern int** matC;


//1. load

void load(FILE* fpA, FILE* fpB) {

	// fp에서 지정된 파일에서 n x n 크기의 행렬을 저장한다.
	// 어디에?
	// 

	fscanf(fpA, "%d", &n);
	matA = (int**)malloc(sizeof(int)*n*n);
	for (int i = 0; i < n; i++) 
		matA[i] = (int*)malloc(sizeof(int) * n);	


	for (int i = 0; i < n; i++) { //matA에 저장
		for (int j = 0; j < n; j++) {
			fscanf(fpA, "%d", &matA[i][j]);
		}
	}

	fscanf(fpA, "%d", &n); // n 저장
	matB = (int**)malloc(sizeof(int)*n*n);
	for (int i = 0; i < n; i++)
		matB[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) { //matB 저장 
		for (int j = 0; j < n; j++) {
			fscanf(fpB, "%d", &matB[i][j]);
		}
	}

}


//2. transpose


int** transpose(int n, int** mat) {
	int** matT = (int**)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n; i++)
		matT[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matT[i][j] = mat[j][i];
		}
	}

	return matT;
}

//3. add

int** add(int n, int** matA, int** matB) {

	int** matC = (int**)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n; i++)
		matC[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}
	return matC;
}

//4. multiply

int** mult(int n, int** matA, int** matB) {

	int** matC = (int**)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n; i++)
		matC[i] = (int*)malloc(sizeof(int) * n);

	int i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0, matC[i][j] = 0; k < n; k++) {
				matC[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}

	return matC;
}
