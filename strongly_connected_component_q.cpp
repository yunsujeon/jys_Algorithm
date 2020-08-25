/*강한결합요소(SCC) 기초 문제풀이
서로 긴밀하게 연결된 정점간의 그룹을 의미한다. */
/*2150번 
방향그래프가 주어졌을 때 그 그래프를 SCC들로 나누는 프로그램을 작성하라
입력)
7 9		그래프가 7개의 정점과 9개의 간선으로 이루어졌다는 의미
1 4		1번과 4번이 연결되어있음 1->4 방향으로
4 5
5 1
1 6
.....
출력) 구성된 SCC를 출력하면된다.
3		구성된 SCC 개수
1 4 5 -1 구성된 SCC의 요소
2 3 7 -1
6 -1
특정한 그래프안에 포함되어있는 SCC를 출력하는 문제이다. (DFS이용)
가장 작은 정점의 번호 순으로 출력을 해야하므로 정렬을 수행해줘야한다.
*/
/*
#include <iostream>
#include <stack> //dfs위해
#include <vector>
#include <algorithm>
#define MAX 10001 //정점이 최대 만개이므로

using namespace std;

vector<int> a[MAX]; //인접노드들을 담을수있게
int id=0, d[MAX];
stack<int> s; //SCC판별시엔 스택이 쌓인다.
bool finished[MAX]; //처리가 된 노드 표시
vector<vector<int>> SCC; 

int dfs(int x) { //항상 처음 방문하는 노드만 실행된다. 즉 n번수행
	d[x] = ++id; //방문체크 해준거. 별의미없음 d[x]가 0이 아님만 나타냄
	s.push(x); //스택에 들어온숫자를 넣는다.
	int result= d[x];
	for (int i = 0; i < a[x].size(); i++) { //연결된거 돌아가면서
		int y = a[x][i]; //y초기화
		if (d[y] == 0) //아직 방문하지않은 이웃노드인경우
			result = min(result, dfs(y)); //재귀로 dfs한 후 더 작은값
		else if (!finished[y]) //방문은했지만 아직 처리중인 이웃노드이면
			//아직 처리중이라는 것은 즉 자신의 부모일 것이라는것 자신과 연결되었다는것
			result = min(result, d[y]); //해당 이웃노드의 d배열값을 넣어준다
	}
	//모든 인접노드를 확인한 다음에 돌아왔을때
	//부모노드가 자기 자신인 경우 SCC를 형성한다.
	if (result == d[x]) { //즉 이웃노드를 전부 방문한 이후에도 자기 자신이
		//가지고 있던 id값과 일치하는 경우에는 내가 특정한 scc에서 부모역할을
		//수행하는 것이였구나 라는 것을 깨달은것
		vector<int> scc;
		while (1) { //자기 자신이 나올때까지 스택에서 꺼내면 된다.
			int t = s.top();
			s.pop();
			scc.push_back(t); //작은 scc에 t를 넣어
			finished[t] = true; //빠져나온 값은 finished 를 true로만듦
			if (t == x) //t가 부모면 멈춘다.
				break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return result;
}

int main() {
	int v, e;
	scanf_s("%d %d", &v, &e);
	for (int i = 0; i < e; i++) { //간선 수만큼 반복
		int x, y;
		scanf_s("%d %d", &x, &y);
		a[x].push_back(y); //뭐와 뭐가 연결되어있는지
	}
	for (int i = 1; i < v; i++) { //1에서부터 정점갯수 전까지 반복
		if (d[i] == 0) //방문체크 안됐으면(근데 아예 떨어져있는 경우 아니면 한면에 다 훑는다.)
			dfs(i); //dfs 실행
	}
	printf("%d\n", SCC.size()); //SCC사이즈 출력하고
	sort(SCC.begin(), SCC.end()); //작은 숫자먼저로 정렬시킨다.
	for (int i = 0; i < SCC.size(); i++) { //사이즈 만큼 반복
		for (int j = 0; j < SCC[i].size(); j++) { //SCC구성하는거 프린트
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
*/

/*4196번 - 도미노

도미노는 연결돼있을때만 쓰러진다. 간혹가다 끊긴 부분이있으면 쓰러지지 않는다.
모두 쓰러뜨리기 위해 몇 번 건드려 줘야할까?

강한결합요소와 강한결합요소 사이의 관계까지 구해야하는문제
강한결합요소를 정점으로 보고 위상정렬을 했을 때 진입차수가 0인 정점의 갯수를 세면됨
모든 SCC에 대해 고유한 번호 값을 매겨 그룹을 만든 뒤 각각의 그룹을
하나의 정점으로 보고 단순하게 진입차수의 갯수만 세주면 된다.
이후에 각 그룹에 대해 진입차수의 갯수가 0인 경우에만 카운트를 해주어 출력
0을 치면 나머지가 넘어가는거기때문
입력)
1		테스트케이스의 갯수
3 2		도미노의 갯수는 3개 관계의 갯수는 2개
1 2		관계 1 -> 1번 블록이 넘어지면 2번 블록도 넘어진다.
2 3		관계 2 -> 2번 블록이 넘어지면 3번 블록도 넘어진다.
출력) 1*/

#include <iostream>
#include <stack>
#include <vector>

#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX]; //각각의 정점의 진입차수가 몇인지 확인

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0)
			parent = __min(parent, dfs(y)); //또는 #define NOMINMAX 추가해주면됨
		else if (!finished[y])
			parent = __min(parent, d[y]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1; //특정한 SCC에 속해있는 모든 
			//정점들이 SCC크기에 1을 더해준값을 넣어주는것
			//첫번째 SCC에 들어있는 애들은 1일것이고
			//두번째 SCC에 들어있는 애들은 2를 가질것이다.
			//그룹값을 기준으로 어떤 SCC에 포함되어있는지 구별할수있다.
			finished[t] = true;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	int t;
	scanf_s("%d", &t);
	while (t--) {
		SCC.clear();
		fill(d, d + MAX, 0); //d값을 초기화한다.
		fill(finished, finished + MAX, 0); //끝났는지 판별 다 초기화 0
		fill(inDegree, inDegree + MAX, 0); //진입차수 다 초기화 0
		scanf_s("%d %d", &n, &m); //정점과 간선정보
		for (int i = 1; i <= n; i++) { 
			a[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf_s("%d %d", &x, &y);
			a[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {//모든 노드에 대해서 dfs
			if (d[i] == 0)
				dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j]; //연결되어진 정점을 y로 함
				if (group[i] != group[y]) //y와 i가 속한 그룹이 다르다면
					inDegree[group[y]] = true; //y가 속한 SCC의 그룹 값을 true로 즉 진입차수가 존재한다.
			}
		}
		int result = 0;
		for (int i = 1; i <= SCC.size(); i++) { //SCC들을 확인하면서
			if (!inDegree[i]) //진입차수가 0인경우는
				result++; //갯수 증가시킨다.
		}
		printf("%d\n", result);
	}
	return 0;
}