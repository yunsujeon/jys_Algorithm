//연구소 3

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
vector <pair<int, int>> v;
int map[51][51] = { 0, };
int N, M;
int dr[] = { -1,0,1,0 };//상우하좌
int dc[] = { 0,1,0,-1 };
int MIN = 987654321;

int bfs(int copy[][51],int x1,int x2, int x3, int y1, int y2, int y3) { //2차원배열 매개변수
	int visit[51][51] = { 0, };
	queue <pair<int, int>>q;
	q.push({ x1, y1 });
	q.push({ x2, y2 });
	q.push({ x3, y3 });
	visit[x1][y1] = true;
	visit[x2][y2] = true;
	visit[x3][y3] = true; //방문체크
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (visit[nr][nc] == 0 && copy[nr][nc] != 1) {
					visit[nr][nc] = 1;
					q.push({ nr,nc });				
				}
			}
		}
	}
	return cnt;
}

int solution() {
	int res = 0;
	int copy[51][51] = { 0, };

	/* 문제점! 활성바이러스 갯수를 3개로 한정했다. 최대 10개까지로 유동적이다
	int x1, y1, x2, y2, x3, y3;

	memcpy(copy, map, sizeof(map)); //배열 복사
	for (int i = 0; i < v.size()-2; i++) {
		x1 = v[i].first;
		y1 = v[i].second;
		for (int j = i + 1; j < v.size()-1; j++) {
			x2 = v[j].first;
			y2 = v[j].second;
			for (int k = j + 1; k < v.size(); k++) {
				x3 = v[k].first;
				y3 = v[k].second;
				copy[x1][y1] = 3;//활성
				copy[x2][y2] = 3;//활성
				copy[x3][y3] = 3;//활성
				//수행내용 - 활성, 비활성의 copymap을 가지고 bfs로 최소를 구해낸다.
				res = bfs(copy,x1,x2,x3,y1,y2,y3);
				if (res <= MIN) {
					MIN = res;
				}
				copy[x3][y3] = 2; //되돌려주기
			}
			copy[x2][y2] = 2; //되돌려주기
		}
		copy[x1][x1] = 2; //되돌려주기
	}
	*/
	return res;
}

int main() {
	int input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			map[i][j] = input;
			if (input == 2) {//virus input 이라면
				v.push_back({ i,j });
			}
		}
	}
	cout << solution() << '\n';
	return 0;
}