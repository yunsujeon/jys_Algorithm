//게리맨더링
//BF로 풀수있을듯?
//아니면 dfs와 백트래킹
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[21][21] = { 0, }; //각 파트별 인구수를 넣어줄것이다.
int MIN = 987654321;

int part(int r, int c, int d1, int d2) { //각 파트별 넓이가 얼마인지 구하고 최소를 리턴
	int l1 = c + 1;
	int l2 = r + d1;
	int l3 = c - (d1 - d2);
	int l4 = r + d2 + 1;
	int number[5] = { 0, };
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j<=  N; j++) {
			if (i < l2 && j <= c && !(i >= r && j >= c - (i - r))) {
				number[0] += map[i][j];
			}
			else if (i<l4 && j>c && !(i >= r && j <= c + (i - r))) {
				number[1] += map[i][j];
			}
			else if (i >= l2 && j < l3 && !(i <= r + d1 + d2 && j >= (c - d1 + d2 - (r + d1 + d2 - i)))) {
				number[2] += map[i][j];
			}
			else if (i >= l4 && j >= l3 && !(i <= r + d1 + d2 && j <= (c - d1 + d2 + (r + d1 + d2 - i)))) {
				number[3] += map[i][j];
			}
			else { //5인 경우
				number[4] += map[i][j];
			}
		}
	}
	sort(number, number + 5);
	int min = number[0];
	int max = number[4];
	int res = max - min;

	return res;
}


int solution() { //BF
	for (int i = 1; i <= N-2; i++) { //시작점이 밑으로로 한칸씩 이동
		for (int j = 2; j <= N-1; j++) { //시작점이 오른쪽ㅇ,로 한칸씩 이동
			//시작점을 짚었다.
			for (int d1 = 1; d1 <= j-1  && d1 <= N - i-1; d1++) { //d설정이 어려웠다.
				for (int d2 = 1; d2 <= N - j && d2 <= N - i-1; d2++) {
					int result = part(i, j, d1, d2);
					if (result <= MIN) {
						MIN = result;
					}
				}
			}
		}
	}
	return MIN;
}

int main() {
	int s;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> s;
			map[i][j] = s;
		}
	}
	cout << solution() << '\n';

	return 0;
}