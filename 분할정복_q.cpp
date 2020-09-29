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

/*
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
*/

/* 1992번 쿼드트리 
흑백영상을 압축하여 표현하는 데이터구조 - 쿼드트리
주어진 영상이 모두 0으로만 되어있으면 압축결과는 0, 모두 1로만 되어있으면 결과는 1이다.
압축하지 못하면 그대로 나타낸다
0000 0001 1111 1000 이면 (0 (0001) 1 (1000)) 이다.
N*N 크기의 영상이 주어질때 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오
ex) 입력
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011
ex ) 출력
((110(0101))(0010)1(0001))

분할을 하고 각각의 결과를 문자열 형태로 합칠때 만약 모두 동일한 문자열이면서 길이가 1이라면
합쳐서 하나만 적어주도록한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 64

#include <iostream>

using namespace std;

char a[MAX][MAX];

string solve(int n, int i, int j) {
	//2*2 까지가 아니고 1개단위까지 다 쪼갠다.
	if (n == 1) {
		return string(1, a[i][j]);
	}
	string a = solve(n / 2, i, j);
	string b = solve(n / 2, i, j + n / 2);
	string c = solve(n / 2, i + n / 2, j);
	string d = solve(n / 2, i + n / 2, j + n / 2);
	if (a == b && a == c && a == d && a.length() == 1) {
		return a;
	}
	else {
		return "(" + a + b + c + d + ")";
	}
}

int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; //엔터치면 자동으로 2차원배열된다..
	}
	cout << solve(n, 0, 0);
	return 0;
}
