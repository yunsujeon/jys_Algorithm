
#include <iostream>

using namespace std;

const int MAX = 20;

int N, S;
int arr[MAX];
int cnt = 0;

void hap(int a, int b) {
	b += arr[a];
	if (a >= N) { //만족하면 return해주기
		return;
	}
	if (b == S) {
		cnt++;
	}
	//두갈래길로 나뉘게된다.
	hap(a + 1, b - arr[a]); //안더해주고 다음 인덱스로넘어가기
	hap(a + 1, b); //더해주고 다음인덱스로 넘어가기

}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	hap(0, 0);
	cout << cnt << endl;
	return 0;
}