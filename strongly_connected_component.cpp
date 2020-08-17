/*강한 결합요소
강하게 결합된 정점집합 / SCC알고리즘 / 같은 SCC에 속하는 두 정점은 서로 도달이 가능하다. 
타잔알고리즘으로 구현 : 모든 정점에 대해 DFS를 수행하여 SCC를 찾는알고리즘
1->2->3->4 에서 다시 1로 돌아갈 수 있어야지 SCC가 성립한다.
1. 정점1을 기준으로 DFS를 수행한다. 이후 정점1이 스택에 들어간다.
2. 정점1과 연결된 2를 스택에 넣는다. 정점2도 현재는 자기자신이 부모
3. 정점2와 연결된 3을 스택에 넣는다. 정점3도 현재는 자기자신이 부모
4. 정점3을 기준으로 DFS를 수행할때 연결된 정점1을 확인 이때 정점1의 DFS가
끝나지 않은 상태이므로 여기서 정점3은 부모가 정점1임을 파악한다.
5. 정점2의 부모값은 정점3에서 건너온 부모값 1로 갱신된다.
6. 함수가끝나며 1의부모값은 자신과 동일하기 때문에 내가 SCC부모라고 깨달을수있음
이후 스택에서 자기자신이 나올때까지 뽑는다. 하나의 SCC그룹 발견
7. 방문하지않은 다음 정점 4에서 부터 DFS수행
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

int id, d[MAX];
bool finished[MAX]; //특정한 dfs가 끝났는지 확인하기위해
vector <int> a[MAX];
vector<vector<int> >SCC;
stack<int> s;

int dfs(int x) {
	d[x] = ++id; //노드마다 고유한 번호를 할당 / 방문표시, 다시 dfs실행안하기위함
	s.push(x); //스택에 자기 자신을 삽입

	int parent = d[x]; //자신의 부모가 누구인지 확인할수있게
	for (int i = 0; i < a[x].size(); i++) { //인접한 노드를 방문
		int y = a[x][i];
		//방문하지않은 이웃
		if (d[y] == 0) parent = min(parent, dfs(y)); //해당노드를 방문한적없다면 해당노드로 dfs를 수행하여 더 작은값으로 부모값갱신
		//처리되지 않은 이웃
		else if (!finished[y]) parent = min(parent, d[y]); //방문은했지만 처리가안됐으면 (dfs수행노드) 더 작은값으로
	}
	if (parent == d[x]) { //부모노드가 자기자신인 경우
		vector<int> scc; //스택에서 꺼내면서 scc를 만들어준다.
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break; //자기자신이 나올때까지 스택에서 뽑아준다.
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i); //각 정점에 대해 한번씩 dfs실행
	}

	printf("SCC의 갯수: %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}