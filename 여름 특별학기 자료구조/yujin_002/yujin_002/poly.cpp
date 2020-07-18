#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#pragma warning(disable : 4996)


void  polynomial::zero(){
	head = (term*)malloc(sizeof(term));
	head->coef = 0;
}

int polynomial::is_zero(){
	return (head->coef == 0);
}

int polynomial::coef(int exp){
	term *curr;
	for (curr = head; curr != NULL; curr = curr->next) {
		if (curr->exp == exp)
			return curr->coef;
	}
	return 0;
}

int polynomial::LeadExp(){
	if (is_zero()) {
		printf("Zero polynomial\n");
		return 0;
	}
	return head->exp;
}

void polynomial::append(int _coef, int _exp) {
	if (head->coef == 0) { // zero
		this->head->set(_coef, _exp);
		this->degree = _exp;
	}

	else {
		term * temp = (term*)malloc(sizeof(term));
		temp->set(_coef, _exp);
		term *curr = head;
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = temp; //curr->next == NULL임 
	}
}


void polynomial::insert(int _coef, int _exp) {

	// 예외 처리
	if (this->degree < _exp) {
		printf("err"); 
		return;

	}
		
	// 삽입할 위치를 결정
	term * curr;
	if (head->coef == 0) { // zero 맨처음들어있음
		this->head->set(_coef, _exp);
		this->degree = _exp;

		return;
	}

	for (curr = head; curr->next != NULL; curr = curr->next) {
		if (curr->next->exp <= _exp) { //나보다 작거나 같은 녀석을 만나면 멈춰
			if (curr->next->exp == _exp) {  // exp와 같은 지수를 가진 항이 있는 경우 더할거임
				if ((curr->next->coef + _coef) == 0) { // 합이 0이면 free
				
					term * dterm = curr->next;
					curr->next = dterm->next;
					free(dterm);
					return;
				}
				else {
					
					curr->next->coef += _coef;
					return;
				}
			}

			else {// exp와 같은 지수를 가진 항이 없는 경우
				term *temp = (term*)malloc(sizeof(term));
				temp->set(_coef, _exp);
				temp->next = curr->next; //temp에 curr의 next의 주소값
				curr->next = temp;
				
				return;
			}
		}

	}

	// 삽입할 위치가 마지막인 경우

	this->append(_coef, _exp);
}

void polynomial::load(FILE *fp) {

	int n = 0;
	fscanf(fp, "%d", &n);

	int num1 = 1;
	int num2 = 1;
	char temp1[10] =" ";
	char temp2[10] =" ";


	this->zero();

	for (int i = 0; i < n; i++) {
		fscanf(fp, "%s %s", temp1,temp2);
		num1 = atoi(temp1);
		num2 = atoi(temp2);
		this->append(num1, num2);
	}
}


void polynomial::add(polynomial pA, polynomial pB){
	
	term * currA;
	term * currB;

	currA = pA.head;
	currB = pB.head;

	while (currA != NULL && currB != NULL) {
		if (currA->exp == currB->exp) {		// currA의 지수와 currB의 지수가 같으면
			if ((currA->coef + currB->coef) != 0) {
				this->append(currA->coef + currB->coef, currA->exp);
			}
			currA = currA->next;
			currB = currB->next;
			
		}
		else if (currA->exp > currB->exp){// currA의 지수가 currB의 지수보다 크면
			this->append(currA->coef, currA->exp);
			currA = currA->next;
		}

		else{  // currA의 지수가 currB의 지수보다 작으면
			this->append(currB->coef, currB->exp);
			currB = currB->next;
		}
	}

	this->degree = this->head->exp;
}


void polynomial::multiply(polynomial pA, polynomial pB) {
	term * currA;
	term * currB;
	this->degree = pA.head->exp + pB.head->exp;
	for (currA = pA.head; currA != NULL; currA = currA->next) {
		for (currB = pB.head; currB != NULL; currB = currB->next) {
			// currA와 currB를 곱해서 insert할 것
			this->insert(currA->coef*currB->coef, currA->exp + currB->exp);
		}
	}

}


void polynomial::print() {
	if (this->is_zero()) {
		printf("0");
		return;
	}
		

	term * curr;

	for (curr = head; curr->next != NULL; curr = curr->next) {
		curr->print();
	}
	
	curr->print();

	
}

void  term::print() {
	if (this->coef == 1) {//계수가 1임 
		if (exp == 0)
			printf(" + 1");
		else if (exp == 1)
			printf(" +x ");
		else
			printf(" +x^%d ",exp);
	}

	else if (coef < 0) {//계수가 음수
		if (exp == 0) //0차
			printf("%d ", coef);
		else if (exp == 1)//1차
			printf("%dx ", coef);
		else
			printf("%dx^%d ",coef, exp);

	}
	else { //계수가 양수
		if (exp == 0) //0차
			printf(" +%d ", coef);
		else if (exp == 1)//1차
			printf(" +%dx ",coef);
		else
			printf(" +%dx^%d",coef, exp);
	}

}