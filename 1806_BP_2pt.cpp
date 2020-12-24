//부분합
/*
#include <iostream>

using namespace std;
const int MAX = 100001;

int N, S;
int arr[MAX];
int startidx,realstart = 0;
int sum=0;
int result=0;
int resMIN=100001;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	for (int i = 0; i < N; i++) { //시작점을 하나씩 올려준다.
		realstart = i;
		startidx = i;
		sum = 0;
		while (1) {
			if (realstart ==N || startidx == N) {//시작점이 선넘으면
				break;
			}
			sum += arr[startidx];
			if (sum >= S) {
				result = startidx - realstart+1;
				if (result < resMIN)
					resMIN = result;
				break;
			}
			startidx++;
		}
	}
}

int main() {
	input();
	solution();
	if (resMIN == 100001)
		resMIN = 0;
	cout << resMIN << endl;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
const int INF = 987654321;

int arr[MAX];

int main() {

	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int low = 0, high = 0; //포인터 두 개
	int sum = arr[0]; //0번째 인덱스의 값으로 초기화
	int result = INF;

	while (low <= high && high < N) {
		if (sum < S)
			sum += arr[++high];
		else if (sum == S) { //sum과 같다면
			result = min(result, (high - low + 1)); //result설정
			sum += arr[++high]; 
		}
		else if (sum > S) {
			result = min(result, (high - low + 1));
			sum -= arr[low++];
		}
	}
	if (result == INF)
		cout << 0 << "\n";
	else
		cout << result << "\n";
	return 0;
}