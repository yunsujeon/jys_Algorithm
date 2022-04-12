/*
택시 기사는 택시 서비스를 요청하는 사람들의 승하차 위치를 알고 있습니다.

모든 위치는 시작 지점에서 km 단위입니다. 시작 지점은 0km입니다.

승객이 여행 한 각 km마다 운전자는 승객 당 1 단위의 돈을 부과합니다.

게다가 택시 자체가 매우 화려합니다.

따라서 일부 사람들은 택시를 타면 추가 팁을 지불 할 의향이 있습니다.

어느 시점에서든 택시는 한 명의 승객 만 수용 할 수 있습니다. 운전자가 벌 수있는 최대 금액을 결정합니다.

Weighted Interval Scheduling 문제이다.
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
	sort(to.begin(), to.end(), compare); //여기서 to 를 기준으로 정렬해줘야한다.
	//이후 정렬된 것을 가지고 dp를 만들어나가자

	dp[0] = 0;
	for (int i = 1; i <= v.size(); i++) {
		if (v[i].first.second == i) { //i번 벡터에있을 때 해당 벡터가 i로 끝나는 경우
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