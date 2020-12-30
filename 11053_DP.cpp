
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int arr[MAX];
int N;
int DP[MAX]; 
int result = 1;

//생각의 흐름 1 : DP안쓰고 반복문으로만 -> 1 100 2 3 4 처리 X
//생각의 흐름 2 : DP순서를 앞에서 뒤로가면서 큰거나오면 처리
//생각의 흐름 3 : 뒤에서 앞으로 오면서 작은거나오면 처리
//생각의 흐름 4 : 앞에서 한칸씩 뒤로가면서 다시 앞을 훑으며 작은거찾아 DP채워나가기
//생각의 흐름 5 : 앞에서 한칸씩 뒤로가면서 다시 앞을 훑으며 큰거찾아 DP채워나가기

/*
int solution() {
	//끝에 수부터 결과를 만들어서 DP로 풀어보자
	for (int i = 0; i < N; i++) {
		DP[i][i] = 1;
	}
	//DP[i][j] 란 i에서 시작해서(i를 꼭 포함) j번째까지의 값
	for (int i = 0; i < N - 1; i++) { //전체과정을 0번째부터 시작했을때 값 도출
		int pointer = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] > arr[i] && (arr[j]>arr[pointer]||arr[j]>arr[j-1])) { //바로 앞에값보다 크고 시작한값보다는 필수로 크면
				DP[i][j] = DP[i][j - 1] + 1;
				pointer = j;
			}
			else
				DP[i][j] = DP[i][j - 1];
			if (j == N - 1)
				maxarr = DP[i][j];
		}
		if (ne < maxarr)
			ne = maxarr;
	
	}
	return ne;
}
*/

/*
10
1 100 2 3 4 5 6 7 8 9
이 예시로 확인할수있다.
*/
int solution() {
	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
			}
		}
		result = max(result, DP[i]);
	}
	return result;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int result = solution();
	cout << result << '\n';
	return 0;
}