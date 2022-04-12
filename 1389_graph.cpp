//케빈베이컨의 수가 가장 작은 사람
//모든 사람과 게임을 했을 때 합이 가장 작은 사람

#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
int fnd[101][101] = { 0, };
int d[101][101] = { 0, }; //거리배열
int result=INF;

int main() {
	int A, B, result_index;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		fnd[A][B] = 1;
		fnd[B][A] = 1;
	}

	// d 초기화
	for (int i = 1; i <= N; i++) { //사람 수
		for (int j = 1; j <= N; j++) {
			if (fnd[i][j] != 0) { //연결이 있다면
				d[i][j] = fnd[i][j]; //값을 넣어준다.
			}
			else { //연결이 없다면
				d[i][j] = INF; //무한대값
			}
		}
	}
	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) { //k를 거쳐가는경우를 따져준다.
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int result_bar[101] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			else {
				result_bar[i] += d[i][j];
			}
		}
		if (result_bar[i] < result) {
			result = result_bar[i];
			result_index = i;
		}
	}

	cout << result_index << '\n';

	return 0;
}