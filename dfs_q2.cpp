#include <iostream>
#include <vector>

using namespace std;
int graph[1001][1001];
int m, n, w;

bool dfs(int x, int y) {
	//범위를 초과하는지 먼저 테스트
	if (x<0 || x>=n || y<0 || y>= m) {
		return false;
	}
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;

}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> w;
			graph[i][j] = w;
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	printf("%d", result);
	return 0;
}