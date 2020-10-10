//연결요소를 찾는 문제
//dfs로 접근한다.

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> a[MAX];
int visit[MAX];
int count = 0;

void dfs(int x) {
	if (visit[x]) return;

	visit[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int z = a[x][i];
		dfs(z);
	}
}

int main() {
	int N, M, u, v;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}