
#include<iostream>

using namespace std;

const int MAX = 10001;
int N, M;
int arr[MAX];
int cnt = 0;
int startindex = 1;
int sum = 0;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		startindex = i;
		sum = 0;
		while (1) {
			if (startindex == N + 1)
				break;
			sum += arr[startindex];
			if (sum == M) {
				cnt++;
				break;
			}
			else if (sum > M)
				break;
			startindex++;
		}
	}
	cout << cnt << endl;
	return 0;
}