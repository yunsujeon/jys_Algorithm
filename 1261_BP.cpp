/*
#include <iostream>
#include <queue>

using namespace std;
const int MAX = 100;

int M, N;
int graph[MAX][MAX];
int dx[] = {-1, 1, 0, 0};//열이바뀌는거
int dy[] = {0, 0, -1, 1};//행이바뀌는거
int minimum = 987654321;
int visited[MAX][MAX] = { 0, };

void bfs(int n, int m) { //가로 세로(행 열)
	queue <pair<pair<int,int>,int>> q; //큐에 ((가로, 세로) 벽부신횟수) 넣기
	q.push({ {n,m},0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int broken = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M &&!visited[ny][nx]) { //범위가맞으면
				if (ny==N-1 && nx==M-1) { //끝점에 다다르면 (끝점엔 벽이없다)
					if (minimum >= broken) {
						minimum = broken;
					}
				}
				if (graph[ny][nx]==0) { //벽을 부수지않고 진행했을때
					q.push({ {ny,nx},broken });
				}
				else if (graph[ny][nx]==1) { //부수고 진행했을때
					q.push({ {ny,nx},broken + 1 });
				}
				visited[ny][nx] = true;
			}
		}
	}
}


int main() {
	cin >> M >> N;//M:열의 크기 N:행의크기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	bfs(0, 0);
	cout << minimum << endl;
	return 0;
}
*/




#include <iostream>
#include <deque>

using namespace std;
const int MAX = 100;

int M, N;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int broken;

//담는 여러가지 방법에 대해 얘기해보자

//덱 - pair로 두개로 묶는방법
//덱 - tuple로 한번에 묶는방법
//덱 - struct로 묶는방법


void bfs() {
	deque<pair<pair<int,int>,int>> deq; //x좌표, y좌표, 부순횟수
	deq.push_back({ {0,0},0 });
	visited[0][0] = 1;
	while (!deq.empty()) {
		int x = deq.front().first.first;
		int y = deq.front().first.second;
		broken = deq.front().second;
		deq.pop_front(); //다뽑고 pop한다.
		if (x == N - 1 && y == M - 1) {
			return;
		}
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx >= N || newx < 0 || newy >= M || newy < 0)
				continue;
			if (visited[newx][newy])
				continue;
			visited[newx][newy] = 1;
			if (graph[newx][newy])
				deq.push_back({ {newx,newy},broken + 1 });
			else
				deq.push_front({ {newx,newy},broken });
		}
	}
	return;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	bfs();
	cout << broken << endl;
	return 0;
}