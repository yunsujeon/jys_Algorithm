/*1978번 - 소수찾기
주어진 수 N개 중에서 소수가 몇개인지 판별하는 프로그램
입력) 4		N개의 수 (100개 이하)
1 2 5 7		주어진 수 (1000이하)
풀이 : 에라토스테네스의 체를 이용해 1000이하의 소수를 미리 판별해놓고
입력이 들어오면 이에 대해 소수판별을 진행하면 된다.
*/
/*
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
*/

/*1929번 소수구하기
N과 M사이에 있는 소수를 구하는 문제이다. 다만 숫자의 크기가 최대 1000000까지
나올수 있다는 점에서 반드시 에라토스테네스의 체 알고리즘을 적용해야됨*/
/*
#include <iostream>
#define MAX 1000001

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
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (a[i] == 0)
			cout << i << '\n';
	}
	return 0;
}
*/

/*6588번 골드바흐의 추측
특정한 짝수가 두 소수의 합으로 이루어지는 성질을 프로그램으로 구현하는 문제
시간 복잡도 계산이 굉장히 빡빡한 편
추측내용 : 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오
입력 :
8
20
0 //마지막에는 0을 붙인다.
출력 : 
8 = 3 + 5
20 = 3 + 17
*/

#include <iostream>
#define MAX 1000001
using namespace std;

int a[MAX];

int main() {
	a[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			if (a[j] == 1)
				continue;
			else
				a[j] = 1;
		}
	}
	while (1) {
		int n;
		scanf_s("%d", &n); //여러 숫자 입력해도됨.
		if (n == 0)
			break;
		bool find = false;
		for (int i = n; i >= n / 2; i--) { //20 부터 10까지 -
			if (a[i] == 0 && a[n - i] == 0) { //빼가는 두 수가 둘다 소수일때
				printf("%d = %d + %d\n", n, n - i, i);
				find = true;
				break;
			}
		}
		if (!find) {
			printf("찾지못했습니다.\n");
		}
	}
	return 0;
}