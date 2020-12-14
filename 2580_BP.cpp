//������ �ϼ��ϸ� �ȴ�.
//������, ������, �׸�ĭ�� 1~9 �ϳ��� ���ߵȴ�.
// map�� ���� ���η� ���°� ��� ��� 3x3 ������ ������������ ���. ���ڿ�?
// ��Ʈ��ŷ���� Ǯ����ϳ�
// ��Ī �˰������� Ǯ��ߵɰŰ���. ���� �ڿ����� ���ڸ��� �װŹۿ� �ȵ��µ�
// �տ����� �ٲ��� �� �ִ��� �׷��ٸ� �ٲٴ� Ȯ�����ִ°� �ʿ��ϴ�.

#define MAX 9

#include <iostream>

using namespace std;

int map[MAX][MAX];

int r[10] = { 0, };
int c[10] = { 0, };
int sq[10] = { 0, };

//����üũ�ϴ� �Լ�

int check(int row, int col){
	int rr=0, cc=0, sqsq=0;
	int nr = row / 3;
	int nc = col / 3;
	int sqrstart;
	int sqrend;
	int sqcstart;
	int sqcend;
	for (int i = 0; i < MAX; i++) {
		if (map[row][i] != 0) {
			r[map[row][i]] = 1;
		}
		if (map[row][i]==0){
			rr++;
		}
		if (map[i][col] != 0) {
			c[map[i][col]] = 1;
		}
		if (map[i][col] == 0) {
			cc++;
		}
	}
	if (nr == 0 && nc == 0) {
		sqrstart = 0; sqrend = 2; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 0 && nc == 1) {
		sqrstart = 0; sqrend = 2; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 0 && nc == 2) {
		sqrstart = 0; sqrend = 2; sqcstart = 6; sqcend = 8;
	}
	else if (nr == 1 && nc == 0) {
		sqrstart = 3; sqrend = 5; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 1 && nc == 1) {
		sqrstart = 3; sqrend = 5; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 1 && nc == 2) {
		sqrstart = 3; sqrend = 5; sqcstart = 6; sqcend = 8;
	}
	else if (nr == 2 && nc == 0) {
		sqrstart = 6; sqrend = 8; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 2 && nc == 1) {
		sqrstart = 6; sqrend = 8; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 2 && nc == 2) {
		sqrstart = 6; sqrend = 8; sqcstart = 6; sqcend = 8;
	}
	for (int i = sqrstart; i <= sqrend; i++) {
		for (int j = sqcstart; j <= sqcend; j++) {
			if (map[i][j] == 0)
				sqsq++;
			if (map[i][j] != 0) {
				sq[map[i][j]] = 1;
			}
		}
	}
	//�����غ�Ϸ�
	if (rr == 1) {
		return 1;
	}
	if (cc == 1) {
		return 2;
	}
	if (sqsq == 1) {
		return 3;
	}
	else
		return 0;
}

int sudoku(int i,int j) {
	//�� ���� ���� ���� Ž���ؼ� 0�� �ϳ��ΰ� ������ ��� ������ �� ���� Ȯ������
	int result = check(i, j);
	if(result==1){
		for (int a = 1; a < 10; a++) {
			if (r[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	else if (result == 2) {
		for (int a = 1; a < 10; a++) {
			if (c[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	else if (result == 3) {
		for (int a = 1; a < 10; a++) {
			if (sq[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	//�� ���� ��� 0�� �ϳ��� ������ �ƴ϶��? �ٸ� 0�� �ֵ��� ���� ���ߵɵ�
	else {// ���� ������ �𸣰ڴ�..
		sudoku(i + 1, j + 1);
	}
}

int main() {

	//�Է����ֱ�
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
		}
	}

	//dfs ��Ʈ��ŷ �����ֱ�
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] == 0) {
				sudoku(i, j);
			}
		}
	}

	//�Ϸ�Ȱ� ������ֱ�
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%d", map[i][j]);
		}
	}
	return 0;
}

