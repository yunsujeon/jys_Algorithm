#include <iostream>

using namespace std;

int N;
const int MAX = 1001;
long long sum = 0;
long long DP[MAX][10];

void solution(){
	for (int i = 0; i <= 9; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			//아래의 것도 for문 돌리면 되긴함 시각적으로 파악하기쉽게 다 풀어써놓음
			if (j == 0)
				DP[i][j] = DP[i - 1][0]; //항상 한가지 경우다. 맨뒤자리가(젤큰자리가) 0이면
			else if (j == 1)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1])%10007;
			else if (j == 2)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 10007;
			else if (j == 3)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3]) % 10007;
			else if (j == 4)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4]) % 10007;
			else if (j == 5)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5]) % 10007;
			else if (j == 6)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5] + DP[i - 1][6]) % 10007;
			else if (j == 7)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5] + DP[i - 1][6] + DP[i - 1][7]) % 10007;
			else if (j == 8)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5] + DP[i - 1][6] + DP[i - 1][7] + DP[i - 1][8]) % 10007;
			else if (j == 9)
				DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5] + DP[i - 1][6] + DP[i - 1][7] + DP[i - 1][8] + DP[i - 1][9]) % 10007;
		}
	}

	for (int i = 0; i <= 9; i++) {
		sum += DP[N][i];
	}
}

int main() {
	cin >> N;
	solution();
	cout << sum%10007 << '\n';
	return 0;
}
