#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;

int N;
int T, P;
int DP[17] = { 0, }; //DP는 각 일자별 들어갈 최대 벌 수 있는 P

//vector <pair<int, int>> v;
// 경우의 수가 적어 사실 전부 따져도 된다.
/*
void solution() {
	// 각 일자별로 최대로 받을 수 있는 pay을 계산해 저장해놓자. 이후 업데이트
	// 우선 DP를 수행하려면 시작값은 선정해줘야 한다.
	for (int i = 0; i < N; i++) {
		int day = v[i].first;
		int pay = v[i].second;
		int targetday = i + day;
		if (targetday <= N && pay>=DP[targetday]) {
			DP[targetday] = pay; //큰걸로갱신
		}
	}
	//이제 각 일수별로 돌아가며 최대값을 갱신해주기만 하면된다.
	for (int i = 0; i < N; i++) {
		int hap = 0;
		int j = i;
		while(j<N){ // 그 값부터 끝값까지 가면서 갱신
			int day = v[j].first;
			int pay = v[j].second;
			if (j + day <= N) { // 일자를 초과하지 않는다면. 즉 0+7<=7 로 생각
				hap += pay; //hap에 pay를 더한다.
				if (day == 1) { // 우선 어느칸에서든 1이면 DP에 hap을 집어넣을수가있음
					DP[j + 1] = hap;
				}
				else {
					for (int k = j; k < j - 1 + day; k++) {
						DP[k + 1] = hap-pay;//1일이 아니라면 바로 넣을 수 없음.
					}
				}
			}
			else {
				DP[j + 1] = hap; //DP에 최대값만 넣어준다.
			}
			j++;
		}
	}

}*/

// but DP를 이용해보자.
// 무조건 다음 수가 아니라 다다음 수를 선택해야 최대가 되는 경우 있음

pair<int, int> map[1002];

void solution(int now, int time, int value) {
	for (int i = now + time; i <= N; i++) { //DP를 찾아갈 곳을 지정한다. now + time부터 시작
		if (i + map[i].first <= N + 1) { //정해준 날을 넘어가지 않는다면
			DP[i] = max(DP[i], map[i].second + value); //찾아간 곳의 DP는 그곳의 P값과 이전 P의 합 vs 그곳의 DP값
			solution(i, map[i].first, DP[i]); // 찾아간 지점에서 또 solution을 돌려준다.
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		map[i].first = T;
		map[i].second = P;
	}

	for (int i = 1; i <= N; i++) {
		if (i + map[i].first <= N + 1) { //정해준 날을 넘어가지 않는다면
			DP[i] = max(DP[i], map[i].second); //해당 DP의 시작 값을 지정해준다.
		}
		solution(i, map[i].first, map[i].second); //현재 i와 T, P를 전달해준다.
	}

	sort(DP, DP + N + 1, greater<int>());
	cout << DP[0] << '\n';

	return 0;
}