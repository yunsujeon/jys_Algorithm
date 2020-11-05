//간척사업으로 문제를 풀수있다. BFS로 섬 부피를 1씩 늘이고 닿는다면 그때의 수

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 100
using namespace std;

int graph[MAX][MAX];
int dx[] = { 0,0,1,-1 }; //상하좌우 탐색위해
int dy[] = { 1,-1,0,0 };
int visited[MAX][MAX];
int N;
int a;

int bfs(int cnt) { //bfs 돌린다
	queue <pair<int,int>> q; 

	//전체를 돌며 cnt 섬만 q에 넣을거다.
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == cnt) { //한 섬의 번호
				visited[i][j] = true; //방문 true
				q.push({ i,j }); //큐에 넣기
			}
		}
	}
	int result = 0;
	while (!q.empty()) {  //큐가 빌때까지 반복한다.
		int size = q.size(); //q의 사이즈 즉 초기에는 섬의 크기
		for (int i = 0; i < size; i++) { //사이즈만큼 반복. 전체의 부피를 4방향으로 늘릴것
			//이게 size만큼 반복되면 한 겹(result)이 쌓인 것 그다음 q는 그 쌓인 부피를 또 늘릴것이다.
			int y = q.front().first;
			int x = q.front().second;
			q.pop(); //pop해준다.
			for (int i = 0; i < 4; i++) { //4방향 탐색하기
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < N) { //범위 조건을 만족하고
					if (graph[ny][nx] && graph[ny][nx] != cnt) { //다른섬과 맞닿으면
						return result; //result를 return한다.
					}
					else if (!graph[ny][nx] && !visited[ny][nx]) //graph가 0이고(섬이아니고) visited하지 않았다면
					{
						visited[ny][nx] = true; //방문해주고
						q.push({ ny,nx }); //push 해준다.
					}
				}
			}
		}
		result++;
	}
}

void dfs(int y, int x, int cnt) { //dfs를 통해 각 섬의 번호를 만들어준다.
	visited[y][x] = true; //지금 들어온 번호 true로 만들어주고 시작
	graph[y][x] = cnt; //섬의 번호를 cnt로 만들어준다.
	for (int i = 0; i < 4; i++) { // 4번반복
		int ny = y + dy[i]; //번호매겨준다.
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < N) { //범위를 충족하면
			if (graph[ny][nx] && !visited[ny][nx]) { //땅이면(0이 아니여야됨) && 방문하지않았다면
				dfs(ny, nx, cnt); //다시 dfs 넣어서 점령한다.
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			graph[i][j] = a;
		}
	}
	//각 섬을 다른수로 마킹해주기 위한 dfs
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] && !visited[i][j])
				dfs(i, j, cnt++); //다끝나고 나오면 또 cnt증가시켜서 다른곳들어감
		}
	}

	int result = 100000;
	//result min의 의미 : 한 번 bfs를 실행하면 1 섬에서 2, 3 섬으로 가는 다리 중 최소를 얻음
	// 2 섬에서의 1 3 까지의 result와 3 섬에서 2 1 까지의 최소랑 비교하여 min을 찾기위함
	for (int i = 1; i < cnt; i++) {
		memset(visited, 0, sizeof(visited));
		result = min(result, bfs(i));
	}
	cout << result << endl;
	return 0;
}