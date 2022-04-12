/*
토지 개발
소마는 가로 세로의 크기가 1로 이뤄진 작은 칸들이 가로로 N개 연결된 토지를 소유하고 있다.
(단, N은 2의 지수 승으로써 2, 4, 8, 16, 32, … 이다) 토지의 각 칸에는 토지를 개발함으로써 얻을 수 있는 이익이 적혀 있으며, 
토지는 아래와 같은 형태로 개발한다.

토지를 개발할 때에는 토지를 절반으로 나누어 한쪽 절반에 해당하는 부분을 모두 활용하여 개발해야 한다.
특정 부분을 모두 활용하여 개발할 때 얻을 수 있는 이익은, 해당 부분에서 개발로 얻을 수 있는 이익 중 최댓값이다.
예를 들어, 아래와 같이 토지가 주어져 있다고 하자.

img1
▲ 크게보기

그렇다면, 아래와 같이 좌/우로 나누어 개발할 수 있는 두 가지 선택지가 있다.

img2
▲ 크게보기

왼쪽의 경우 얻을 수 있는 이익은 최댓값인 10이며, 오른쪽의 경우 얻을 수 있는 이익은 최댓값인 6이다. 이렇게 개발을 하고 난 이후에는
해당 면적을 더 개발하지 못하며, 남은 면적만을 활용하여 개발해야 한다. 예를 들어, 처음에 왼쪽 절반을 개발했다고 하자. 그렇게 되면
아래와 같이 두 가지 선택지가 존재하게 된다.

img3
▲ 크게보기

이때 개발을 통해 얻을 수 있는 이익은 각각 6, 3이다. 위의 과정을 반복해서 절반씩 개발하다 보면 맨 마지막에는 결국 두 개의 칸이 남게 된다.
그 두 개의 칸을 또 절반으로 나누어 한 개의 칸을 개발하면, 마지막에 최종적으로 하나의 칸이 남게된다. 이와 같이 남은 칸이 1개일 경우에는 
해당 칸에서 이익을 얻을 수 없으며 개발을 종료한다. 위 규칙을 토대로 예시의 토지를 모두 개발했을 때 소마는 이익의 합으로 최대 19 만큼의 
이익을 얻을 수 있다.

크기가 N인 토지와 각각의 칸에 대한 이익이 주어질 때, 토지 개발을 통해 소마가 얻을 수 있는 이익의 합 중 최댓값을 출력하시오.

입력
첫 번째 줄에 토지의 크기 정수 N을 입력받는다.
N = 2^M
1 ≦ M ≦ 10
이후 두 번째 줄에 공백을 구분자로 가장 왼쪽부터 각 칸의 개발 이익 값 NN개를 입력받는다. (입력되는 개발 이익 값은 모두 양의 정수이다.)
출력
토지 개발을 통해 소마가 얻을 수 있는 이익의 합 중 최댓값을 출력한다.
입력 예시
8
1 3 10 9 6 2 3 2
출력 예시
19
*/

/*
그냥 비교해서 그리디로 푸는 방법은 조건을 충족하지 못할것이다 (그리디는 생각보다 어려운 프로그래밍 기법이다.)
내가 푼다하면 그냥 시뮬레이션적 풀이로 그리디로 풀겠지만 모든 테케를 만족할수는 없을수도 있다.

그래서 이사람은 굳이 dp를 이용한 풀이를 제시함
1. 테이블 정의 dp[i][j] -> i번부터 j번 땅들을 이용해서 얻을 수 있는 최대 개발 이익
2. dp[1][n]에 써있는 걸 출력하면 될것
3. 최소문제들에 대해 초기값을 설정해줄것 dp[i][i+1] //만약 땅이 두개밖에 없을 때 정답은? 둘중 하나를 선택하면 될것
4. 점화식
DP[i][j] = ?
- 1. 왼쪽(1~m)을 선택(max를 씌우면 될것), 오른쪽(m+1~j)을 마저 개발(DP[m+1][j]의 값이 될 것
- 2. 반대의 경우 DP[i][m] + 오른쪽의 max 해주면 될것
따라서 DP[i][j] = max(DP[i][m]+max(a[m+1 ... j]), max(a[i ... m], DP[m+1][j]))

top-down 방식
int solve(int left, int right) {
	if (dy[eft][right] != 0)
		return dy[left][right];
	if (left + 1 == right) {
		return dy[left][right] = max(a[left], a[right]);
	}
	int m = (left + right) / 2;
	//왼쪽 절반을 선택하는경우
	int select_left = *max_element(a + left, a + m + 1) + solve(m + 1, right);
	//오른쪽 절반 선택경우
	int select_right = *solve(left, m) + m * max_element(a + m + 1, a + right + 1);

	return DP[left][right] = max(select_left, select_right); //둘중 큰걸고르면 된다.

}

bottom-up 으로 풀게되면
void solve2() {
	for (int i = 1; i <= N; i += 2) {
		dy[i][i + 1] = max(a[i], a[i + 1]);
		for (int size = 4; size <= N; size += 2) {
			for (int left = 1; left <= N; left += size) {
				//left~left+size-1 까지에 대해서
				int right = left + size - 1;
				int mid = left + size / 2-1;
				int select_left = *max_element(a + left, a + m + 1) + dy[m + 1][right];
				//오른쪽 절반 선택경우
				int select_right = dy[left[m] + m * max_element(a + m + 1, a + right + 1);
				dy[ileft][right] = max(select_left, select_right);
				
			}
	}
	}
	cout << dy[1][N];
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int t;
int a[1030];
int DP[1030][1030];

//top-down 방식
int solution(int left, int right) { //1번부터 N번까지의 최대의 이익
	if (DP[left][right] != 0) //만약 이 문제를 푼적이 있다면
		return DP[left][right]; //리턴한다

	if (left + 1 == right) { //가장 작은 문제라면, 즉 초기값
		return DP[left][right] = max(a[left], a[right]);
	}

	int m = (left + right) / 2; //초기가 아니라면 반으로 나눠야지
	//왼쪽 절반을 선택하는경우
	int select_left = *max_element(a + left, a + m + 1) + solution(m + 1, right);
	//max_element는 구간에서의 최대값의 주소를 리턴한다 따라서 *를 붙여준다.
	//오른쪽 절반 선택경우
	int select_right = solution(left, m) + *max_element(a + m + 1, a + right + 1);

	return DP[left][right] = max(select_left, select_right); //둘중 큰걸고르면 된다.

}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	cout << solution(1, N);
	return 0;
}