//순열사이클
//-> 몇 개의 사이클이 존재하는지 출력해야한다.
//몇 번의 테스트케이스를 한번에 테스트 하니 초기화가 필요하다.
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1001
using namespace std;

vector <int> v[MAX];
int visit[MAX];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visit[x] = true;
	while (!q.empty()) {
		int ex = q.front();
		q.pop();
		for (int i = 0; i < v[ex].size(); i++) {
			int z = v[ex][i];
			if (visit[z] == 0) {
				visit[z] = true;
				q.push(z);
			}
			else if (z == x) {
				visit[z] = true;
			}
		}
	}
}

int main() {
	int T, N;
	int count=0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			int x;
			cin >> x;
			v[j].push_back(x);
		}
		for (int i = 1; i <= N; i++) { //순열사이클이 몇개인지 테스트한다. 모든 노드를 번갈아가며 검사
			if (!visit[i]) {
				bfs(i);
				count++;
			}
		}
		printf("%d\n", count);
		//초기화
		for (int i = 1; i <= N; i++) {
			v[i].clear();
		}
		count = 0;
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}