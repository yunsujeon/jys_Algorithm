/*네트워크플로우 - 특정한지점에서 다른지점으로 데이터가 얼마나 흐르는가
유량 / 용량 으로 용량보다 더 많이 보낼수는없음
최대유량문제 자주출제 
BFS를 이용 에드몬드카프 알고리즘, 단순하게 모든경우의 수 탐색
1. 현재 흐르고있는 유량을 모두 0으로 설정
2. 정해진 용량안에서 가능한 최대 용량의 양을 반복적으로 더해준다.
3. 음의 유량을 계산해준다. 반대로 가는 유량을 생각한다. (남은경로 더 찾기위해)
//순서가 상관없다. 남아있는 양이 1이 넘으면 계속해서 흘려보내주면 알아서
최적화가 이루어진다.
*** 기본적으로 BFS를 사용해서 모든 가능한 경로를 다 찾아서 남아있는 용량만큼
유량을 흘려보내주는 것을 반복하면된다.
bfs - queue
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100
#define INF 1000000000

using namespace std;
int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX]; //c는 용량 f는 유량 flow
vector<int> a[MAX];

void maxFlow(int start, int end) { //최대유량을 구하자
	while (1) {
		fill(d, d + MAX, -1); //배열 d를 전부 -1로 채운다.
		queue<int> q; //큐 선언
		q.push(start); //큐에 start를 넣는다.
		//기본적인 BFS
		while (!q.empty()) { //큐가 빌때까지 반복
			int x = q.front(); //큐 가장 앞에있는걸 x로 잡고
			q.pop(); //pop한다. bfs과정
			for (int i = 0; i < a[x].size(); i++) { //인접노드 확인
				int y = a[x][i]; //그 노드를 아예 y로 정해준다.
				//방문하지 않는 노드 중에서 용량이 남은 경우
				//printf("%d", c[x][y]-f[x][y]);
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) { //노드를 탐색했을 때 용량-유량>0 , 방문X
					q.push(y); //큐에 넣는다.
					d[y] = x; //경로 기억위해 현재 방문한 그 노드를 그 인접노드로 가는 값으로 넣어준다.
					//예를들어 d[3]=2 라면 노드 2에서 노드3으로 왔다는 뜻이다. 2->3
					if (y == end) break; //도착지에 도달
				}
			}
		}
		//모든 경로를 다 찾은경우
		if (d[end] == -1) //가능한 모든경로를 다 찾은경우에는 한번 너비우선탐색을 실행했을때
			//end 즉 도착지까지 도달을하지 못하기 때문에 -1
			//end에 도달하지 못하면 끝나도록 되어있다!! 경로가 더이상없는것
			break; //반복문을 탈출한다.

		int flow = INF; //가능한 가장 작은 유량을 흘려야되기때문에

		//거꾸로 최소 유량을 탐색한다.
		for (int i = end; i != start; i = d[i]) { //이전노드로 거꾸로 돌아감
			flow = min(flow, c[d[i]][i] - f[d[i]][i]); //최소값으로 갱신
		}
		//최소 유량만큼 추가한다.
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow; //음의 유량도 처리
		}
		result += flow; //최대유량값을 구해냈다.
	}
}

int main() {
	a[1].push_back(2); //상호연결
	a[2].push_back(1); //상호연결
	c[1][2] = 12; //유량

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	printf("%d", result);
}