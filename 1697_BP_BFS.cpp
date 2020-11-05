//완전탐색
//이동 가능한 경우의 수 : X-1, X+1, 2*X
// BFS이용한다. BFS의 다른 쓰임
#include <iostream>
#include <queue>

using namespace std;
	
//visited 에 갈수있는 경우를 모두 탐색해준다 bfs를
int N, K, visited[100001] = { 0, };
queue<int> q;

//기본원리 : 각 visited에 방문횟수를 입력함으로써 숫자 x가 도달하려면
//몇번 가야되는지를 visited에 다 저장해두는것
int bfs() {
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		//위치에 도달했다면 출력
		if (p == K) 
			return visited[p] - 1;
		//수빈이 현재위치-1 한 값이 0이상이고 방문한 적이없을경우
		//현재 값에서 레벨을(위치를) 1 증가시켜 큐에 넣어준다.
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1; //현재 p가 1이라면 이 자리엔 2를 넣어주는것 
			q.push(p - 1); //p-1값을 push 해준다
		}
		//수빈이 현재 위치의 +1이 100000보다 작거나 같고 방문한 적이 없을경우
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		//수빈이 현재 위치의 2배가 0보다 크거나 같고, 방문한적이 없을경우
		if (2 * p <= 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);
		}
	}
}
int main() {
	cin >> N >> K;
	printf("%d", bfs());
}