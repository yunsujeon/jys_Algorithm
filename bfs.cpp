/*너비우선탐색
너비를 우선으로 탐색을 수행하는 """탐색""" 알고리즘. 
맹목적인 탐색을 하고자할때 사용할 수 있는 탐색 기법
최단경로를 찾아준다는점에서 최단길이를 보장해야할때 사용
큐를 이용한다.*/
//BFS - QUEUE

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //결과를 저장하는 배열
vector <int> a[8];
//입구와 출구가 다른 큐
void bfs(int start) {
	queue<int> q; //큐 생성
	q.push(start); //받아온 시작위치를 큐에 넣어준다.
	c[start] = true; //방문처리를 해준다.
	while (!q.empty()) { //q가 빌때까지 계속한다. queue가 비면 끝난거.
		int x = q.front(); //일단 하나 꺼내고 연결된 거를 큐로 넣는 방법
		q.pop(); //꺼낸다.
		printf("%d", x); //꺼낸것을 보인다.
		for (int i = 0; i < a[x].size(); i++) { //연결된 수만큼반복
			int y = a[x][i]; //연결된 노드가 가리키는 수를 저장
			if (!c[y]) { //있다면은
				q.push(y); //큐에 그 수를 넣는다.
				c[y] = true; //방문체크를 해준다.
			}
		}
	}
}
int main() {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);
	return 0;
}
