//연구소 3

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;
vector <pair<int, int>> v;
vector <int> temp;
int map[51][51] = { 0, };
int N, M;
int dr[] = { -1,0,1,0 };//상우하좌
int dc[] = { 0,1,0,-1 };
int MIN = 987654321;
int MAX = 0;
int MIN2=987654321;
int Xs[11] = { 0, };
int Ys[11] = { 0, };


struct compare {
	bool operator()(pair<pair<int, int>, int >a, pair<pair<int, int>, int >b) {
		return a.second > b.second;
	}
};

int bfs(int copy[][51],int X[], int Y[]) { //2차원배열 매개변수
	int visit[51][51] = { 0, };
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare >q;
	int cnt = 0;
	int re = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < M; i++) {
		q.push({{ X[i],Y[i] }, 0});
		visit[X[i]][Y[i]] = true; //방문처리
	}
	while (!q.empty()) {
		int r = q.top().first.first;
		int c = q.top().first.second;
		cnt = q.top().second;
		q.pop();
		for (int i = 0; i < 4; i++) { //4방향을 탐색한다.
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N) { //범위만족
				if (visit[nr][nc] == 0 && copy[nr][nc] != 1) { //방문 및 벽
					visit[nr][nc] = 1;
					if (copy[nr][nc] == 2) {//비활성된 바이러스라면
						q.push({ {nr,nc},cnt });
					}
					else {
						q.push({ { nr,nc },cnt + 1 }); //큐에삽입하여 bfs
					}
				}
			}
		}
	}
	re = cnt;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0 && copy[i][j] != 1) //방문하지 않은곳중에 벽이아닌곳이있다면
				re = -1;
		}
	}
	return re;
}

int solution() {
	int res = 0;
	int start = 0;
	temp.resize(v.size()); //인덱스를 나타 낼 temp
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		temp[i] = 1;
	}
	sort(temp.begin(), temp.end());

	do {
		int ct = 0;
		for (int i = 0; i < v.size(); i++) {
			if (temp[i] == 1) {
				Xs[ct] = v[i].first;
				Ys[ct] = v[i].second;
				map[Xs[ct]][Ys[ct]] = 3;
				ct++;
			}
		}
		res = bfs(map, Xs, Ys);
		if (res <= MIN&&res!=-1) {//MIN보다 작고 -1이 아니라면 MIN 갱신해
			MIN = res;
		}
		for (int i = 0; i < v.size(); i++) {
			if (temp[i] == 1) {
				Xs[ct] = v[i].first;
				Ys[ct] = v[i].second;
				map[Xs[ct]][Ys[ct]] = 2;
				ct++;
			}
		}

	} while (next_permutation(temp.begin(), temp.end()));

	if (MIN == 987654321) {
		return -1;
	}
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


