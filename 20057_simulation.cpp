//������ ������ ���� ���� ���� ����Ѵ�.

#include <iostream>

using namespace std;

int N;
int map[504][504];
int temp;
int dir, r, c;
int cnt = 0;
int go;

void move(int dir,int r,int c) { 

	if ((dir == 1)&& (c>2)) { //�·��̵�
		cnt++;
		for (int i = 0; i < cnt; i++) {
			if (r == 2 && c == 2) //���� �ٴٸ��� return �Ѵ�. 0,1�� �� �����̽��� ����
				return;
			int y = map[r][c - 1]; //y������ 0�̵ǰ� �� �������ִ�
			int re = y / 100;
			map[r][c - 1] = 0;
			map[r][c - 2] = map[r][c - 2] + re * 55; //a �� 55%�� �ƴϴ�.. ���� �� ���� ���̴�..!!!!!!
			map[r][c - 3] = map[r][c - 3] + re * 5;
			map[r - 1][c] = map[r - 1][c] + re * 1;
			map[r - 1][c - 1] = map[r - 1][c - 1] + re * 7;
			map[r - 1][c - 2] = map[r - 1][c - 2] + re * 10;
			map[r - 2][c - 1] = map[r - 2][c - 1] + re * 2;
			map[r + 1][c] = map[r + 1][c] + re * 1;
			map[r + 1][c - 1] = map[r + 1][c - 1] + re * 7;
			map[r + 1][c - 2] = map[r + 1][c - 2] + re * 10;
			map[r + 2][c - 1] = map[r + 2][c - 1] + re * 2;
			c--;//�ѹ� ���������� c�� �پ���
		}
		dir = 2;
		move(dir, r, c);
	}

	else if ((dir == 2) && (r < N + 2)) { //�Ϸ��̵�
		for (int i = 0; i < cnt; i++) {
			int y = map[r + 1][c]; //y������ 0�̵ǰ� �� �������ִ�
			int re = y / 100;
			map[r + 1][c] = 0;
			map[r + 2][c] = map[r + 2][c] + re * 55;
			map[r + 3][c] = map[r + 3][c] + re * 5;
			map[r][c - 1] = map[r][c - 1] + re * 1;
			map[r + 1][c - 1] = map[r + 1][c - 1] + re * 7;
			map[r + 2][c - 1] = map[r + 2][c - 1] + re * 10;
			map[r + 1][c - 2] = map[r + 1][c - 2] + re * 2;
			map[r][c + 1] = map[r][c + 1] + re * 1;
			map[r + 1][c + 1] = map[r + 1][c + 1] + re * 7;
			map[r + 2][c + 1] = map[r + 2][c + 1] + re * 10;
			map[r + 1][c + 2] = map[r + 1][c + 2] + re * 2;
			r++;
		}
		dir = 3;
		move(dir, r, c);
	}
	else if ((dir == 3) && (c < N+2)) { //����̵�
		cnt++;
		for (int i = 0; i < cnt; i++) {
			int y = map[r][c + 1];
			int re = y / 100;
			map[r][c + 1] = 0;
			map[r][c + 2] = map[r][c + 2] + re * 55;
			map[r][c + 3] = map[r][c + 3] + re * 5;
			map[r - 1][c] = map[r - 1][c] + re * 1;
			map[r - 1][c + 1] = map[r - 1][c + 1] + re * 7;
			map[r - 1][c + 2] = map[r - 1][c + 2] + re * 10;
			map[r - 2][c + 1] = map[r - 2][c + 1] + re * 2;
			map[r + 1][c] = map[r + 1][c] + re * 1;
			map[r + 1][c + 1] = map[r + 1][c + 1] + re * 7;
			map[r + 1][c + 2] = map[r + 1][c + 2] + re * 10;
			map[r + 2][c + 1] = map[r + 2][c + 1] + re * 2;
			c++;//�ѹ� ���������� c�� �پ���
		}
		dir = 4;
		move(dir, r, c);
	}
	else if ((dir == 4) && (r > 2)) { //�������̵�
		for (int i = 0; i < cnt; i++) {
			int y = map[r - 1][c]; //y������ 0�̵ǰ� �� �������ִ�
			int re = y / 100;
			map[r - 1][c] = 0;
			map[r - 2][c] = map[r - 2][c] + re * 55;
			map[r - 3][c] = map[r - 3][c] + re * 5;
			map[r][c - 1] = map[r][c - 1] + re * 1;
			map[r - 1][c - 1] = map[r - 1][c - 1] + re * 7;
			map[r - 2][c - 1] = map[r - 2][c - 1] + re * 10;
			map[r - 1][c - 2] = map[r - 1][c - 2] + re * 2;
			map[r][c + 1] = map[r][c + 1] + re * 1;
			map[r - 1][c + 1] = map[r - 1][c + 1] + re * 7;
			map[r - 2][c + 1] = map[r - 2][c + 1] + re * 10;
			map[r - 1][c + 2] = map[r - 1][c + 2] + re * 2;
			r--;
		}
		dir = 1;
		move(dir, r, c);
	}
}
int sum_move() {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < N+4; i++) {
		for (int j = 0; j < N+4; j++) {
			sum1 += map[i][j];
		}
	}
	for (int i = 2; i < N+2 ; i++) {
		for (int j = 2; j < N+2; j++) {
			sum2 += map[i][j];
		}
	}
	return sum1 - sum2;
}

int main() {
	cin >> N;
	for (int i = 2; i < N+2; i++) {
		for (int j = 2; j < N+2; j++) {
			cin >> map[i][j];
		}
	}

	dir = 1; //���۹��� '��'
	r = ((N + 2) / 2) + 1;
	c = ((N + 2) / 2) + 1; //�߾� ��
	move(dir, r, c);
	int result = sum_move();
	printf("%d", result);

	return 0;
}