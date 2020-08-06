/*깊이우선탐색
탐색을 함에 있어 보다 깊은 것을 우선적으로 탐색한다
맹목적으로 각 노드를 탐색할때 사용
DFS - Stack 사용*/

#include <iostream>
#include <vector>
//#include <stack> 굳이 없어도 되는 이유는 컴퓨터 기본 구조가 스택구조이기때문
using namespace std;

int number = 7;
int c[8];
vector <int> a[8];

void dfs(int x) {
	//cout << c[x]; //방문체크여부
	if (c[x])  //방문체크가 되었다면 뛰어넘기
		return;
	c[x] = true; //방문체크하기
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
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

	dfs(1);
	return 0;
}