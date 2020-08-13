/*다익스트라 알고리즘 = 최단경로탐색 알고리즘
인공위성 GPS소프트웨어 등에서 많이 사용된다. 음의 간선 존재X
최단거리는 여러 개의 최단거리로 이루어져있다.
탐색하면서 최소비용인것으로 갱신해나간다.
동적프로그래밍을 적용
*/

//선형탐색으로 찾도록 함. O(N^2) 이는 정점은많은데 간선은 적을때 비효율적

/*
#include <stdio.h>

int number = 6;
int INF = 10000000;

int a[6][6] = { //비용을 정의해준다.
{0,2,5,1,INF,INF},
{2,0,3,2,INF,INF},
{5,3,0,3,1,5},
{1,2,3,0,1,INF},
{INF,INF,1,1,0,2},
{INF,INF,5,INF,2,0}
};
bool v[6]; //방문한 노드
int d[6]; //거리

//가장 최소 거리를 가지는 정점을 반환한다.
int getSmallIndex() {
	int min = INF; //최대로 초기화해둔다.
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) { //방문하지 않는 노드중에서 최소값보다 적은 거리갖는.
			min = d[i];
			index = i;
		}
	}
	return index; //그때의 위치를 반환
}

void dijkstra(int start) { //0start 면 [0]은 1이므로 1에서 각 정점까지 비용계산
	for (int i = 0; i < number; i++) { //0 1 2 3 4 5
		d[i] = a[start][i]; //반복하며 d를 초기화시켜준다.0 2 5 1 INF INF
	}
	v[start] = true; //시작점을 방문노드 처리해준다.

	for (int i = 0; i < number - 2; i++) { //첫노드 마지막 노드를 빼서 n-2번만 돌면된다
		int current = getSmallIndex(); //방문하지 않은 노드들을 돌며 최소거리를 가지는 정점을 반환 [3]이니깐 4
		v[current] = true; //그 노드를 방문처리해준다

		//그 노드에 인접한 모든 노드들을 확인하면서
		for (int j = 0; j < 6; j++) { //0 1 2 3 4 5
			if (!v[j]) { //v[j]가 0이면 if문 걸린다. 0이라는 뜻은 방문하지않은것
				if (d[current] + a[current][j] < d[j]) { //거쳐서 가는게 더 작다면
					d[j] = d[current] + a[current][j]; //갱신해준다.
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d", d[i]);
	}
}
*/
//선형탐색방법이 아닌 힙구조를 활용하여 O(N*logN)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int inf = 10000000;

vector<pair<int, int>>a[7]; //간선정보
int d[7]; //최소비용

void dijkstra(int start) {
	d[start] = 0; //최소비용 0으로 초기화
	priority_queue<pair<int, int>>pq; //pq 선언
	pq.push(make_pair(start, 0)); //초기화

	//가까운 순서대로 처리하므로 큐를 사용한다.
	while (!pq.empty()) {
		int current = pq.top().first;
		//짧은 것이 먼저 오도록 음수화한다
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] < distance) continue; //이미 최소라면 루프의 끝으로 이동한다
		for (int i = 0; i < a[current].size(); i++) { //연결된 노드들을 돌아가며 본다
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) { //더한게 더 작다면 
				d[next] = nextDistance; //교체한다
				pq.push(make_pair(next, -nextDistance));
			} 
		}
	}
}

int main() {
	for (int i = 1; i <= number; i++) {
		d[i] = inf;
	}
	a[1].push_back(make_pair(2, 2)); //1에 2가 물려있고 비용은 2
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[1].push_back(make_pair(1, 2));
	a[1].push_back(make_pair(3, 3));
	a[1].push_back(make_pair(4, 2));

	a[1].push_back(make_pair(1, 5));
	a[1].push_back(make_pair(2, 3));
	a[1].push_back(make_pair(4, 3));
	a[1].push_back(make_pair(5, 1));
	a[1].push_back(make_pair(6, 5));

	a[1].push_back(make_pair(1, 1));
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 3));
	a[1].push_back(make_pair(5, 1));

	a[1].push_back(make_pair(3, 1));
	a[1].push_back(make_pair(4, 1));
	a[1].push_back(make_pair(6, 2));

	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(5, 2));

	dijkstra(1);

	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}