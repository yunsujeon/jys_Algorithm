//min max가 algorithm 헤더에있다니!

#include <iostream>
#include <algorithm>


using namespace std;

int count(int n, int m) {
	int result;
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		result =  (m+1)/2;
		if (result >= 4) {
			result = 4;
		}
		return result;
	}
	else { //n이 3 이상일때
		if (m >= 7) //7 이후에는 자유다 .m-2로 같음
			return m - 2;
		else {//7 미만이라면
			result = min(m, 4); //4번 초과하면안됨 but 아무거나쓸수있음
			return result;
		}
	}

}
int main() {
	int N, M;
	cin >> N >> M;
	cout << count(N, M) << endl;

	return 0;
}