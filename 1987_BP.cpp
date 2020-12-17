#define MAX 20
#include <iostream>
#include <algorithm>
//#include <queue>
//#include <set>

using namespace std;

int R, C;
char map[MAX][MAX];


int dx[] = { 1, 0, -1, 0 }; //우 하 좌 상 순서
int dy[] = { 0, 1, 0, -1 };
bool visit[26] = { 0, }; //알파벳 갯수 26
int ans = 0;

/* //bfs로 풀어보려다 visit 에서 막힘

int bfs(int y, int x) {
	queue < pair < pair <int, int>, int >> q; //좌표와 카운트
	set <char> visit;
	q.push({ { y,x }, 0 });
	visit.insert(map[y][x]); //set에 map의 숫자가 들어갔다.
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { //4방향 탐색하겠다.
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < C && ny < R) { //범위조건
				if (visit.find(map[ny][nx]) == visit.end()) { //같은 문자가 안에 없다면
					q.push({ { ny,nx }, cnt + 1 });
					visit.insert(map[ny][nx]);
				}
			}
		}
	}
}
*/



void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) { //네방향 보면서
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) { //범위조건
			if (visit[map[ny][nx]-'A'] == false) { //그 알파벳을 안밟았다면
				visit[map[ny][nx] - 'A'] = true; //방문체크
				dfs(ny, nx, cnt+1);
				visit[map[ny][nx] - 'A'] = false; //백트래킹 한다. 다시밟을수있게
			}	
		}
	}
}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	//bfs(0, 0);
	visit[map[0][0]-'A'] = true; //'A'-'A'=0 이다. 체크하고dfs로 들어갈것이다.
	dfs(0, 0, 1);

	cout << ans << endl;

	return 0;
}