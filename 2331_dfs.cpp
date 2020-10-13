//반복수열
#include <iostream>
#include <cmath>
using namespace std;

//floor를 이용한 반올림함수 : floor에 0.5를 더해주면 반올림이된다.
int result=0;
int visit[1000000];

int mult(int A, int P) {
	int next = 0;
	while (A > 0) {
		next = (int)floor(pow(A % 10, P) + 0.5) + next;
		A /= 10; //A의 모든자리수를 해줘야되기때문이다.
		// 9876였다면 9876%10 = 6 -> /10 = 987 -> 987%10 = 7 이런식으로 하나씩 감해간다
	}
	return next;
}
void dfs(int A, int P) {
	visit[A]++; // true로 두면 계속 1일테니..
	if (visit[A] > 2) {
		return;
	}
	dfs(mult(A, P), P);
}

int main() {
	int A, P;
	cin >> A >> P;
	dfs(A, P);

	for (int i = 0; i < 1000000; i++) { //1000000까지 반복해서 구해준다.
		if (visit[i] == 1) { //딱한번만 나온걸 result+해줘야됨
			result++; 
		}
	}
	cout << result;
}