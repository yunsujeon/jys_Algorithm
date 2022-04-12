
//Ʈ���� ������ �ִ� �׷����� �ƴϰ� ����Ŭ�� �������� �ʴ´�.
//�� ª������ ���ͼ� ���� ũ�⸦ ������Ʈ �������� ����.
/*
#include <iostream>
#include <vector>
#include <queue>
#include<string.h>

using namespace std;

const int MAX = 100001;
vector <pair<int, int>>v[MAX];
int V;
int dist = 0;
int maxdist=0;
int maximum = 0;
bool visited[MAX] = { 0, };

void program(int i) { //bfs ��������
	maxdist = 0;
	queue<pair<int, int>>q;
	q.push({ i, 0 });
	visited[i] = true;
	while (!q.empty()) {
		int x = q.front().first;
		dist = q.front().second;
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {		
			int z = v[x][j].first; // 1�� ����Ǿ��ִ°�
			if (visited[z] == false) {
				int ndist = dist + v[x][j].second;
				visited[z] = true;
				q.push({ z,ndist });
			}
		}
		if (dist > maxdist)
			maxdist = dist;
	}
}

int main() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num,n1,n2;
		cin >> num;
		cin >> n1;
		while (n1 != -1) {
			cin >> n2;
			v[num].push_back({ n1,n2 });
			v[n1].push_back({ num,n2 });
			cin >> n1;
		}
	}
	for (int i = 1; i <= V; i++) { //��� ������ ����ϵ����ؼ� ����� ����������
		//�ð��ʰ�
		dist = 0;
		program(i);
		if (maxdist > maximum)
			maximum = maxdist;
		memset(visited,0, sizeof(visited));
	}
	cout << maximum;
	return 0;
}
*/

//Ʈ���� ������ ���� ���غ���
//���� 1���� �����ؼ� ���� �� �Ÿ��� y �����̶�� ����
//�� y�������� ���� �������� z�� �ִ� y-z�� ���� �� �Ÿ��̴�.

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int V;
const int MAX = 100001;
vector <pair<int, int>>v[MAX];
int visited[MAX] = { 0, };
int maxdist = 0;
int maxnode;

void input() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num, n1, n2;
		cin >> num;
		cin >> n1;
		while (n1 != -1) {
			cin >> n2;
			v[num].push_back({ n1,n2 });
			v[n1].push_back({ num,n2 });
			cin >> n1;
		}
	}
}

void dfs(int i,int dist) {
	if (visited[i]) //�湮�ѰŸ� �ٽù湮X
		return;
	if (maxdist < dist) { //�����س����°���
		maxdist = dist;
		maxnode = i;
	}
	visited[i] = true;
	for (int j = 0; j < v[i].size(); j++) {
		int ni = v[i][j].first;
		int nd = v[i][j].second;
		dfs(ni, nd + dist);
	}
}

int main() {
	input();
	dfs(1,0);//1�������� �����Ѵ�. distance=0���� ���� maxnode�� ���ؾߵȴ�.
	memset(visited, false, sizeof(visited));
	maxdist = 0;
	dfs(maxnode, 0);//ã�� �� ��忡�� ����հ��� ã�´�.
	cout << maxdist;
	return 0;
}