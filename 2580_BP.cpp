//스도쿠를 완성하면 된다.
//가로줄, 세로줄, 네모칸에 1~9 하나씩 들어가야된다.
// map을 가로 세로로 보는건 쉬운데 어떻게 3x3 블럭으로 나눌수있을까 고민. 문자열?
// 백트래킹으로 풀어야하나
// 매칭 알고리즘으로 풀어야될거같다. 만약 뒤에꺼가 그자리에 그거밖에 안들어가는데
// 앞에꺼를 바꿔줄 수 있는지 그렇다면 바꾸는 확인해주는게 필요하다.


/*나는 처음에 접근방식을 main문에서 칸이0일때만 dfs로 들어와서 수행하려고 했다.
그런데 확정이 아니고 예정된 값을은 언제든 바껴야 했고 즉 한번의 dfs내에서 수행
하는것이 나아보임 그래서 0으로 들어와서 전체에 대해 실행함*/

//스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.
//이 말이 젤 중요한것같다. 우리가 흔이 아는 HARD 난이도의 스도쿠는 없다는것.. 대각선X

//백트래킹은 아래와같은 예시를 진행하는 과정으로 설명할 수 있다.
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/
#define MAX 9
#include <iostream>

using namespace std;

int map[MAX][MAX];
int row[MAX][10];
int col[MAX][10];
int square[MAX][10];

int squareindex(int y, int x) {
	return (y / 3) * 3 + x / 3;
}

void sudoku(int cnt) {
	//스도쿠 판을 채우는 방법이 여러개일 경우 하나만 출력하므로 81이 되면 그냥 출력해버리기
	if (cnt == 81) { //총 81칸이므로
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int y = cnt / 9; //cnt에 대해 x,y 좌표를 지정해준다.
	int x = cnt % 9;

	if (map[y][x]) //0이 아니라면
		sudoku(cnt + 1); //다음칸에 대해 dfs 실행
	else {
		for (int k = 1; k <= MAX; k++) {
			if (!col[x][k] && !row[y][k] && !square[squareindex(y, x)][k]) { //다같이 한 숫자가 없다면
				map[y][x] = k;//map상의 0를 k로바꾼다.
				col[x][k] = true; //차례대로 col row square를 채운다.
				row[y][k] = true;
				square[squareindex(y, x)][k] = true;
				sudoku(cnt + 1);
				//하지만 위의 숫자 k가 정답이 아닐수도 있다. k++가 진행되면서 조건에 맞는 다른 숫자가 정답일 수 있다.
				//따라서 이것이 아닐경우 지워주는 작업도 진행해주어야한다.
				map[y][x] = 0;
				col[x][k] = false;
				row[y][k] = false;
				square[squareindex(y, x)][k] = false;
				
			}
		}
	}
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j]) { //0이 아닌 수가 입력되었다면
				col[j][map[i][j]] = true;
				row[i][map[i][j]] = true;
				square[squareindex(i, j)][map[i][j]] = true;
			}
		}
	}
	sudoku(0);
	return 0;
}

/*
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
*/
