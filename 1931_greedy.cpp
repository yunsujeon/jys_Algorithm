//회의실배정
//continue와 break 구분사용
//next_permutation 전에는 sort를 해줘야 전체 다 탐색가능

#include <iostream>
#include <vector>
/*#include <algorithm>
#include <string.h>
using namespace std;

int time[25];
vector <pair<int, int>>v;

int main() {
	int N;
	int start;
	int end;
	int slut;
	int number=0;
	int MAX = 0;
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end());

	//명심해야될것 : 회의 시간의 최대 X 회의갯수의 최대 O
	do {
		for (int i = 0; i < N; i++) {
			slut = 0; //초기화

			int a = v[i].first;
			int b = v[i].second;
			if (a == b) {
				number++;
			}
			for (int j = a; j < b; j++) { //끝나는 동시에 시작가능하니 <=b 아니다
				if (time[j] == 0) {
					slut = 0;
				}
				else {
					slut = 1;
					break;
				}
			}
			if (slut == 0) {
				for (int j = a; j < b; j++) {
					time[j] = 1;					
				}
				number++;
			}
		}

		if (MAX < number)
			MAX = number;
		number = 0; //초기화
		memset(time, 0, sizeof(time)); //초기화
		//cout << count++ << endl;
		//cout << MAX << endl;
	} while (next_permutation(v.begin(), v.end()));

	cout << MAX << endl;
	return 0;
}
*/


//전체 경우를 찾는 수 말고 최적의 해를 찾기위해
//활동이 최대한 일찍끝나는 것을 골라가면된다.

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
	return (a.second < b.second);
}
int main() {

	int N, i, n1, n2, min, cnt = 0;

	cin >> N;
	vector <pair <int, int> > v;

	for (i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back({ n1, n2 });
	}
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), sortbysec); //두번째원소로 정렬
	//끝나는 시간이 가장 빠른 순서대로 정렬되게 된다.

	min = v[0].second; //그러면 무조건 0으로 시작하는게 이득
	cnt++;

	for (i = 1; i < N; i++) { //0번은 한다치고 1번부터시작
		if (v[i].first >= min) { //이전이 끝난다음 시작하는것중에 가장 시간이 적게걸리는거
			min = v[i].second; //이것이 끝나는 시간을 min
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}