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
int MAX = 0;
int Xs[11] = { 0, };
int Ys[11] = { 0, };

int bfs(int copy[][51],int X[], int Y[]) { //2차원배열 매개변수
	int visit[51][51] = { 0, };
	queue<pair<pair<int, int>, int>>q;
	for (int i = 0; i < M; i++) {
		q.push({{ X[i],Y[i] }, 0});
		visit[X[i]][Y[i]] = true;
	}
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		if (cnt > MAX) {
			MAX = cnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (visit[nr][nc] == 0 && copy[nr][nc] != 1) {
					visit[nr][nc] = 1;
					q.push({ { nr,nc },cnt++ });
				}
			}
		}
	}
	return MAX;
}

int solution() {
	int res = 0;
	int copy[51][51] = { 0, };
	int c = v.size();
	int start = 0;
	do {

		for (int i = 0; i < M; i++) {
			Xs[i] = v[i].first;
			Ys[i] = v[i].second;
			copy[Xs[i]][Ys[i]] = 3;
		}
		
		res = bfs(copy, Xs, Ys);
		if (res <= MIN) {
			MIN = res;
		}

		for (int i = 0; i < M; i++) {
			copy[Xs[i]][Ys[i]] = 2;
		}

	} while (next_permutation(v.begin(), v.end()));
	
	return MIN;
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