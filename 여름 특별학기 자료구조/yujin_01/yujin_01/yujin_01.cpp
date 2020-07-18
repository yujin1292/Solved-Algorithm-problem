#pragma warning(disable : 4996)

#include <time.h>
#include <stdio.h>
#include "sparse.h"


int n;
int** matA;
int** matB;
int** matC;

smatrix smatA;
smatrix smatB;
smatrix smatC;

smatrix smatBT;



extern void load(FILE* fpA, FILE* fpB);
extern int** transpose(int n, int** mat);
extern int** add(int n, int** matA, int** matB);
extern int** mult(int n, int** matA, int** matB);

int main(){

	clock_t tik, tok;


	printf("[LOADING]\n");
	//1.load
	FILE* fpA = fopen("matA\\matA_K.txt", "r+t");
	FILE* fpB = fopen("matB\\matB_K.txt", "r+t");


	tik = clock();
	load(fpA, fpB); // matA와 matB에 행렬저장됨
	tok = clock();
	printf("Loading: %f\n\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	smatA.convert_to_smat(n, matA);
	smatB.convert_to_smat(n, matB); 

	printf("[TRANSPOSE] \n");
	//2.transpose 
		//2.1 ordinary transpose
	tik = clock();
	matC = transpose(n, matA);
	tok = clock();
	printf("Transpose: %f\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	//2.2 fastTranspose
	tik = clock();
	smatBT.fastTranspose(smatA);
	tok = clock();
	printf("Fast transpose: %f\n\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	printf("[ADD]\n");
	//3.add
		//3.1 ordinary add
	tik = clock();
	matC = add(n, matA, matB);
	tok = clock();
	printf("add: %f\n", (float)(tok - tik) / CLOCKS_PER_SEC);
	//3.2 fastAdd

	tik = clock();
	smatC.fastAdd(smatA, smatB);
	tok = clock();
	printf("FastAdd: %f\n\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	printf("[MULTIPLY]\n");
	//4.multiply
		//4.1 ordinary multiply
	tik = clock();
	matC = mult(n, matA, matB);
	tok = clock();
	printf("Multiply: %f\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	//4.2 fastMultiply
	tik = clock();
	smatC.fastMulti(smatA, smatB);
	tok = clock();
	printf("Fast Multiply: %f\n\n", (float)(tok - tik) / CLOCKS_PER_SEC);


	fclose(fpA);
	fclose(fpB);
	system("pause");
	return 0;
}