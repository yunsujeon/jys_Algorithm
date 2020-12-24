
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

/*2포인터 방법
#include <iostream>

using namespace std;
const int MAX = 10000;

int main(){
	int N, M, arr[MAX];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int left = 0, right = 0, sum=0, count =0;
	while(1){
		if(sum>=M)
			sum-=arr[left++]; //빼주고 left증가
		else if(right ==N) //끝내버리자
			break;
		else //아니라면 더해주고 right++
			sum += arr[right++];
		if(sum==M) //조건만족시 count++
			count++;
	}
	cout << count << "\n";
	return 0;
}
*/