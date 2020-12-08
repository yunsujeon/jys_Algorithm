#define MAX 20
#include <iostream>

using namespace std;

int n, m, x, y, k;
int dir;
int graph[MAX][MAX];
int state[7] = { 0, }; //주사위 면 6개지만 1~6으로 쓰려고 크기 7로잡음

void move(int dir) {
	if (dir == 1) {
		int empty = 0;
		if (y+1 >= m) { //이동시 범위만족
			return;
		}
		else {
			if (graph[x][y + 1] == 0)
				graph[x][y + 1] = state[3];
			else {
				state[3] = graph[x][y + 1];
				graph[x][y + 1] = 0;
			}
			empty = state[1];
			state[1] = state[4];
			state[4] = state[6];
			state[6] = state[3];
			state[3] = empty;
			y = y + 1;
			printf("%d\n", state[1]);
		}
	}
	else if (dir == 2) {
		int empty = 0;
		if ( y-1<0) { //이동시 범위만족
			return;
		}
		else {
			if (graph[x][y - 1] == 0)
				graph[x][y - 1] = state[4];
			else {
				state[4] = graph[x][y - 1];
				graph[x][y - 1] = 0;
			}
			empty = state[1];
			state[1] = state[3];
			state[3] = state[6];
			state[6] = state[4];
			state[4] = empty;
			y = y - 1;
			printf("%d\n", state[1]);
		}
	}
	else if (dir == 3) {
		int empty = 0;
		if (x-1 < 0) { //이동시 범위만족
			return;
		}
		else {
			if (graph[x - 1][y] == 0)
				graph[x - 1][y] = state[2];
			else {
				state[2] = graph[x - 1][y];
				graph[x - 1][y] = 0;
			}
			empty = state[1];
			state[1] = state[5];
			state[5] = state[6];
			state[6] = state[2];
			state[2] = empty;
			x = x - 1;
			printf("%d\n", state[1]);
		}
	}
	else if (dir == 4) {
		int empty = 0;
		if (x+1 >= n) { //이동시 범위만족
			return;
		}
		else {
			if (graph[x + 1][y] == 0)
				graph[x + 1][y] = state[5];
			else {
				state[5] = graph[x + 1][y];
				graph[x + 1][y] = 0;
			}
			empty = state[1];
			state[1] = state[2];
			state[2] = state[6];
			state[6] = state[5];
			state[5] = empty;
			x = x + 1;
			printf("%d\n", state[1]);
		}
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0;i < n; i++) {
		for (int j = 0;j < m;j++) {
			cin >> graph[i][j];
		}
	}
	while (k) {
		cin >> dir;
		move(dir);
		k--;
	}
}