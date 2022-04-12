//타일문제 : 점화식을 잘 세워야된다. 예외의 경우와 조건을 잘 생각해서 식세운다

/*
11726번 2*n타일링문제
2*n 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수를 구하는 프로그램 작성
가장 마지막에 오는 타일을 기준으로 생각해보았을때 가능한 경우는 오직 두가지이다.
1*2 (그전까지는 N-1개) or 2*1 2*1 배치 (그전까지는 N-2개)
*/
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 1) return 1; 
	if (x == 2) return 2;
	if (d[x] != 0) return d[x]; //d[x]가 0이될때까지 dp반복
	return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}

*/

//2*n 직사각형을 1*2 2*1 2*2 타일로 채우는 방법의 수 구하는 프로그램 작성
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3; //3가지 경우의 수
	if (d[x] != 0) return d[x]; //d[x]가 0이될때까지 dp반복
	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007; //N-2개가 남는 상황이 두개가있음
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/

//3*n 크기의 벽을 2*1 1*2 크기의 타일로 채우는 경우의 수는?
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 0) return 1; //못채우는경우
	if (x == 1) return 0;
	if (x == 2) return 3; //3가지 경우의 수
	if (d[x] != 0) return d[x]; //d[x]가 0이될때까지 dp반복
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) { //4개일때부터 짝수개에는 경우가 두가지씩 더들어간다
		if (i % 2 == 0) //짝수개일때
			result += 2 * dp(x - i); //두가지경우씩 추가로 붙여준다.
	}
	return d[x] = result;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/

//2*n크기의 벽을 2*1 1*2 1*1 타일로 채우는 경우의 수를 구해보자
/*
#include <iostream>
using namespace std;
int d[1000001]; 

int dp(int x) {
	if (x == 0) return 1; //못채우는경우
	if (x == 1) return 2;
	if (x == 2) return 7; //3가지 경우의 수
	if (d[x] != 0) return d[x]; //d[x]가 0이될때까지 dp반복
	int result = 3 * dp(x - 2) + 2 * dp(x - 1);
	for (int i = 3; i <= x; i++) { //4개일때부터 하나씩 올라갈때마다 경우가 두가지씩 더들어간다
		result += 2 * dp(x - i); //두가지경우씩 추가로 붙여준다.
	}
	return d[x] = result;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/
//하지만 시간복잡도가 O(N^2) 가 되므로 백만에 대해서는 시간초과가 나게된다.
//따라서 2차원 다이나믹 프로그래밍 기법을 사용해야된다.
//2차원 dp를 씀으로써 예외 계산을 따로 해주고 완료 식에 더해준다. 
#include <iostream>
using namespace std;

long long int d[1000001][2];

long long int dp(int x) {
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]); //[i][1]로 뺀거는 예외를 따로 계산해주기위해서
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]); //완료된 식
	}
	return d[x][0];
}

int main() {
	int x;
	cin >> x;
	printf("%lld", dp(x));
}