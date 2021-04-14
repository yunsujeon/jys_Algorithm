#include <iostream>

using namespace std;

long long N;
long long solution(long long a) {
	long long v = 1;
	while (v * 2 < a) {
		v *= 2;
	}
	return a - v;
}

int main() {
	cin >> N;
	int cnt = 0;
	while (N != 0) {
		cnt++;
		N = solution(N);
	}
	if (cnt % 2 == 1) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}