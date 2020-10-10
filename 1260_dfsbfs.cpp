#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, M, V;
vector<int>v[1001];
queue<int> q;
int d1[MAX];
int d2[MAX];

void dfs(int start) { //재귀
	if (d1[start]) return;

	d1[start] = true;
	printf("%d ", start);
	for (int i = 0; i < v[start].size(); i++) {
		int j = v[start][i];
		dfs(j);
	}
}

void bfs(int start) { //큐가 빌때까지반복
	q.push(start);
	d2[start] = true;
	while (!q.empty()) {
		int x = q.front();
		printf("%d ", x);
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (!d2[z]) {
				d2[z] = true;
				q.push(z);
			}
		}
	}
}

int main() {
	int x, y;
	cin >> N >> M >> V; //정점의 개수, 간선의 개수, 시작할정점번호
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y); //간선
		v[y].push_back(x); //서로연결
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);
	return 0;
}