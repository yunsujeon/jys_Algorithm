//분할정복 알고리즘

/*1074번 Z
2차원 배열을 z모양으로 탐색하려고 한다. 예를 들어 2*2배열을 Z모양으로 탐색
만약 2*2가 아니라면 2^N*2^N일 수 있는데 이는 배열을 등분하여 z모양으로 탐색
Z Z
Z Z 같이 탐색
N 이 주어졌을 때 (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하라
예제입력)  2 3 1 (N r c) -> 2^2*2^2의 크기
r c는 0,0 부터 출발한다.
예제출력) 11 (번째로 방문)
*/
/*분할을 통해 2*2 크기까지 나누고 시작.*/

#include <iostream>
#include <math.h>
using namespace std;

int N, R, C;
int ans = 0;

void solve(int n, int r, int c) {
	//네개로 분할하다가 이제 마지막 2*2가 됐을때 탐색
	if (n == 2)
	{
		if (r == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r + 1 == R && c == C) {
			cout << ans;
			return;
		}
		ans++;
		if (r + 1 == R && c + 1 == C) {
			cout << ans;
			return;
		}
		ans++;
		return;
	}
	//네개로 계속하여 분할하는 코드
	solve(n / 2, r, c);
	solve(n / 2, r, c + n / 2);
	solve(n / 2, r + n / 2, c);
	solve(n / 2, r + n / 2, c + n / 2);
}

int main() {
	scanf_s("%d %d %d", &N, &R, &C);
	solve(pow(2,N),0,0);
	return 0;
}