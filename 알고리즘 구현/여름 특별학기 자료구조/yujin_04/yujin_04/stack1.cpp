#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack1.h"
#include "stack2.h"
#pragma warning(disable : 4996)


extern int tcnt;
extern int ptcnt;

extern char ** tok;
extern char ** ptok;

// ���� ǥ��� ������ ����


int is_operator(char op) { //�켱������ ���� = ���ڰ� �۴�
	if (op == '+')
		return 4;
	else if (op == '-')
		return 4;
	else if (op == '*')
		return 3;
	else if (op == '/')
		return 3;
	else if (op == '^')
		return 2;
	else if (op == '(')
		return 10;
	else if (op == ')')
		return 10;
	
	else
		return 0;
}

void remove_delimiters(char * dest, char * res) {
	int j = 0;
	for (int i = 0; res[i]!= '\0'; i++) {
		if (res[i] != ' ') {
			dest[j] = res[i];
			j++;
		}
	}
	dest[j] = '\0';
}

void token_parser(char * expr) {
	tok = (char**)malloc(sizeof(char) * 5 * 100);
	for (int i = 0; i < 100; i++) {
		tok[i] = (char*)malloc(sizeof(char) * 5);
	}

	//tok �� expr(����) �� token ���� �ɰ��� ��ƾ���
	
	char op[5];
	char * num = (char*)malloc(sizeof(char) * 10);
	int n = 0;

	for (int i = 0; expr[i] != '\0'; i++) {
		if (is_operator(expr[i]) ) { //������ �϶� 
			if (n != 0) {
				num[n] = '\0';
				strcpy(tok[tcnt], num);
				tcnt++;
				num = (char*)malloc(sizeof(char) * 10);
				n = 0;
			}
			
			

			op[0] = expr[i];
			op[1] = '\0';

			strcpy(tok[tcnt], op);
			tcnt++;
		}
		else { // �����϶�
			num[n] = expr[i];
			n++;
		}
	}

	if (n != 0){
		num[n] = '\0';
		strcpy(tok[tcnt], num);
		tcnt++;
	}
	
}


void print_tok(int tcnt, char** tok) {

	for (int i = 0; i < tcnt; i++) {
		printf("%s ", tok[i]);
	}
	printf("\n");
}


int cmp_op(char op1, char op2) {
	int o1 = is_operator(op1);
	int o2 = is_operator(op2);

	return o1 <= o2;
}

void postpix() { //���� ���� ǥ������� ptok�� ����
	ptok = (char**)malloc(sizeof(char) * 5 * 100);
	for (int i = 0; i < 100; i++) {
		ptok[i] = (char*)malloc(sizeof(char) * 5);
	}

	stack stack;
	stack.init();

	for (int i = 0; i < tcnt; i++) {
		//printf("now -> %s \t|| ", tok[i]);
		if (is_operator(tok[i][0]) == 0) { //current token is an operand
			//printf("num \n");
			strcpy(ptok[ptcnt], tok[i]);
			ptcnt++;
		}
			
		else {
			if (tok[i][0] == '(') {
				//printf("( \n");
				stack.push(tok[i]);
				continue;
			}
			else if (tok[i][0] == ')') {
				//printf(")\n");
				while (!stack.is_empty() && strcmp(stack.Top(), "(") != 0) {
					strcpy(ptok[ptcnt], stack.pop());
					ptcnt++;

					//printf("pop : %s\n", ptok[ptcnt - 1]);
				} 
				stack.pop();
				continue;
			}
			else if (!stack.is_empty())
			{
				char temp[5];
				strcpy(temp, stack.Top());
				//printf("compare [%s, %s] =  %d\n", temp, tok[i], cmp_op(temp[0], tok[i][0]));
				if (cmp_op(temp[0], tok[i][0])) { // top�� ���ƾ� ����

					strcpy(ptok[ptcnt], stack.pop());
					ptcnt++;

					//printf("pop %s\n",ptok[ptcnt -1]);

					//continue;
				}
			}
			
			stack.push(tok[i]);
			//printf("push%s \n", tok[i]);
		}
	}
	while (!stack.is_empty()) {
		//printf("pop all\n");
	
		strcpy(ptok[ptcnt],stack.pop());
		ptcnt++;
		//printf("pop : %s\n", ptok[ptcnt - 1]);
	}

	printf("\n");
}