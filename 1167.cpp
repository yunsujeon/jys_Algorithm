
//트리는 방향이 있는 그래프가 아니고 사이클이 존재하지 않는다.
//더 짧은길이 들어와서 길의 크기를 업데이트 해줄일이 없다.
/*
#include <iostream>
#include <vector>
#include <queue>
#include<string.h>

using namespace std;

const int MAX = 100001;
vector <pair<int, int>>v[MAX];
int V;
int dist = 0;
int maxdist=0;
int maximum = 0;
bool visited[MAX] = { 0, };

void program(int i) { //bfs 돌려주자
	maxdist = 0;
	queue<pair<int, int>>q;
	q.push({ i, 0 });
	visited[i] = true;
	while (!q.empty()) {
		int x = q.front().first;
		dist = q.front().second;
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {		
			int z = v[x][j].first; // 1과 연결되어있는거
			if (visited[z] == false) {
				int ndist = dist + v[x][j].second;
				visited[z] = true;
				q.push({ z,ndist });
			}
		}
		if (dist > maxdist)
			maxdist = dist;
	}
}

int main() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num,n1,n2;
		cin >> num;
		cin >> n1;
		while (n1 != -1) {
			cin >> n2;
			v[num].push_back({ n1,n2 });
			v[n1].push_back({ num,n2 });
			cin >> n1;
		}
	}
	for (int i = 1; i <= V; i++) { //모든 점에서 출발하도록해서 모든점 도착을살핌
		//시간초과
		dist = 0;
		program(i);
		if (maxdist > maximum)
			maximum = maxdist;
		memset(visited,0, sizeof(visited));
	}
	cout << maximum;
	return 0;
}
*/

//트리의 지름을 먼저 구해보자
//정점 1에서 시작해서 가장 먼 거리를 y 정점이라고 하자
//이 y정점에서 가장 먼저리인 z가 있다 y-z가 가장 긴 거리이다.

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int V;
const int MAX = 100001;
vector <pair<int, int>>v[MAX];
int visited[MAX] = { 0, };
int maxdist = 0;
int maxnode;

void input() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num, n1, n2;
		cin >> num;
		cin >> n1;
		while (n1 != -1) {
			cin >> n2;
			v[num].push_back({ n1,n2 });
			v[n1].push_back({ num,n2 });
			cin >> n1;
		}
	}
}

void dfs(int i,int dist) {
	if (visited[i]) //방문한거면 다시방문X
		return;
	if (maxdist < dist) { //갱신해나가는과정
		maxdist = dist;
		maxnode = i;
	}
	visited[i] = true;
	for (int j = 0; j < v[i].size(); j++) {
		int ni = v[i][j].first;
		int nd = v[i][j].second;
		dfs(ni, nd + dist);
	}
}

int main() {
	input();
	dfs(1,0);//1정점에서 시작한다. distance=0으로 들어갈것 maxnode를 구해야된다.
	memset(visited, false, sizeof(visited));
	maxdist = 0;
	dfs(maxnode, 0);//찾은 그 노드에서 가장먼것을 찾는다.
	cout << maxdist;
	return 0;
}