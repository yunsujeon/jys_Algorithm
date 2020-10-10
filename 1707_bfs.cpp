//이분그래프 bfs dfs 다 풀어볼수있다.
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 20001

using namespace std;

vector <int> v[MAX];
int visit[MAX]; //여기다가 0,1 뿐만이아니라 방문X:0 빨강:1 파랑:2 로 표시
int result;
int K, V, E;

void bfs(int x, int y) {
	queue <int> q;
	visit[x] = y; //RED로 초기화
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (visit[z] == 0) {
				if (visit[x] == 1) {
					visit[z] = 2;
					q.push(z);
				}
				else if (visit[x] == 2) {
					visit[z] = 1;
					q.push(z);
				}
			}
		}
	}
}

bool isBipartiteGraph() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < v[i].size(); j++) { //빠져나온 후 모든경우에 대해 탐색
			int z = v[i][j];
			if (visit[i] == visit[z]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int re;

	cin >> K;
	for (int i = 0; i < K; i++) {

		cin >> V >> E;//노드의 수 , 간선의 수

		for (int i = 0; i < E; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= V; i++) { //노드 를 살펴본다.
			if (visit[i] == 0) { //색이 칠해져있지 않은 노드만 따져본다.
				bfs(i, 1); //빨간색:1 부터 칠하고 시작한다.
			}
		}

		if (isBipartiteGraph()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		for (int i = 0; i < MAX; i++) {
			v[i].clear(); //한번 수행후엔 벡터를 다 비워줘야 함
		}
		memset(visit, 0, sizeof(visit)); //방문, 색 나타낸 배열도 비워주기
	}
	return 0;
}