//dfs에서 한 가지에서 뻗어나가는 개체들을 모두 같게 생각
//이를 위해서 pari<pair<>>를 사용. 묶어버리기위해
//최단경로는 dfs보다 bfs를 먼저 생각해보자

#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
using namespace std;

int graph[MAX][MAX] = { 0, };
int visit[MAX][MAX] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 }; //하 우 상 좌 순서로 움직이게 함 상관은없음
int Y, X, s;

int bfs(int x, int y, int cnt) {
	queue <pair <pair <int, int>, int>> q;
	q.push({{ x, y }, cnt});
	visit[x][y] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;
		q.pop();

		if (x == X-1 && y == Y-1) 
			return cnt;

		for (int i = 0; i < 4; i++) {
			int ex = x + dx[i];
			int ey = y + dy[i];
			if (ex < 0 || ex >= X || ey < 0 || ey >= Y)
				continue;

			if (!visit[ex][ey] && graph[ex][ey]) {
				visit[ex][ey] = true;
				q.push({{ ex,ey }, cnt + 1});
			}
		}
	}
}


int main(){
	cin >> X >> Y;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			scanf_s("%1d", &s); //글자를 하나씩 읽어온다.
			graph[i][j] = s;
		}
	}
	cout << bfs(0,0,1) << endl;

}

