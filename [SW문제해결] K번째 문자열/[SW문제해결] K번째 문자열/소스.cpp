#include <iostream>
#include <string>
#include <vector>

#define ALPHABETS 28
using namespace std;

int dollor = 0;

int K;
string input;
vector<char> p;
int number = 0;

int char_to_index(char c) {
	return c - 'a' + 1;
}
class Trie {

public:
	char c;
	Trie * children[ALPHABETS];


	Trie() {
		c = ' ';
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}

	}
	Trie(int cc) {
		c = cc;
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}
	}
	void init(int cc) {
		c = cc;
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}
	}
	void insert(char a, string s) {
		if (a == '$') {
			Trie*t = (Trie*)malloc(sizeof(Trie));
			t->init(a);
			children[dollor] = t;
			return;
		}

		if (children[char_to_index(a)] == NULL) {
			Trie*t = (Trie*)malloc(sizeof(Trie));
			t->init(a);
			children[char_to_index(a)] = t;
			t->insert(s[1], s.substr(1, s.size() - 1));
		}
		else {
			children[char_to_index(a)]->insert( s[1], s.substr(1, s.size() - 1));
		}
	}

	void insert(string s) {
		for (int split = 1; split <= s.size(); split++) {
			for (int i = 0; i < s.size() - split ; i++) {
			//	cout << split << " " << s[i] << " " << s.substr(i, split) << endl;
				this->insert(s[i], s.substr(i, split)+"$" );
			}
		}
		
	}

	void print() {
		//printc();

		for (int i = 0; i < ALPHABETS -1 ; i++) {
			if (children[i] != NULL) {
				if (i == dollor) {
					number++;

					if (number == K) {
						for (int j = 0; j < p.size(); j++)
							cout << p[j];
					}
					/*cout << number << ": ";
					for (int j = 0; j < p.size(); j++)
						cout << p[j] << " ";
					cout << endl;*/
				}
				else {
					p.push_back(i + 'a' -1);
					children[i]->print();
					p.pop_back();
				}
			}
		}
	}
	void printc() {
		cout << "\n" << c << "--> ";
		for (int i = 0; i < ALPHABETS; i++) {
			if (children[i] != NULL)
				cout << char(i + 'A') << " ";
		}
		cout << endl;
	}
};

void find() {
	input.append("$");
	string result;

	Trie root;

	root.insert(input);
	root.print();
	if (K > number)
		cout << "none";

}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> K >> input;
		cout << "#" << t + 1 << " ";
		find();
		cout << endl;
		number = 0;
	}

	return 0;
}