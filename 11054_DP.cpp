
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int N;
int arr[MAX] = { 0, };
int leftdp[MAX];
int rightdp[MAX];
int result[MAX];
int val=0;

void solution() {
	//따로따로 구해야될것이다. 증가부와 감소부 1053번 참고
	leftdp[0] = 1;
	for (int i = 1; i < N; i++) {
		leftdp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j]<arr[i] && leftdp[j]+1>leftdp[i]) { //갈수록 더 최신의 값을 받을것이다.
				leftdp[i] = leftdp[j] + 1;
			}
		}
	}
	
	rightdp[N - 1] = 1;
	for (int i = N-2; i >=0; i--) {
		rightdp[i] = 1;
		for (int j = N-1; j > i; j--) {
			if (arr[j] < arr[i] && rightdp[j] + 1 > rightdp[i]) {
				rightdp[i] = rightdp[i] + 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		result[i] = leftdp[i] + rightdp[i];
		if (val < result[i])
			val = result[i];
	}
	
	cout << val << '\n';

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solution();
	return 0;
}
