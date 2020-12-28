
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int T;
int n;
int arr[2][MAX];
int dp[2][MAX];
int result;

void solution(){
	//dp[0or1][n까지]
	
	//초기설정
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[0][1] + arr[1][0];
	dp[1][1] = arr[0][0] + arr[1][1];

	//dp 알고리즘을 생각해내는게 어렵다.
	//https://m.blog.naver.com/occidere/220786307316 이 블로그 참고함

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j == 0) {
				dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[j][i];
			}
			else {
				dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + arr[j][i];
			}
		}
	}
	result = max(dp[0][n-1], dp[1][n-1]);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		solution();
		cout << result << '\n';
		memset(arr, false, sizeof(arr));
	}
	return 0;
}