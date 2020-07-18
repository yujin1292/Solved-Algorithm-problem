


class stack {
public:

	int top;
	int n;
	char ** tokens;


	void init();
	int is_full();
	int is_empty();
	void push(char * P);
	char* pop();
	char* Top();
};

char* f_to_a(double a);

void evaluate();