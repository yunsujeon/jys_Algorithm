//문제해결
//done 배열의 사용
//시간초과 대비 - 한번 인지한 사이클은 더이상 보지 않게끔하기

#include <iostream>
#include <cstring> //for memset
#define MAX 100001

using namespace std;

int graph[MAX];
bool visit[MAX];
bool done[MAX]; //더이상 이 노드를 방문하지 않을 것을 확신하는 경우에만 true
int cnt,n;

void dfs(int x) {

	visit[x] = true; //방문처리 해주고

	int next = graph[x]; //x가 가리키는것이 next
	//아예 가리키지 않는다면 끝나버릴것

	//방문 안했다면 dfs를 돌린다
	if (!visit[next]) {
		dfs(next);
	}

	//visit == 1 이여도 done이 false면 else를 탄다.
	else if (!done[next]) {

		//팀원을 모두 센다
		for (int i = next; i != x; i = graph[i]) { //i!=x 라는것은 자기자신이나올때까지
			cnt++;
		}
		cnt++; //자기자신도 더해준다
	}
	done[x] = true; //진심 더이상 방문하지 않아도된다
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));

		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> graph[j];
		}

		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				dfs(j);
			}
		}

		cout << n - cnt << endl;

	}
	return 0;
}