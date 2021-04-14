#include <iostream>
#include <string>
using namespace std;

int N;
long long X, Y;
string h = "";

long long calculate(long long a) {
	long long v = 1;
	while (v * 2 < a) {//2의 제곱승만큼
		v *= 2;
	}
	return a - v;
}

void hap(string s, int n) {
	string nr = to_string(n);
	h = s + nr;
}

int main() {
	cin >> N >> X >> Y;
	int resent;
	for (int i = X; i <= Y; i++) {
		int cnt = 0;
		int n = i;
		while (n != 0) {
			cnt++;
			n = calculate(n);
		}
		if (cnt % 2 == 1) {
			resent = 0;
		}
		else {
			resent = 1;
		}
		hap(h, resent);
	}
	cout << h << endl;
	return 0;
}