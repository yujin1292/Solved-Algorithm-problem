#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int wid, hei;
pos in, out;
char **maze;

void load_maze(FILE * fp) {
	fscanf(fp,"%d %d", &wid, &hei);
	printf("%d, %d\n", wid, hei);
	maze = (char**)malloc(sizeof(char)*wid*hei);

	for (int i = 0; i < hei; i++) {
		maze[i] = (char*)malloc(sizeof(char)*wid);
	}

	for (int i = 0; i< wid; i++) {
		for (int j = 0; j < hei; j++) {
			fscanf(fp, "%c", &maze[i][j]);
			if (maze[i][j] == ' ' || maze[i][j] == '\n') {
				j--;
				continue;
			}
			if (maze[i][j] == 'E')
				in.set(i, j);
			if (maze[i][j] == 'X')
				out.set(i, j);
			
		}
	}
}

void print_maze() {
	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < hei; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}

	printf("Entry :");
	in.print();
	printf("Exit :");
	out.print();
	printf("\n\n\n");

}

int can_go(char c) {
	if (c == '0')
		return 1;
	else if (c == 'X')
		return 1;
	else
		return 0;
}

void solve_maze() {

	stack s_maze;
	s_maze.init();

	pos curr;
	curr.set(in);
	s_maze.push(curr);

	// 1. �̵��Ҽ��ִµ����̵� 
	do {//  1. �̷�ã�� while ( !stack.is_empty( ) ) {
	
		if (0 <= (curr.x) - 1 && can_go( maze[curr.x - 1][curr.y]) ) {// ���ΰ���
			//printf("up ");
			curr.up();
			s_maze.push(curr);
			maze[curr.x][curr.y] = '#';
			if (curr.is_same(out))
				break;
			continue;
		}
		else if (0 <= (curr.y) - 1 && can_go(maze[curr.x][curr.y - 1])) { //����
			//printf("left ");
			curr.left();
			s_maze.push(curr);
			maze[curr.x][curr.y] = '#';
			if (curr.is_same(out))
				break;
			continue;
		}
		else if (curr.x + 1 < hei && can_go(maze[curr.x + 1][curr.y])) {//�Ʒ�
			//printf("down ");
			curr.down();
			s_maze.push(curr);
			maze[curr.x][curr.y] = '#';
			if (curr.is_same(out))
				break;
			continue;
		}
		else if (curr.y + 1 < wid && can_go(maze[curr.x][curr.y + 1] )) {//������
			//printf("right ");
			curr.right();
			s_maze.push(curr);
			maze[curr.x][curr.y] = '#';
			if (curr.is_same(out))
				break;
			continue;
		}
		else { //���������� ���� curr�� ���� stack top �� curr
			if (curr.is_same(out))
				break;

			//printf("%d left || back: " ,s_maze.n);
			//curr.print();
			
			maze[curr.x][curr.y] = 'x';
			s_maze.pop();
			curr = s_maze.Top();
			
		}
	} while ((s_maze.is_empty()) != 1);

	if (s_maze.is_empty())
		printf("No exit\n");		

	//    �̵��Ҷ�������ġ��stack������
	//    �ⱸ�������ϸ�break
	// 2. ���̻������Ҽ�������б������εǵ��ư���
	//    �̵��Ҽ��ִ���ġ���ö�����stack pop }
	// 2. �̷����: stack���������ġ����� 

}

int main() {
	FILE *fp = fopen("maze.txt", "r+t");
	load_maze(fp);
	print_maze();
	solve_maze();
	print_maze();
	fclose(fp);
	system("pause"); 
	return 0;
}