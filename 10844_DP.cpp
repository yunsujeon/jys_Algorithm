//점화식 세우는데서 문제
//long long 형에서 문제

#include <iostream>

using namespace std;
const int MAX = 101;

int N;
long long DP[MAX][10];
long long sum = 0;

//점화식을 세우자

void solution(int n) {

	DP[1][0] = 0;
	for (int i = 1; i <= 9;i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) { //길이
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1]%1000000000;
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1]%1000000000;
			}
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1])%1000000000;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		sum += DP[n][i];
	}
}

int main() {
	cin >> N;
	solution(N);
	cout << sum%1000000000<<'\n';
	return 0;
}