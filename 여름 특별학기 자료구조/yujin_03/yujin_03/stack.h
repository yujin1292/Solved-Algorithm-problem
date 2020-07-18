class pos { 

public:

	int x; 
	int y; 

	void set(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void set(pos p) {
		x = p.x;
		y = p.y;
	}
	void up() {
		x--;
	}
	void down() {
		x++;
	}
	void right() {
		y++;
	}
	void left() {
		y--;
	}
	int is_same(pos p) {
		return (p.x == x && p.y == y);
	}
	void print() {
		printf("%d , %d\n", x, y);
	}

};


class stack { 
public:

	int top;
	int n;
	pos*arr; 


	void init();
	int is_full();
	int is_empty();
	void push(pos P);
	pos pop();
	pos Top();
};