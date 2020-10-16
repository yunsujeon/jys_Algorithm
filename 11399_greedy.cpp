/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int,int>> v;

bool secondsort(pair<int,int>a, pair<int,int>b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int N, s;
	int result=0;
	int mid = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		v.push_back({ i,s }); //i번사람이 s분의 시간
	}
	sort(v.begin(), v.end(), secondsort); //시간적은순으로 정렬한다.
	
	for (int i = 0; i < N; i++) {
		mid = v[i].second + mid;
		result = result + mid;
	}
	cout << result << endl;
	return 0;
}
*/

//벡터와 배열을 자유롭게 오가기. front 와 first 의미들
//생각하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v; //저장되는것을 즉 v[i]로 꺼낼수있다.

int main() {
	int N, s;
	int result=0;
	int mid = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s); //i번사람이 s분의 시간
	}
	sort(v.begin(), v.end()); //입력한 숫자순 정렬한다.

	for (int i = 0; i < N; i++) {
		mid = v[i] + mid;
		result = result + mid;
	}
	cout << result << endl;
	return 0;
}
