
int is_num(char * str);

class hnode {
	char* key;
	int cnt;
public:
	void init();
	void set(int cnt, char* key);
	char * get_data();
	int get_cnt();
	void print();
	
};

class node {
	char * key;
	int value;
	node * rchild;
	node * lchild;

public:
	void init();
	void set(char* skey);
	int find(char* skey);
	int insert(char * key);
	char* get_data();
	int get_cnt();
	int remove(char * key);
	char* get_max();
	void print();
};


class heap {
	int cnt;
	hnode * heap_list;

public:
	int get_cnt();
	void init();
	void push(hnode n);
	hnode pop();
	void heapify_topdown(int idx);
	void heapify_bottomup(int idx);
	hnode list(int idx);
};
void swap(hnode * a, hnode *b);
int is_word(char * str);