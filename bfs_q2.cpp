//미로탈출
/*직사각형 NxM 크기의 미로가 있다.
이동할 수 있는 곳의 값은 1 이동불가는 0
내 위치 1,1에서부터 출구인 N,M까지의 최단거리는 몇인가?
최단거리 : BFS - queue로 풀기*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue <pair<int, int>>q;
int graph[201][201] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M, x;

int bfs(int x, int y) {
	q.push({x, y});//큐에넣는다
	while (!q.empty()) { //큐가 빌때까지 계속한다.
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { //4방향 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (graph[nx][ny]==0)
				continue;
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return graph[N - 1][M - 1];
}


int main() {
	cin >> N >> M;
	for (int i=0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x;
			graph[i][j] = x ;
		}
	}
	cout << bfs(0, 0) << endl;
	return 0;
}