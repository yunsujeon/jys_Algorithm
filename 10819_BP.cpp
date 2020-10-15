//next_permutation을 이용하여 순열을 구한다.
//순열 : 1,2,3,4로 1 3 2 4 / 4 2 3 1 등 의 순서를 바꿔준것의 모음


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N,s,temp;
	int arr[8];
	int sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr[i] = s;
	}

	sort(arr, arr + N);
	
	do {
		temp = 0;
		for (int i = 0; i < N - 1; i++) {
			temp += abs(arr[i] - arr[i + 1]);
		}
		sum = max(sum, temp);
	} while (next_permutation(arr, arr + N));
	//순열을 바꿔주는 함수이다.
	
	cout << sum << endl;
}