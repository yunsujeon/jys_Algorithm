#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 10001;

int n;
int arr[MAX];
int dp[MAX];

//점화식 도출 다시 생각해볼것

void solution() {
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		//뭘 차지하느냐의 차이 i-3까지 차지한다면 i, i-1 먹을수있고
		//i-2까지 차지한다면 i를 먹을수 있다.
		dp[i] = max(dp[i - 3] + arr[i] + arr[i - 1], dp[i - 2] + arr[i]); 
		dp[i] = max(dp[i - 1], dp[i]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	solution();
	cout << dp[n];
	return 0;
}