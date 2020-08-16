/*위상정렬-순서가 정해져있는 작업을 차례로 수행해야할때 순서를 결정하기위해
결과1 : 현재 그래프는 위상정렬이 가능한지
결과2 : 위상정렬이 가능하다면 그 결과는 무엇인지
과정 1> 진입차수가 0인 정점을 큐에 삽입한다 
2> 큐에서 원소를 꺼내 연결된 모든 간선을 제거한다
3> 간선제거 이후에 진입차수가 0이 된 정점을 큐에 삽입한다
4> 큐가 빌때까지 2~3번 과정을 반복한다. 모든 원소를 방문하기전에 큐가 빈다면
사이클이 존재하는것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상정렬의 결과
시간복잡도는 O(V+E)
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i); //처음에 큐에 넣을것. 진입차수0
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) { //다 돌기전에 큐가 빈것.
			printf("사이클이 발생했습니다");
			return;
		}
		int x = q.front(); //현재 진입차수 0인거 큐에서 뺀다
		q.pop();
		result[i] = x;

		for (int i = 0; i < a[x].size(); i++) { //연결된걸 둘러보며
			int y = a[x][i]; 
			if (--inDegree[y] == 0) //진입차수 빼준게 0이면 큐에들어간다
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", result[i]);
	}
}

int main(void) {
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
}