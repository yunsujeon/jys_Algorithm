#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N, s;
	int result = 0;
	int twice = 0;
	int now;
	int sortnum=-1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end()); //sort로 작은순부터 정렬한다.
	//2 3 4 들어갔을때 2*3 + 4가 안되고 2+ 3*4 가 되게하는방법은? 여기서마힘

	//vector를 재정렬하기
	// -5 -4 -3 -2 -1 0 1 2 3 4 5 라면
	// -5 -4 -3 -2 -1 0 5 4 3 2 1 로

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 0) {
			sortnum = i;
			break;
		}
	}
	if (sortnum >= 0) {
		sort(v.begin() + sortnum, v.end(),compare);
	}

	while(!v.empty()) {
		int i = 0;
		if (twice == 0) { //두번 건너뛰었을때
			if (v[i] <= 0) { //현재 원소가 음수거나 0이면
				now = v[i]; //now에 값을 옮긴다
				v.erase(v.begin()); //vector원소 지운다. 다음원소는 v[i]가 될것이다.
				if (!v.empty()) { //다음이 비지 않았으면
					if (v[i] <= 0) { //다음 원소가 음수이면
						result += now * v[i];
						twice = 1; // 곱했으니깐 뛰어넘는다는 표시
					}
					else if (v[i] > 0) { //다음원소가 양수이면
						result += now;
						twice = 0;
					}
				}
				else { //다음이 비었으면 지금 하나만 더한다
					result += now;
				}
			}

			else if (v[i] > 0) { //현재 원소가 양수이면
				now = v[i];
				v.erase(v.begin()); //다음원소가 v[i]가 될 것이다.
				if (!v.empty()) { //다음이 비지 않았으면
					if (v[i] <= 1) { //1이하면 그거만 더한다
						result += now;
						twice = 0;
					}
					else if (v[i] > 1) { //2이상의 양수이면 양수끼리 곱한다.
						result += now * v[i];
						twice = 1;
					}
				}
				else { //다음원소가 없다면 하나만 더한다
					result += now;
				}
			}
		}
	
		else if (twice == 1) {
			twice = 0;
			v.erase(v.begin());
		}
			
	}
	cout << result << endl;
	return 0;
}