#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack2.h"
#include "stack1.h"

#pragma warning(disable : 4996)

extern int tcnt;
extern int ptcnt;

extern char ** tok;
extern char ** ptok;

//후위 표기식 연산을 위한 stack ptok을 이용해야함


void stack::init() {
	top = 0;
	n = 0;
	tokens = (char**)malloc(sizeof(char) * 20 * 100);
	for (int i = 0; i < 100; i++) {
		tokens[i] = (char*)malloc(sizeof(char) * 20);
	}
}
int stack::is_full() {
	return (n == 100);
}
int stack::is_empty() {
	return n == 0;
}
void stack::push(char * P) {
	if (this->is_full())
		return;
	strcpy(tokens[top], P);
	top++;
	n++;
}
char* stack::pop() {
	if (this->is_empty())
		return NULL;
	top--;
	n--;
	return tokens[top];
}
char* stack::Top() {
	if (this->is_empty())
		return NULL;

	return tokens[top-1];
}


void evaluate() {
	double result;
	double od2;

	char t1[20];
	char t2[20];

	stack e_stack;
	e_stack.init();
	for (int i = 0; i < ptcnt; i++) {

		if (!is_operator(ptok[i][0])) {
			e_stack.push(ptok[i]);
		}

		else {
			strcpy(t2, e_stack.pop());
			strcpy(t1, e_stack.pop());

			switch (ptok[i][0]) {
			case '+':
				result = atof(t1) + atof(t2);
				sprintf(t1, "%lf", result);
				e_stack.push(t1);
				//printf("%lf\n", result);
				break;
			case '-':
				result = atof(t1) - atof(t2);
				sprintf(t1, "%lf", result);
				e_stack.push(t1);
				//printf("%lf\n", result);
				break;

			case '*':
				result = atof(t1) * atof(t2);
				sprintf(t1, "%lf", result);
				e_stack.push(t1);
				//printf("%lf\n", result);
				break;
			case '/':
				result = atof(t1) / atof(t2);
				sprintf(t1, "%lf", result);
				e_stack.push(t1);
				//printf("%lf\n", result);
				break;

			case '^':
				result = pow(atof(t1) , atof(t2));
				sprintf(t1, "%lf", result);
				//printf("%lf\n", result);
				e_stack.push(t1);
				break;

			}
		}
	}

	printf("%s\n", e_stack.pop());
}