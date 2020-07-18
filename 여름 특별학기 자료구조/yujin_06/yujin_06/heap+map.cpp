#include "heap+map.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int is_num(char * str) {
	for (int i = 0; str[i] != '\0'; i++){
		if( 0<=str[i]-'0' && str[i]-'0' <= 9)
			return 1;
	}
	return 0;
}


int is_word(char * str) {
	if (strcmp(" ", str) == 0)
		return 0;
	else if (strcmp("\n", str) == 0)
		return 0;
	else if (strcmp("\t", str) == 0)
		return 0;
	else if (strcmp("\&", str) == 0)
		return 0;
	else if (strcmp("\?", str) == 0)
		return 0;
	else if (is_num(str))
		return 0;
	else
		return 1;
}

char* only_word(char* str) {
	char * result = (char*)malloc(sizeof(char) * 64);
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '[') {
			result[cnt] = '\0';
			return result;
		}
		if (str[i] == '"' || str[i] == ','||str[i] == '.' ||
			str[i] == '(' || str[i] == ')' || str[i] == ';' 
			|| str[i] == '?' || str[i] == '!' || str[i] == ':'
			|| str[i] == ']' || str[i] == '[')
			continue;
		result[cnt] = str[i];
		cnt++;
	}
	result[cnt] = '\0';

	return result;
}


void node::init() {
	this->key = (char*)malloc(sizeof(char) * 20);
	strcpy(this->key , "-1");
	this->value = 0;
	this->lchild = this->rchild = NULL;
}
void node::set(char* skey) {
	this->key = (char*)malloc(sizeof(char) * 20);
	strcpy(this->key, skey);
	this->value = 1;
	this->lchild = this->rchild = NULL;
}

int node::find(char* skey) { // value 리턴
	if (strcmp(skey ,this->key) == 0)
		return this->value;
	int temp;
	if (strcmp(skey , this->key)>0 && this->rchild != NULL) {
		temp = this->rchild->find(skey);
		if (temp > 0) 
			return temp;
	} 
	if (strcmp(skey ,this->key)<0 && this->lchild != NULL) { 
		temp = this->lchild->find(skey);
		if (temp > 0) 
			return temp;
	}
	return 0;

}
int node::insert(char * ikey) {
	char * key_ = only_word(ikey);
	//처음 insert 라면?
	if (strcmp(this->key, "-1") == 0)
		this->set(key_);

	if (strcmp(key_, this->key) == 0) {
		this->value++;
		return 0;
	}
	else if (strcmp(key_, this->key) > 0) {
		if (this->rchild != NULL) {
			if (this->rchild->insert(ikey))
				return 1;
		}
		else {
			this->rchild = (node*)malloc(sizeof(node));
			this->rchild->set(key_);
			return 1;
		}
	}
	else {
		if (this->lchild != NULL) {
			if (this->lchild->insert(ikey))
				return 1;
		}
		else {
			this->lchild = (node*)malloc(sizeof(node));
			this->lchild->set(key_);
		}
	}
	return 0;
}
char* node::get_data() {
	return this->key;
}
int node::get_cnt() {
	return this->value;
}
int value_TT;
int node::remove(char * dkey) {
	//  dkey와key와같으면 
	if (strcmp(dkey, this->key) == 0) {
		//printf("Deleting %s\n", dkey);
		// (1) 두child가다NULL
		if (this->lchild == NULL && this->rchild == NULL)
			return 1; //부모에게 죽여달라고 요청

		// (2-1) lchild만NULL 
		if (this->lchild == NULL && this->rchild != NULL) {
			strcpy(this->key, this->rchild->key);
			this->value = this->rchild->value;

			this->lchild = this->rchild->lchild;
			this->rchild = this->rchild->rchild;
			return 0; // 죽이진말고 내가 변경함
		}
		// (2-2) rchild만NULL 
		if (this->lchild != NULL && this->rchild == NULL) {
			strcpy(this->key, this->lchild->key);
			this->value = this->lchild->value;

			this->rchild = this->lchild->rchild;
			this->lchild = this->lchild->lchild;
			return 0;
		}
		// (3) 둘다NULL이아닌경우 

		if (this->lchild != NULL && this->rchild != NULL) {
			strcpy(this->key, this->lchild->get_max());
			this->value = this->lchild->find(this->key);
			if (this->lchild->remove(this->key) == 1) // 바꿔치기한애 죽여 
				this->lchild = NULL;

			return 0;
		}

	}
	//dkey가key보다작으면 
	else if (strcmp(dkey,this->key)<0) {
		if (this->lchild != NULL) {
			if (this->lchild->remove(dkey)==1)
				this->lchild = NULL;
		}
		else {
			//printf("not found\n");
		}
		return 0;
	} 
	//  dkey가key보다크면 
	else {
		if (this->rchild != NULL) {
			if (this->rchild->remove(dkey)==1)
				this->rchild = NULL;
		}
		else {
			//printf("not found\n");
		}
		return 0;
	} 
}
char* node::get_max() {
	if (this->rchild != NULL) {
		return this->rchild->get_max();
	}
	else {
		return this->get_data();
	}
}
void node::print() {
	if (this->lchild != NULL) {
		this->lchild->print();
	}
	printf("%s  (%d)\n", this->key, this->value);
	if (this->rchild != NULL) {
		this->rchild->print();
	}
}

 

void heap::init() {
	this->cnt = 0;
	this->heap_list = (hnode*)malloc(sizeof(heap) * 100000);
	for (int i = 0; i < 100000; i++)
		heap_list[i].init();
}
void swap(hnode * a, hnode *b) {
	hnode temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

hnode heap::list(int idx) {
	return this->heap_list[idx];
}


void heap::heapify_topdown(int idx) {
	// leaf node에 도착하면 끝
	if (2 * idx > cnt)
		return;
	if (2 * idx == cnt) {
		if (heap_list[idx].get_cnt() < heap_list[2 * idx].get_cnt())
			swap(&heap_list[idx], &heap_list[2 * idx]);
		return;
	}

	if (heap_list[2 * idx].get_cnt() >= heap_list[2 * idx + 1].get_cnt()  && heap_list[2 * idx].get_cnt() > heap_list[idx].get_cnt()) { 
		swap(&heap_list[idx], &heap_list[2 * idx]);
		heapify_topdown(2 * idx);
	}
	else if (heap_list[2 * idx + 1].get_cnt() >= heap_list[2 * idx].get_cnt() && heap_list[2 * idx + 1].get_cnt() > heap_list[idx].get_cnt()) {
		swap(&heap_list[idx], &heap_list[2 * idx + 1]);
		heapify_topdown(2 * idx + 1);
	}
}
void heap::heapify_bottomup(int idx) {
	// root node에 도착하면 끝
	//printf("idx %d\n", idx);
	if (idx == 1)
		return;
	if (heap_list[idx / 2].get_cnt() < heap_list[idx].get_cnt()) {
	//	printf("%s <-> %s\n", heap_list[idx / 2].get_data(), heap_list[idx].get_data());
		swap(&heap_list[idx / 2], &heap_list[idx]);
	//	printf("swap!\n%s <-> %s\n", heap_list[idx / 2].get_data(), heap_list[idx].get_data());
		heapify_bottomup(idx / 2);
	}
}


void heap::push(hnode n) {
	this->cnt++;

	heap_list[this->cnt].set(n.get_cnt(), n.get_data());
	heapify_bottomup(this->cnt);

}
hnode heap::pop() {
	hnode temp;
	temp.init();
	temp.set(heap_list[1].get_cnt(), heap_list[1].get_data());


	heap_list[1].set(heap_list[this->cnt].get_cnt(), heap_list[this->cnt].get_data());

	this->cnt--;
	heapify_topdown(1);
	return temp;
}

int heap::get_cnt() {
	return cnt;
}

void hnode::print() {
	printf("%s (%d)\n", this->key, this->cnt);
}
void hnode::init() {
	key = this->key = (char*)malloc(sizeof(char) * 60);
	cnt = 0;
}
void hnode::set(int cnt_, char* key_) {
	this->cnt = cnt_;
	strcpy(this->key, key_);
}
char * hnode::get_data() {
	return this->key;
}
int hnode::get_cnt() {
	return this->cnt;
}