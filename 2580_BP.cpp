//스도쿠를 완성하면 된다.
//가로줄, 세로줄, 네모칸에 1~9 하나씩 들어가야된다.
// map을 가로 세로로 보는건 쉬운데 어떻게 3x3 블럭으로 나눌수있을까 고민. 문자열?
// 백트래킹으로 풀어야하나
// 매칭 알고리즘으로 풀어야될거같다. 만약 뒤에꺼가 그자리에 그거밖에 안들어가는데
// 앞에꺼를 바꿔줄 수 있는지 그렇다면 바꾸는 확인해주는게 필요하다.

#define MAX 9

#include <iostream>

using namespace std;

int map[MAX][MAX];

int r[10] = { 0, };
int c[10] = { 0, };
int sq[10] = { 0, };

//조건체크하는 함수

int check(int row, int col){
	int rr=0, cc=0, sqsq=0;
	int nr = row / 3;
	int nc = col / 3;
	int sqrstart;
	int sqrend;
	int sqcstart;
	int sqcend;
	for (int i = 0; i < MAX; i++) {
		if (map[row][i] != 0) {
			r[map[row][i]] = 1;
		}
		if (map[row][i]==0){
			rr++;
		}
		if (map[i][col] != 0) {
			c[map[i][col]] = 1;
		}
		if (map[i][col] == 0) {
			cc++;
		}
	}
	if (nr == 0 && nc == 0) {
		sqrstart = 0; sqrend = 2; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 0 && nc == 1) {
		sqrstart = 0; sqrend = 2; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 0 && nc == 2) {
		sqrstart = 0; sqrend = 2; sqcstart = 6; sqcend = 8;
	}
	else if (nr == 1 && nc == 0) {
		sqrstart = 3; sqrend = 5; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 1 && nc == 1) {
		sqrstart = 3; sqrend = 5; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 1 && nc == 2) {
		sqrstart = 3; sqrend = 5; sqcstart = 6; sqcend = 8;
	}
	else if (nr == 2 && nc == 0) {
		sqrstart = 6; sqrend = 8; sqcstart = 0; sqcend = 2;
	}
	else if (nr == 2 && nc == 1) {
		sqrstart = 6; sqrend = 8; sqcstart = 3; sqcend = 5;
	}
	else if (nr == 2 && nc == 2) {
		sqrstart = 6; sqrend = 8; sqcstart = 6; sqcend = 8;
	}
	for (int i = sqrstart; i <= sqrend; i++) {
		for (int j = sqcstart; j <= sqcend; j++) {
			if (map[i][j] == 0)
				sqsq++;
			if (map[i][j] != 0) {
				sq[map[i][j]] = 1;
			}
		}
	}
	//사전준비완료
	if (rr == 1) {
		return 1;
	}
	if (cc == 1) {
		return 2;
	}
	if (sqsq == 1) {
		return 3;
	}
	else
		return 0;
}

int sudoku(int i,int j) {
	//세 개의 조건 전부 탐색해서 0이 하나인게 있으면 얘는 무조건 그 수로 확정짓자
	int result = check(i, j);
	if(result==1){
		for (int a = 1; a < 10; a++) {
			if (r[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	else if (result == 2) {
		for (int a = 1; a < 10; a++) {
			if (c[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	else if (result == 3) {
		for (int a = 1; a < 10; a++) {
			if (sq[a] == 0) {
				map[i][j] = a;
				return;
			}
		}
	}
	//세 조건 모두 0이 하나만 남은게 아니라면? 다른 0인 애들을 먼저 봐야될듯
	else {// 여기 조건을 모르겠다..
		sudoku(i + 1, j + 1);
	}
}

int main() {

	//입력해주기
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
		}
	}

	//dfs 백트래킹 돌려주기
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] == 0) {
				sudoku(i, j);
			}
		}
	}

	//완료된거 출력해주기
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%d", map[i][j]);
		}
	}
	return 0;
}

