/*1978번 - 소수찾기
주어진 수 N개 중에서 소수가 몇개인지 판별하는 프로그램
입력) 4		N개의 수 (100개 이하)
1 2 5 7		주어진 수 (1000이하)
풀이 : 에라토스테네스의 체를 이용해 1000이하의 소수를 미리 판별해놓고
입력이 들어오면 이에 대해 소수판별을 진행하면 된다.
*/
#include <iostream>
#define MAX 1001

using namespace std;

int a[MAX];

int main() {
	a[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			// 4 6 8 10 12 14 16 18 ... 2의배수 중 소수인2만빼고
			// 6 9 12 15 18 21 24 27 30 ... 3의배수 중 소수인 3만빼고
			// 8 12 16 20 24 28 32 36 ... 4의배수 중 4는이미제외
			if (a[j] == 1)
				continue;
			else 
				a[j] = 1;
		}
	}
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (a[x] == 0)
			count++;
	}
	cout << count;
	return 0;
}
