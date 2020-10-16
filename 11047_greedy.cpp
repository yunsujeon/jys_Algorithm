//그리디알고리즘 - 이기적인 알고리즘이야

#include <iostream>
#include <algorithm>
using namespace std;

int coin[10] = { 0, };

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + 10, desc);

	int i = 0;
	int count = 0;
	while (K) {
		int r = 0;;
		r = K / coin[i];
		if (r) {
			K = K - (coin[i] * r);
			count += r;
		}
		i++;

	}
	cout << count << endl;
}