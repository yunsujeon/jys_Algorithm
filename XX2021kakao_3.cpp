/*
�ý� ���� �ý� ���񽺸� ��û�ϴ� ������� ������ ��ġ�� �˰� �ֽ��ϴ�.

��� ��ġ�� ���� �������� km �����Դϴ�. ���� ������ 0km�Դϴ�.

�°��� ���� �� �� km���� �����ڴ� �°� �� 1 ������ ���� �ΰ��մϴ�.

�Դٰ� �ý� ��ü�� �ſ� ȭ���մϴ�.

���� �Ϻ� ������� �ýø� Ÿ�� �߰� ���� ���� �� ������ �ֽ��ϴ�.

��� ���������� �ýô� �� ���� �°� �� ���� �� �� �ֽ��ϴ�. �����ڰ� �� ���ִ� �ִ� �ݾ��� �����մϴ�.

Weighted Interval Scheduling �����̴�.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> from;
vector <int> to;
vector <int> tip;
int num, cost;
int dp[] = { 0, };

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b ) {
	return a.first.second > b.first.second;
}

void taxi(vector<int>from,vector<int>to,vector<int>tip) {
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < num; i++) {
		v.push_back({ {from[i],to[i]},tip[i] });
	}
	sort(to.begin(), to.end(), compare); //���⼭ to �� �������� ����������Ѵ�.
	//���� ���ĵ� ���� ������ dp�� ��������

	dp[0] = 0;
	for (int i = 1; i <= v.size(); i++) {
		if (v[i].first.second == i) { //i�� ���Ϳ����� �� �ش� ���Ͱ� i�� ������ ���
			cost = v[i].second + dp[v[i].first.first];
		}
		dp[i] = max(dp[i - 1], cost);
	}
}

int main() {
	cin >> num;
	int a, b, c;
	for (int i = 0; i < num; i++) {
		cin >> a >> b >> c;
		from.push_back(a);
		to.push_back(b);
		tip.push_back(c);
	}
	taxi(from, to, tip);
	return 0;
}