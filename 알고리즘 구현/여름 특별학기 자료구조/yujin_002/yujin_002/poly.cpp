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

		curr->next = temp; //curr->next == NULL�� 
	}
}


void polynomial::insert(int _coef, int _exp) {

	// ���� ó��
	if (this->degree < _exp) {
		printf("err"); 
		return;

	}
		
	// ������ ��ġ�� ����
	term * curr;
	if (head->coef == 0) { // zero ��ó���������
		this->head->set(_coef, _exp);
		this->degree = _exp;

		return;
	}

	for (curr = head; curr->next != NULL; curr = curr->next) {
		if (curr->next->exp <= _exp) { //������ �۰ų� ���� �༮�� ������ ����
			if (curr->next->exp == _exp) {  // exp�� ���� ������ ���� ���� �ִ� ��� ���Ұ���
				if ((curr->next->coef + _coef) == 0) { // ���� 0�̸� free
				
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

			else {// exp�� ���� ������ ���� ���� ���� ���
				term *temp = (term*)malloc(sizeof(term));
				temp->set(_coef, _exp);
				temp->next = curr->next; //temp�� curr�� next�� �ּҰ�
				curr->next = temp;
				
				return;
			}
		}

	}

	// ������ ��ġ�� �������� ���

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
		if (currA->exp == currB->exp) {		// currA�� ������ currB�� ������ ������
			if ((currA->coef + currB->coef) != 0) {
				this->append(currA->coef + currB->coef, currA->exp);
			}
			currA = currA->next;
			currB = currB->next;
			
		}
		else if (currA->exp > currB->exp){// currA�� ������ currB�� �������� ũ��
			this->append(currA->coef, currA->exp);
			currA = currA->next;
		}

		else{  // currA�� ������ currB�� �������� ������
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
			// currA�� currB�� ���ؼ� insert�� ��
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
	if (this->coef == 1) {//����� 1�� 
		if (exp == 0)
			printf(" + 1");
		else if (exp == 1)
			printf(" +x ");
		else
			printf(" +x^%d ",exp);
	}

	else if (coef < 0) {//����� ����
		if (exp == 0) //0��
			printf("%d ", coef);
		else if (exp == 1)//1��
			printf("%dx ", coef);
		else
			printf("%dx^%d ",coef, exp);

	}
	else { //����� ���
		if (exp == 0) //0��
			printf(" +%d ", coef);
		else if (exp == 1)//1��
			printf(" +%dx ",coef);
		else
			printf(" +%dx^%d",coef, exp);
	}

}