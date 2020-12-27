//전위순회 중위순회 후위순회 구현

#include <iostream>
#include <vector>
using namespace std;

int N;
const int MAX = 26;
vector <pair<int,int>> v[MAX];

void preorder(int node) {
	cout << (char)(node + 'A');
	for (int i = 0; i < v[node].size(); i++) {
		preorder(v[node][i].first);
	}
}

void inorder(int node) {
	if (v[node].size() && v[node][0].second)
		inorder(v[node][0].first);
	cout << (char)(node + 'A');
	if (v[node].size() && !v[node][0].second)
		inorder(v[node][0].first);
	else if (v[node].size() == 2) {
		inorder(v[node][1].first);
	}
}

void postorder(int node)
{
	for (int i = 0; i < v[node].size(); i++)
		postorder(v[node][i].first);
	cout << (char)(node + 'A');
}

int main() {
	char a, b, c;
	cin >> N; //이진트리의 노드의 개수
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (b != '.')
			v[a - 'A'].push_back({ b - 'A', 1 });
		if(c!='.')
			v[a - 'A'].push_back({ c - 'A', 0 });
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
	return 0;
}