/*이분매칭
A집단이 B집단을 선택하는 방법에 대한 알고리즘
효과적으로 집단을 매칭해준다. (최대매칭)
DFS로 풀 수 있다.
*/

#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n = 3, m, s;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) { //x에 연결된 노드들을 돌아가며 시도
		int t = a[x][i]; //그 인접노드를 t로 명명한다.
		//이미 처리한 노드는 더 이상 볼 필요가 없음
		if (c[t]) continue; //이미 true라면 빠져나간다.
		c[t] = true; //true 처리해준다.
		printf("%d", d[t]);
		if (d[t] == 0 || dfs(d[t])) { //원하고자 하는 대상이 비어있을 경우에
			d[t] = x; //차지한다.
			return true; //그리고 true를 반환한다.
		}
	}
	return false;
}

int main() {
	a[1].push_back(1); //1은 1을 원한다.
	a[1].push_back(2); //1은 2를 원한다.
	a[1].push_back(3); //1은 3을 원한다.
	a[2].push_back(1); //2는 1을 원한다.
	a[3].push_back(2); //3은 2를 원한다.
	int count = 0; //카운트를 0으로 초기화한다.
	for (int i = 1; i <= n; i++) { //갯수만큼 번갈아가면서
		fill(c, c + MAX, false); //c배열을 false로 초기화한다.
		if (dfs(i)) //0이 아닌경우. 즉, 매칭에 성공한경우.
			count++; //dfs가 0이 아니면 count를 늘린다. = 매칭에 성공한 경우이다.
	}
	printf("%d개의 매칭이 이루어졌습니다.\n", count);
	for (int i = 1; i <= 100; i++) { //100까지 반복
		if (d[i] != 0) { //d[i]가 0이 아니면 = 매칭된 값이 있으면
			printf("%d -> %d\n", d[i], i); //나타내준다.
		}
	}
	return 0;
}