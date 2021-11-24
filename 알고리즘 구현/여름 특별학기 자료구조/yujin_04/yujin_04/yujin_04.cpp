#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack1.h"
#include "stack2.h"



int tcnt =0;
int ptcnt=0;

char ** tok;
char ** ptok;

int main()
{
	printf("start!\n\n");
	char expr[256] = "((3 + 4) * 8 - 7) / 2";
	//char expr[256] = "1 + 5";
	//char expr[256] = "31.6 + (19.3 - 2.1)*((1.4^0.6) + 8.5)";
	char expr2[256];
	remove_delimiters(expr2, expr);
	token_parser(expr2);
	print_tok(tcnt, tok);
	postpix();
	print_tok(ptcnt, ptok);
	evaluate();
	system("pause");
	return 0;
}