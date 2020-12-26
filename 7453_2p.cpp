
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 4000;

int n;
int arr[4][MAX];
vector <int> ab;
vector <int> cd;
long long int c = 0, c1 = 0, c2 = 0;

void hap() { //ab를 합친것과 cd를 합친 백터 생성
	int cnt1=0,cnt2=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(arr[0][i] + arr[1][j]);
			cd.push_back(arr[2][i] + arr[3][j]);
		}
	}
}

void twopointer() {
	int check1 = 0;
	int check2 = 0;
	while (check1!=ab.size() && check2!=cd.size()) {
		c1 = 0, c2 = 0;
		int result = ab[check1] + cd[check2];
		if (result == 0) {
			//같은수반복
			for (int t = ab[check1]; check1 < ab.size() && t == ab[check1]; check1++, c1++);
			for (int t = cd[check2]; check2 < cd.size() && t == cd[check2]; check2++, c2++);
			c += c1 * c2;
		}
		else if (result > 0) {
			check2++;
		}
		else
			check1++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}
	hap();
	
	//투포인터 위해 cd는 내림차순으로 정렬해준다.
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end(), greater<int>());

	twopointer();

	cout << c << endl;
	return 0;
}