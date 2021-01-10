//격자의 밖으로 나간 모래의 양을 출력한다.

#include <iostream>

using namespace std;

int N;
int map[504][504];
int temp;
int dir, r, c;
int cnt = 0;
int go;

void move(int dir,int r,int c) { 

	if ((dir == 1)&& (c>2)) { //좌로이동
		cnt++;
		for (int i = 0; i < cnt; i++) {
			if (r == 2 && c == 2) //끝에 다다르면 return 한다. 0,1은 빈 스페이스로 나둠
				return;
			int y = map[r][c - 1]; //y지점은 0이되고 이 지점에있는
			int re = y / 100;
			map[r][c - 1] = 0;
			map[r][c - 2] = map[r][c - 2] + re * 55; //a 는 55%가 아니다.. 남은 모래 전부 다이다..!!!!!!
			map[r][c - 3] = map[r][c - 3] + re * 5;
			map[r - 1][c] = map[r - 1][c] + re * 1;
			map[r - 1][c - 1] = map[r - 1][c - 1] + re * 7;
			map[r - 1][c - 2] = map[r - 1][c - 2] + re * 10;
			map[r - 2][c - 1] = map[r - 2][c - 1] + re * 2;
			map[r + 1][c] = map[r + 1][c] + re * 1;
			map[r + 1][c - 1] = map[r + 1][c - 1] + re * 7;
			map[r + 1][c - 2] = map[r + 1][c - 2] + re * 10;
			map[r + 2][c - 1] = map[r + 2][c - 1] + re * 2;
			c--;//한번 진행했으니 c가 줄어들것
		}
		dir = 2;
		move(dir, r, c);
	}

	else if ((dir == 2) && (r < N + 2)) { //하로이동
		for (int i = 0; i < cnt; i++) {
			int y = map[r + 1][c]; //y지점은 0이되고 이 지점에있는
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
	else if ((dir == 3) && (c < N+2)) { //우로이동
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
			c++;//한번 진행했으니 c가 줄어들것
		}
		dir = 4;
		move(dir, r, c);
	}
	else if ((dir == 4) && (r > 2)) { //상으로이동
		for (int i = 0; i < cnt; i++) {
			int y = map[r - 1][c]; //y지점은 0이되고 이 지점에있는
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

	dir = 1; //시작방향 '좌'
	r = ((N + 2) / 2) + 1;
	c = ((N + 2) / 2) + 1; //중앙 점
	move(dir, r, c);
	int result = sum_move();
	printf("%d", result);

	return 0;
}