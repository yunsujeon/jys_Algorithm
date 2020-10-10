//도시 까지 정확히 최단거리가 맞는 도시는?
/* 1~N까지의 도시, M개의 단방향 도로 존재, 각 도로의 거리는 1
특정도시 X로부터 출발하여 도달할 수 있는 도시들 중 최단거리가 정확히 K인
모든 도시들의 번호를 출력하는 프로그램을 작성하라*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[300001];
int dist[300001] = { 0, };
int n, m, k, x, z; //n:도시개수 m:도로갯수 k:최단거리여야되는 거리 x:특정도시

void bfs(int x) {
	queue <int> q;
	q.push(x);

	while (!q.empty()) {
		int x = q.front(); //항상 들어온 x이지는 않으니 x로 갱신해준것이다.
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (dist[z] == 0) { //탐색하지않은곳만 찾아간다.
				dist[z] = dist[x]+1;
				q.push(z);
			}
		}
	}
}
//반례로 거리가 이미 3이 들어가있는 경우에 2인 거리가 최소로 들어오면? - 그러나 정답... 이건 반례가 아닌가보다

int main() {

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int i1, i2;
		cin >> i1 >> i2;
		v[i1].push_back(i2);
	}

	bfs(x);

	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k)
			answer.push_back(i);
	}
	if (answer.size() == 0)
		cout << -1 << endl;
	else {
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
	}
}