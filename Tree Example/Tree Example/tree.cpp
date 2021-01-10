#include <iostream>
using namespace std;

class node {


public:
	int item;
	node *rchild;
	node *lchild;

	node() {
		item = -1;
		rchild = lchild = NULL;
	}
	node(int item) {
		this->item = item;
		rchild = lchild = NULL;
	}

	bool searchItem(int i);
	bool insertItem(int i);
	void print();
};


void node::print() {
	if (lchild != NULL)
		lchild->print();
	cout << item << "\n";
	if (rchild != NULL)
		rchild->print();
}
bool node::insertItem(int i){
	if (item == i)
		return false;
	else if (this->item <= i) { //오른쪽에 insert
		if (rchild == NULL) {
			node* temp = (node*)malloc(sizeof(node));
			temp->rchild = temp->lchild = NULL;
			temp->item = i;
			rchild = temp;
		}
		else
			rchild->insertItem(i);
	}
	else { // 왼쪽에 insert
		if (lchild == NULL) {
			node* temp = (node*)malloc(sizeof(node));
			temp->rchild = temp->lchild = NULL;
			temp->item = i;
			lchild = temp;
		}
		else
			lchild->insertItem(i);
	}

	return true;
}
bool node::searchItem(int i) {
	if (item == i)
		return true;
	else if (item < i) {
		if (rchild == NULL)
			return false;
		return rchild->searchItem(i);
	}
	else if (i < item) {
		if (lchild == NULL)
			return false;
		return lchild->searchItem(i);
	}
}

int main() {
	node mytree(5);
	mytree.insertItem(3);
	mytree.insertItem(3);
	mytree.insertItem(7);
	mytree.insertItem(2);
	mytree.insertItem(11);
	mytree.insertItem(1);

	mytree.print();

	for (int i = 1; i < 9; i += 3) {
		cout << "find " << i << ": ";
		if (mytree.searchItem(i))
			cout << " FIND!!\n";
		else
			cout << " NO!!\n";
	}
	return 0;

}