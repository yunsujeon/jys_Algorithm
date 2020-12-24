#include <iostream>

using namespace std;
const int MAX = 4000000;

int a[MAX];
int res[MAX];
int N;

void eratosthenes() { //소수를 판별해서 배열을 만들자
	for (int i = 2; i <= MAX; i++) {
		a[i] = i; //배열을 다 초기화해준다.
	}
	for (int i = 2; i <= MAX; i++) {
		if (a[i] == 0) continue; //이미 방문했던곳은 방문하지않는다.
		for (int j = i + i; j <= MAX; j += i) { //배수
			a[j] = 0; //방문처리
		}
	}
	int cnt = 0;
	for (int i = 2; i <= MAX; i++) {
		if (a[i] != 0) //0으로 변하지 않은 남은 소수부분 출력
			res[cnt++] = i;
	}
}

int main() {
	eratosthenes();
	cin >> N;
	int M;
	for (int i = 0; i < MAX; i++) {
		if (res[i] >= N) {
			M = i + 1;//쓰는 배열 개수
			break;
		}
	}
	//투포인터 알고리즘 이용하자
	int sum = 0, count = 0, left = 0, right = 0;
	while (1) {
		if (sum >= N) {
			sum -= res[left++];
		}
		else if (right == M)
			break;
		else
			sum += res[right++];
		if (sum == N)
			count++;
	}
	cout << count << endl;
	return 0;
}
