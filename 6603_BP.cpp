//꼭 6개의 숫자를 골라야한다. 주어진 수 중에서.

#define MAX 6
#include <iostream>
#include <string.h>

using namespace std;

int k, input[13];
int result[MAX];

void print(int a, int b) { //재귀를 이용한 완전탐색으로 해결
	if (b == MAX) { //6개 만들면 출력하고 탈출
		for (int i = 0; i < MAX; i++) {
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = a; i < k; i++) {
		result[b] = input[i];
		print(i + 1, b + 1);
	}
}

int main() {
	cin >> k;
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> input[i]; //6~13 입력가능
		}

		print(0, 0);
		cout << endl;

		memset(input, 0, sizeof(input));
		memset(result, 0, sizeof(result));
		cin >> k;
	}
	return 0;
}