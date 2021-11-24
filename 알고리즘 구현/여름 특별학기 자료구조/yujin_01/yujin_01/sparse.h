#include <stdio.h>
#include <stdlib.h>

class element {
public:
	int row;
	int col;
	int val;

	void set(int row_, int col_, int val_) {
		row = row_;
		col = col_;
		val = val_;
	}
	


};

class smatrix {
	int n;
	int cnt;
	element* list;
	int* startPos, * rowTerms;

public:
	void convert_to_smat(int n, int** mat);
	void fastTranspose(smatrix smat);
	void fastAdd(smatrix smatA, smatrix smatB);
	void fastMulti(smatrix smatA, smatrix smatB);
	void ready();
	void ready_();
	void append(element ele);
	void store(int idx, element ele);

};