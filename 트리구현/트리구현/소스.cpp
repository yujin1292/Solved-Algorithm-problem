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

	else if (item < i) { //오른쪽에삽입
		if (rchild == NULL) {
			//새로운 노드만들고 세팅하기
			node* temp = (node*)malloc(sizeof(node));

			temp->item = i;
			temp->rchild = temp->lchild = NULL;
			//rchild에 붙이기
			rchild = temp;
			return true;
		}
		else 
			return rchild->insertItem(i);
	}

	else { // 왼쪽에삽입
		if (lchild == NULL) {
			//새로운 노드만들고 세팅하기
			node* temp = (node*)malloc(sizeof(node));

			temp->item = i;
			temp->rchild = temp->lchild = NULL;
			//lchild에 붙이기
			lchild = temp;
			return true;
		}
		else
			return lchild->insertItem(i);
	}

	return false;
}
void node::print(){ 
	// inorder 순회

	//1.왼쪽 child 프린트
	if(lchild!=NULL)
		lchild->print();

	//2. 나 프린트
	cout << item << "\n";

	//3. 오른쪽 child 프린트
	if(rchild!=NULL)
		rchild->print();
	
}

int main() {

	node mytree(5);
	vector<int> numbers = { 3,3,6,2,7,11,2,4 };
	vector<int> numbers2 = { 3,234,55,1,6,7 };


	for (int i = 0; i < numbers.size(); i++) {
		if (mytree.insertItem(numbers[i]))
			cout << numbers[i] << " 삽입 성공\n";
		else
			cout << numbers[i] << " 삽입 실패!\n";
	}
	
	cout << "================================\n";
	mytree.print();
	cout << "================================\n";


	for (int i = 0; i < numbers2.size(); i++) {
		if (mytree.searchItem(numbers2[i]))
			cout << numbers2[i] << " 을 찾았습니다 \n";
		else
			cout << numbers2[i] << " 이 없습니다!\n";
	}

}