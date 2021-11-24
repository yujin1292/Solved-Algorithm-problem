#include <iostream>
#include <vector>
using namespace std;


class node{
private:
	int item;
	node *rchild;
	node *lchild;
public :
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
bool node::searchItem(int i){

	if (item == i)
		return true;

	else if (item < i) { //rchild
		if (rchild == NULL)
			return false;
		return rchild->searchItem(i);
	}
	else {//lchild
		if (lchild == NULL)
			return false;
		return lchild->searchItem(i);
	}
}
bool node::insertItem(int i){

	if (i == item)
		return false;

	else if (item < i) { //�����ʿ�����
		if (rchild == NULL) {
			//���ο� ��常��� �����ϱ�
			node* temp = (node*)malloc(sizeof(node));

			temp->item = i;
			temp->rchild = temp->lchild = NULL;
			//rchild�� ���̱�
			rchild = temp;
			return true;
		}
		else 
			return rchild->insertItem(i);
	}

	else { // ���ʿ�����
		if (lchild == NULL) {
			//���ο� ��常��� �����ϱ�
			node* temp = (node*)malloc(sizeof(node));

			temp->item = i;
			temp->rchild = temp->lchild = NULL;
			//lchild�� ���̱�
			lchild = temp;
			return true;
		}
		else
			return lchild->insertItem(i);
	}

	return false;
}
void node::print(){ 
	// inorder ��ȸ

	//1.���� child ����Ʈ
	if(lchild!=NULL)
		lchild->print();

	//2. �� ����Ʈ
	cout << item << "\n";

	//3. ������ child ����Ʈ
	if(rchild!=NULL)
		rchild->print();
	
}

int main() {

	node mytree(5);
	vector<int> numbers = { 3,3,6,2,7,11,2,4 };
	vector<int> numbers2 = { 3,234,55,1,6,7 };


	for (int i = 0; i < numbers.size(); i++) {
		if (mytree.insertItem(numbers[i]))
			cout << numbers[i] << " ���� ����\n";
		else
			cout << numbers[i] << " ���� ����!\n";
	}
	
	cout << "================================\n";
	mytree.print();
	cout << "================================\n";


	for (int i = 0; i < numbers2.size(); i++) {
		if (mytree.searchItem(numbers2[i]))
			cout << numbers2[i] << " �� ã�ҽ��ϴ� \n";
		else
			cout << numbers2[i] << " �� �����ϴ�!\n";
	}

}