//경쟁적전염
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int visit[201][201];
int d[201][201];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0,0,-1,1 };
vector < pair <int, int>>v[201];
queue<tuple<int, int, int> > q;

int n, k;
int s, x, y;

void bfs() {

	for (int i = 1; i <= k; i++) {
		if (!v[i].empty()) { //즉 v에는 1 2 3 순으로 들어가있다. 이를 큐에 넣어주고 방문처리 해주면 될것이다.
			q.push(make_tuple(i, v[i].front().first, v[i].front().second));
			visit[v[i].front().first][v[i].front().second] = 1; //바이러스가 들어있는 곳은 다 방문처리를 해준다.
		}
	}

	while (!q.empty()&& s--) { //총 반복해야 할 수와 q가 비는것
		int qs = q.size();

		while (qs--) { //한번 돌때 큐 사이즈만큼은 반복해줘야됨. 1 2 3 다 증폭시켜줘야되니깐
			int num, x, y;
			tie(num, x, y) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) { //pop 한 큐에 대해서 4방향을 탐색해준다
				int ex = x + dx[i];
				int ey = y + dy[i];
				if (ex < 1 || ex>3 || ey < 1 || ey>3 || visit[ex][ey]) {
					continue;
				}
				d[ex][ey] = num;
				visit[ex][ey] = true;
				q.push(make_tuple(num, ex, ey));
			}
		}
	}
}



int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n; j++) {
			cin >> d[i][j]; //배열에 다 넣고
			if (d[i][j]) { //0이 아닌애들만으로 벡터를 만든다.
				v[d[i][j]].push_back(make_pair( i, j ));
			}
		}
	}
	cin >> s >> x >> y; // 2 3 2
	bfs();
	printf("%d\n", d[x][y]);
	return 0;
}
