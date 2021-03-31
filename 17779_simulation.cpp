//게리맨더링
//BF로 풀수있을듯?
//아니면 dfs와 백트래킹
#include <iostream>
#include <math.h>

using namespace std;

int N;
int map[101][101] = { 0, }; //각 파트별 인구수를 넣어줄것이다.
int MIN = 987654321;

int part(int r, int c, int d1, int d2) { //각 파트별 넓이가 얼마인지 구하고 최소를 리턴
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int l1 = c + 1;
	int l2 = r + d1;
	int l3 = c - (d1 - d2);
	int l4 = r + d2 + 1;
	int virmap[101][101] = { 0, }; 

	for (int i = 0; i < l2; i++) { //5를 포함한 1을 계산
		for (int j = 0; j < l1; j++) {
			virmap[i][j] = 1;
		}
	}
	//5를 포함한 2를계산
	//5를포함한 3을계산
	//5를포함한 4를 계산
	return
}


int solution() { //BF
	for (int i = 0; i < N-2; i++) { //시작점이 밑으로로 한칸씩 이동
		for (int j = 1; j < N-1; j++) { //시작점이 오른쪽ㅇ,로 한칸씩 이동
			//시작점을 짚었다.
			for (int d1 = 1; d1 <= j-2  && d1 <= N - i-2; d1++) { //d설정이 어려웠다.
				for (int d2 = 1; d2 <= N - j-1 && d2 <= N - i-2; d2++) {
					int res = part(i, j, d1, d2);
					if (res <= MIN) {
						MIN = res;
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s;
			map[i][j] = s;
		}
	}
	solution();
	return 0;
}