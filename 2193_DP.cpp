
#include <iostream>

using namespace std;

int N;
const int MAX = 91;
long long DP[MAX][2];
long long sum=0;

void solution() {
	DP[1][0] = 0; //길이가 1일때 0 으로 시작못함
	DP[1][1] = 1; //길이가 1일때 1 로는 시작할수있다.
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j == 0)
				DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
			else
				DP[j][1] = DP[i - 1][0];
		}
	}
	for (int i = 0; i <= 1; i++) {
		sum += DP[N][i]; //N번째에서 0으로 끝나는거 수와 1로 끝나는거 수를 더한다.
	}
}

int main() {
	cin >> N;
	solution();
	cout << sum << '\n';
	return 0;
}