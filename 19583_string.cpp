//입력이 까다로웠던 문제
#include <iostream>
#include <string>
#include <set>
using namespace std;

string S, E, Q;
string id;
int time, time_s, time_e, time_q;

set <string> in_check;
set <string> out_check;

int cnt = 0;

void solution() {
	string in_a, in_b;
	while (!cin.eof()) {
		cin >> in_a >> in_b;
		//cin >> in_a >> in_b;
		//if (cin.eof()) break;
		time = stoi(in_a.substr(0, 2)) * 100 + stoi(in_a.substr(3, 5));
		if (time >= 0 && time <= time_s) {
			in_check.insert(in_b);
		}
		else if (time >= time_e && time <= time_q) {
			out_check.insert(in_b);
		}
	}
	for (set<string>::iterator it = in_check.begin(); it != in_check.end(); it++) {
		if (out_check.find(*it) == out_check.end()) { // 찾는 문자열이 없다면
			continue;
		}
		else cnt++;
	}
}

int main() {
	//https://chogyujin.github.io/2019/02/15/%EC%BD%94%ED%85%8C-%EB%B3%B4%EA%B8%B0-%EC%A0%84%EC%97%90-%EC%A4%80%EB%B9%84%ED%95%98%EA%B8%B0!/?
	ios::sync_with_stdio(0); // C++ stream과 C stream 사이의 sync를 끄는 명령
	cin.tie(0); // cin과 cout이 번갈아 나올 때마다 flush를 하지 않도록 하는 명령

	cin >> S >> E >> Q;
	time_s = stoi(S.substr(0, 2)) * 100 + stoi(S.substr(3, 5));
	time_e = stoi(E.substr(0, 2)) * 100 + stoi(E.substr(3, 5));
	time_q = stoi(Q.substr(0, 2)) * 100 + stoi(Q.substr(3, 5));

	solution();

	cout<<cnt;
	return 0;
}
