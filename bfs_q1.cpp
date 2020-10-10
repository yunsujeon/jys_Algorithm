#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;
vector <int> a[MAX];
int d[MAX] = { 0, };

void bfs(int x) {
	queue <int> q;
	q.push(x);
	d[x] = true;
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		printf("%d", y);
		for (int i = 0; i < a[y].size(); i++) {
			int z = a[y][i];
			if (!d[z]) {
				q.push(z);
				d[z] = true;
			}
		}
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

	bfs(1);
	return 0;
}