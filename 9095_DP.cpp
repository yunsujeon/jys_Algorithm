//DP를 이용한 완전탐색이다.
//DP는 점화식을 찾아야된다.

//문제의 포인트는 1,2,3의 합으로 이루어진 경우를 생각하는 것
//n-1번째에서 각각의 값에 1을 더하는 경우
//n-2번째에서 각각의 값에 2를 더하는 경우
//n-3번째에서 각각의 값에 3을 더하는 경우로 나타낼수있다.

#include <iostream>
using namespace std;

int dp[11] = { 0, };

int cal(int x) {
	int cnt = 0;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= x; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[x];

}
int main() {
	int T, s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s;
		cout << cal(s) << endl;
	}
}