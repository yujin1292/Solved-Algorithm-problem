#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#pragma warning(disable : 4996)


extern int wid, hei;
extern pos in, out;
extern char **maze;



void stack::init() {
	this->top = 0;
	n = 0;
	arr = (pos*)malloc(sizeof(pos) * 100);
}
int stack::is_full() {
	return top == 100;
}
int stack::is_empty() {
	return n == 0;
}
void stack::push(pos P) {
	if (this->is_full() ) {
	//	printf("full!");
		return;
	}
	arr[top] = P;
	top++;
	n++;
	
}
pos stack::pop() {
	if (this->is_empty()) {
	//	printf("is empty!");
		return *arr;
	}
	top--;
	n--;
	return arr[top];
}
pos stack::Top() {
	if (this->is_empty()) {
	//	printf("is empty!");
		return *arr;
	}
	return arr[top - 1];
}

