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
/*
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
*/

/*4673번 셀프넘버
d(n)은 n과 n 자리수를 더하는 함수 d(75)=75+7+5 = 87이다
양의정수 33으로 시작했을때 33+3+3 = 39 / 39+3+9=51.. 등으로 무한수열 만들수있다.
n은 d(n)의 생성자라고 부른다. 위에서 33은 39의 생성자이다.
생성자가 한개 이상인 경우도 있다. 101의 생성자는 91과 100
여기서 생성자가 없는 숫자를 셀프넘버 라고 한다.
100보다 작은 셀프넘버는 13개이다. 1 3 5 7 9 20 31 42 53 64 75 86 97
10000보다 작거나 같은 셀프넘버를 한줄에 하나씩 출력하는 프로그램을 작성하시오
-> 에라토스테네스의 체 알고리즘을 조금 변경하면 풀수있다.
특정한 숫자의 생성자를 구하면 그 숫자의 생성자를 언제 구하든지 항상 동일한 값이
나온다는 특징을 이용한 것.
*/

#include <iostream>
#define MAX 10001

using namespace std;

int a[MAX];
int d[MAX];


int getNext(int x) {
	int sum = x, temp = x, cipher = 1;
	while (temp >= 10) {
		cipher++;
		temp /= 10;
	}
	for (int i = 0; i < cipher; i++) {
		sum += x % 10; //x를 10으로 나눈 나머지를 더한다.
		x /= 10; //x는 x를 10으로 나눈 몫.
	}
	return sum;
}

int main() {
	for (int i = 1; i < MAX; i++) {
		for (int j = getNext(i); j < MAX; j = getNext(j)) {
			if (a[j] == 1)continue;
			else a[j] = 1;
		}
	}
	for (int i = 1; i < MAX; i++) {
		if (a[i] == 0)
			cout << i << '\n';
	}
	return 0;
}