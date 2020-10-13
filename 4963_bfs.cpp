#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 50
using namespace std;

int graph[MAX][MAX];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1 ,-1,0,1 };
int visit[MAX][MAX];
int cnt;
int X, Y, s;

void bfs(int x, int y) {
	queue <pair<int,int>> q;
	visit[x][y] = true;
	q.push({x,y});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ex = x + dx[i];
			int ey = y + dy[i];
			if (!visit[ex][ey] && graph[ex][ey] && ex>=0 && ex<X && ey>=0 && ey<Y) {
				visit[ex][ey] = true;
				q.push({ex, ey});
			}
			
		}
	}
	cnt++;
}

int main() {
	while (1) {
		cnt = 0;
		memset(visit, false, sizeof(visit));
		memset(graph, false, sizeof(visit));

		cin >> Y >> X;
		if (Y==0 && X==0) {
			break;
		}
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cin >> graph[i][j];
			}
		}
		cnt = 0;
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if (!visit[i][j]&&graph[i][j]) {
					bfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}