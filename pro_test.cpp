/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, string>>v;
	v.push_back(pair<int, string>(9, "A"));
	v.push_back(pair<int, string>(8, "B"));
	sort(v.begin(), v.end());
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int>>a, pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main() {
	vector<pair<string, pair<int, int>>>v;
	v.push_back(pair<string, pair<int, int>>("A", make_pair(90, 11111111)));
	v.push_back(pair<string, pair<int, int>>("B", make_pair(9, 111111)));
	sort(v.begin(), v.end(), compare);
	return 0;
}
*/

/*
#include <iostream>
#include <queue>
using namespace std;

struct test {
	int x; int y; int z;
};

struct compare {
	bool operator()(test a, test b) {
		if (a.z == b.z) {
			return a.x > b.x;
		}
	}
};

int main() {
	priority_queue<int>pq;
	pq.push(4);
	priority_queue<int, vector<int>, greater<int>>pq2;
	pq2.push(5);
	priority_queue<pair<pair<int, int>, int>>pq3;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>pq4;
	pq4.push({ {1,2},3 });
	priority_queue<test, vector<test>>pq5;
	priority_queue<test, vector<test>, greater<test>>pq6;
	priority_queue<test, vector<test>, compare>pq7;

}*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	//1234567 �Է��ε� ���� ������Ȳ�̸�?
	int a[7];
	for (int i = 0; i < 7; i++) {
		scanf("%1d", &a[i]);
	}
	// ��޴��� �𸣰� �ϳ��� �޾ƾߵɶ�
	string b;
	int temp = 0;
	cin >> b;
	for (int i = 0; i < b.size(); i++) {
		temp += b[i] - '0';
	}
	// ������ �����ؼ� �ϳ��� �޴� ���
	string name;
	getline(cin, name);
	// ������ �з��ؼ� �޴� ���
		// ���̸� �˸�
	int a1, a2;
	scanf("%d %d", &a1, &a2);
	cin >> a1 >> a2;
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}
		// ���̸� �𸣸� ���鹮�ڸ� �������� ���ڿ��� �ڸ��� �ֱ�


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

}
*/

/*
//bfs
#include <iostream>
#include <queue>

using namespace std;

vector<int>v[300001];
int dist[300001] = { 0, };

void bfs(int x) {
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (dist[z] == 0) {
				dist[z] = dist[x] + 1;
				q.push(z);
			}
		}
	}
}
int main() {


}
*/

