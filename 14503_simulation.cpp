/*
#include <iostream>

using namespace std;

int map[51][51] = { 0, };// 방문한곳을 1로바꾸면 곧 visit
int cnt = 0;

void cleaner(int x, int y, int d) {
	//주위가 다막힐때까지 반복한다
	while (1) { 
		if (map[x][y] == 0) {
			map[x][y] = 2;
			cnt++;
		}
		
		if (d == 0) {
			if ((map[x + 1][y] == 1) && map[x - 1][y] && map[x][y - 1] && map[x][y + 1]) { //뒤가 확실히 벽
				break;
			}
			else if (map[x + 1][y] && map[x - 1][y] && map[x][y - 1] && map[x][y + 1]) { //후진가능
				x++; //다 1,2이지만 뒤가 벽(1)이 아니라면 후진한다.
			}
			else if(map[x][y-1]) { //서쪽에 청소공간없다면
				d = 3;// 서쪽으로 회전
				//2번으로 돌아간다?? continue?
			}
			else if (map[x][y - 1] == 0) { //서쪽에 청소공간이있다면
				d = 3; //서쪽으로 회전
				y--; //서쪽으로 한칸 전진
				continue; //break와 continue의 차이 break는 반복문을 탈출하지만 continue는 반복문 처음으로돌아감
			}
		}
		else if (d == 1) {
			if (map[x + 1][y] && map[x - 1][y] && (map[x][y - 1] == 1) && map[x][y + 1]) { //뒤가 확실히 벽
				break;
			}
			else if (map[x + 1][y] && map[x - 1][y] && map[x][y - 1] && map[x][y + 1]) { //후진가능
				y--; //뒤가 벽(1)이 아니라면 후진한다.
			}
			else if (map[x - 1][y]) { //서쪽에 청소공간없다면
				d = 0;// 서쪽으로 회전
				//2번으로 돌아간다?? continue?
			}
			else if (map[x-1][y] == 0) { //서쪽에 청소공간이있다면
				d = 0; //서쪽으로 회전
				x--; //서쪽으로 한칸 전진
				continue; //break와 continue의 차이 break는 반복문을 탈출하지만 continue는 반복문 처음으로돌아감
			}


		}
		else if (d == 2) {
			if (map[x + 1][y] && (map[x - 1][y] == 1) && map[x][y - 1] && map[x][y + 1]) { //뒤가 확실히 벽
				break;
			}
			else if (map[x + 1][y] && map[x - 1][y] && map[x][y - 1] && map[x][y + 1]) { //후진가능
				x--; //뒤가 벽(1)이 아니라면 후진한다.
			}
			else if (map[x][y + 1]) { //서쪽에 청소공간없다면
				d = 1;// 서쪽으로 회전
				//2번으로 돌아간다?? continue?
			}
			else if (map[x][y+1] == 0) { //서쪽에 청소공간이있다면
				d = 1; //서쪽으로 회전
				y++; //서쪽으로 한칸 전진
				continue; //break와 continue의 차이 break는 반복문을 탈출하지만 continue는 반복문 처음으로돌아감
			}


		}
		else {
			if (map[x + 1][y] && map[x - 1][y] && map[x][y - 1] && (map[x][y + 1] == 1)) { //뒤가 확실히 벽
			break;
			}
			else if (map[x + 1][y] && map[x - 1][y] && map[x][y - 1] && map[x][y + 1]) { //후진가능
			y++; //뒤가 벽(1)이 아니라면 후진한다.
			}
			else if (map[x+1][y]) { //서쪽에 청소공간없다면
			d = 2;// 서쪽으로 회전
			//2번으로 돌아간다?? continue?
			}
			else if (map[x+1][y] == 0) { //서쪽에 청소공간이있다면
				d = 2; //서쪽으로 회전
				x++; //서쪽으로 한칸 전진
				continue; //break와 continue의 차이 break는 반복문을 탈출하지만 continue는 반복문 처음으로돌아감
			}

			
		}
	}
}


보는 방향에 따른 이동
d= 
0(바라보고있는 위치가 북) :앞(-1,0) 오른(0,1) 뒤(1,0) 왼(0,-1)
1(바라보고있는 위치가 동) :앞(0,1) 오른(1,0) 뒤(0,-1) 왼(-1,0) 
2(바라보고있는 위치가 남) :앞(1,0) 오른(0,-1) 뒤(-1,0) 왼(0,1)
3(바라보고있는 위치가 서) :앞(0,-1) 오른(-1,0) 뒤(0,1) 왼(1,0)

int main() {
	int N, M;
	cin >> N >> M;
	int r, c, d; //로봇청소기의 좌표, 바라보고있는방향
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) { //가로
		for (int j = 0; j < M; j++) { //세로
			cin >> map[i][j];
		}
	}

	cleaner(r, c, d);
	cout << cnt << endl;
	return 0;
}

*/


//dfs로 풀기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int n, m, cnt = 0;
int map[50][50];

int nexty[4] = { -1, 0, 1, 0 };
int nextx[4] = { 0, 1, 0, -1 };

int backy[4] = { 1, 0, -1, 0 };
int backx[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int d) {
	int k;

	if (map[y][x] == 0) {
		cnt++;
		map[y][x] = 2;
	}

	for (k = d - 1; k > d - 5; k--) {

		int newk = (k + 4) % 4;
		int newy = y + nexty[newk];
		int newx = x + nextx[newk];

		if (newy < 0 || newy > n - 1 || newx < 0 || newx > m - 1) continue;

		if (map[newy][newx] == 0) {
			dfs(newy, newx, newk);
			return;
		}
	}

	if (map[y + backy[d]][x + backx[d]] == 1) return;
	else dfs(y + backy[d], x + backx[d], d);
}

int main() {

	int r, c, d, i, j;

	freopen("test.txt", "r", stdin);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(r, c, d);

	printf("%d\n", cnt);

	return 0;
}