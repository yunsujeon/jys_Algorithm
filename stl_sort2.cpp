/* 클래스 대신 Pair 라이브러리 사용하기*/
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, string>>v;
	v.push_back(pair<int, string>(90, "A"));
	v.push_back(pair<int, string>(85, "B"));
	v.push_back(pair<int, string>(82, "C"));
	v.push_back(pair<int, string>(98, "D"));
	v.push_back(pair<int, string>(79, "E"));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
	return 0;
}
*/
//성적대로 정렬을 하되 성적이 같다면 나이가 어린사람이 출력
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int> >a,
	pair < string, pair<int, int> > b) {
	if (a.second.first == b.second.first) { //성적이 같으면
		return a.second.second > b.second.second; //연도 높으면 나이어린거
	}
	else {
		return a.second.first > b.second.first; //성적높은사람 우선
	}
}
int main() {
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("A", make_pair(90, 19961222)));
	v.push_back(pair<string, pair<int, int> >("B", make_pair(97, 19930518)));
	v.push_back(pair<string, pair<int, int> >("C", make_pair(95, 19930203)));
	v.push_back(pair<string, pair<int, int> >("D", make_pair(90, 19921207)));
	v.push_back(pair<string, pair<int, int> >("E", make_pair(88, 19900302)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}
