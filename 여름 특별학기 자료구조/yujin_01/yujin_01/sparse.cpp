#include "sparse.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


void smatrix::convert_to_smat(int n, int** mat) {
	//1. count non-zero elements

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != 0) {
				count++;
			}
		
		}
	}


	//2. alloc smat
	//3. build smat
	element* list_ = (element*)malloc(sizeof(element) * (count + 1) );

	list_[0].set(n, n, count);
	int k = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != 0) {
				list_[k].set(i, j, mat[i][j]);
				k++;
			}
		}
	}

	this->n = n;
	this->cnt = count;
	this->list = list_;
	this->ready();
}

void smatrix::ready() {
	int* rowTerms_ = (int*)malloc(sizeof(int) * (this->n));
	int* startPos_ = (int*)malloc(sizeof(int) * (this->n));

	//0. 0으로 초기화
	for (int i = 0; i < this->n; i++) {
		rowTerms_[i] = 0;
		startPos_[i] = 0;
	}
	
	// 1. rowTerms계산
	
	for (int i = 0; i <= this->cnt; i++) {
		rowTerms_[this->list[i].col] ++;
	}

	// 2. startPos계산 rowTerms를이용
	startPos_[0] = 1;

	for (int i = 1; i < this->n ; i++) {

		startPos_[i] = startPos_[i - 1] + rowTerms_[i - 1];
		
	}

	this->startPos = startPos_;
	this->rowTerms = rowTerms_;
}

void smatrix::ready_() {
	int* rowTerms_ = (int*)malloc(sizeof(int) * (this->n));
	int* startPos_ = (int*)malloc(sizeof(int) * (this->n));

	//0. 0으로 초기화
	for (int i = 0; i < this->n; i++) {
		rowTerms_[i] = 0;
		startPos_[i] = 0;
	}

	// 1. rowTerms계산

	for (int i = 0; i <= this->cnt; i++) {
		rowTerms_[this->list[i].row] ++;
	}

	// 2. startPos계산 rowTerms를이용
	startPos_[0] = 1;

	for (int i = 1; i < this->n; i++) {

		startPos_[i] = startPos_[i - 1] + rowTerms_[i - 1];

	}

	this->startPos = startPos_;
	this->rowTerms = rowTerms_;
}

void smatrix::fastTranspose(smatrix smat) {

	this->cnt = smat.cnt;
	this->n = smat.n;

	smat.ready();

	if (smat.cnt <= 0)
		return;
	int j;

	this->list = (element*)malloc(sizeof(element)* (this->cnt +1));
	this->list[0].set(n, n, cnt);
	

	int temp; 
	for (int i = 1; i <= smat.cnt; i++) {
		temp = smat.list[i].col;
		j = smat.startPos[temp]++;
		
		this->list[j].row = smat.list[i].col;
		this->list[j].col = smat.list[i].row;
		this->list[j].val = smat.list[i].val;
	}

	this->ready_();
}

void smatrix::fastAdd(smatrix smatA, smatrix smatB) {
	//초기화
	this->cnt = 0;
	this->n = 0;
	this->list = (element*)malloc(sizeof(element));
	this->list[0].row = this->list[0].col = smatA.n;
	this->list[0].val = 0;

	int i = 1;
	int j = 1;
	while (i != smatA.cnt && j != smatB.cnt)
	{

		// 1. smatA의행==smatB의행 
		if (smatA.list[i].row == smatB.list[j].row) {
			// 1.1 smatA의열== smatB의열
			if (smatA.list[i].col == smatB.list[j].col) {
				// ADD!! 
				element temp;
				temp.set(smatA.list[i].row, smatB.list[i].col, smatA.list[i].val + smatB.list[j].val);
				this->append(temp);
				if(i <= smatA.cnt)
					i++;
				if(j <= smatB.cnt)
					j++;

			}
			// 1.2 smatA의열< smatB의열
			else if (smatA.list[i].col < smatB.list[j].col) {
				//smatA append
				this->append(smatA.list[i]);
				if (i <= smatA.cnt)
					i++;
			}

			// 1.3 smatA의열> smatB의열
			else {
				//smatB append
				this->append(smatB.list[j]);
				if (j <= smatB.cnt)
					j++;
			}

		}
		// 2. smatA의행< smatB의 행
		else if (smatA.list[i].row < smatB.list[j].row) {
			//smatA append
			this->append(smatA.list[i]);
			if (i <= smatA.cnt)
				i++;
		}
		// 3. smatA의행> smatB의 행
		else {
			//smatB append
			this->append(smatB.list[j]);
			if (j <= smatB.cnt)
				j++;
		}

	}
}

void smatrix::fastMulti(smatrix smatA, smatrix smatB) {
	//smatC (this) 초기화
	int a = smatA.n;

	this->cnt = 0;
	this->n = 0;
	this->list = (element*)malloc(sizeof(element));
	this->list[0].row = this->list[0].col = a;
	this->list[0].val = 0;
	
	
	smatrix smatBT;
	smatBT.fastTranspose(smatB);
	
	int temp;


	// smatC[i, j, k]  smatA의i번째행과 smatBT의j번째행의곱
		// smatA의i번째행  <- startPosA[i] ~ startPosA[i] + rowTermsA[i] 
		// smatBT의j번째행 <- startPosBT[j] ~ startPosBT[j] + rowTermsBT[j]
		element C_element;	
	int j, i;
	for (i = 0; i <= a; i++) { // smatA의모든행과 smatBT의transpose의모든행에대해서연산
		for (j = 0 ; j <= a; j++) {
			temp = 0;
			
			for (int jj = 0; j < smatA.rowTerms[i]; j++) {
				for (int ii = 0; ii < smatBT.rowTerms[j] ; ii++) {
					if(smatA.list[smatA.startPos[i] + ii].col == smatB.list[smatBT.startPos[j] + jj].col){}
						temp += smatA.list[smatA.startPos[i]+ii].val * smatB.list[smatBT.startPos[j]+jj].val;
				}
			}
			
			C_element.set(i, j, temp);
			if(temp != 0)
				this->append(C_element); // this의 list에  저장 (val, cnt update됨) 이게 엄청오래걸림 왜야왜
		}

	}
}


void smatrix::append(element ele){
	this->cnt++;
	this->list[0].val++;
	this->list = (element*)realloc(this->list, sizeof(element) * (this->cnt + 1));
	this->list[cnt] = ele;
	}

void smatrix::store(int idx, element ele) {
	this->cnt++;
	this->list[0].val++;
	this->list = (element*)realloc(this->list, sizeof(element) * (this->cnt + 1));

	//idx 다음부터 한칸씩 뒤로 보내기 
	for (int i = cnt; i > idx ; i--)
		this->list[i] = this->list[i - 1];

	//idx 자리에 추가하기
	this->list[idx] = ele;

}