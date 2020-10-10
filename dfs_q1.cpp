//DFS 기본
#include <iostream>
#include <vector>
#define MAX 9

using namespace std;
int d[MAX] = { 0, }; //방문체크하는배열
vector<int> a[MAX];


void dfs(int x) {
	
	if (d[x] == 1)
		return;
	d[x] = true;//방문체크하기
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

	a[1].push_back(8);
	a[8].push_back(1);

	a[2].push_back(7);
	a[7].push_back(2);

	a[7].push_back(6);
	a[6].push_back(7);

	a[7].push_back(8);
	a[8].push_back(7);

	a[3].push_back(4);
	a[4].push_back(3);

	a[3].push_back(5);
	a[5].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	dfs(1);

	return 0;

}