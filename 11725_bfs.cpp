//트리의 부모찾기
//입력에서 두 정점이 연결되었다는것은 하나는 그것의 부모이고 하나는 자식일것이다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int N;
vector <int> v[MAX];
int visited[MAX];
int parent[MAX];

void bfs() { //모든 노드를 탐색하며 그때그때 자신의 부모를 체크한다.
	queue<int>q;
	q.push(1); //1이 루트라고 설정해놓음
	visited[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (!visited[z]) {
				parent[z] = x; //check parent
				visited[z] = 1;
				q.push(z);
			}
		}
	}
}
void printparent() {
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}

int main() {
	cin >> N;
	int val1,val2;
	for (int i = 0; i < N-1; i++) {
		cin >> val1>>val2;
		v[val1].push_back(val2);
		v[val2].push_back(val1);
	}
	bfs();
	printparent();

	return 0;
}