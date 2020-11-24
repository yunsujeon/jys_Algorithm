//까다로운 한붓그리기 문제
//좌표가 음수도 포함하므로 배열로 방문여부 표시불가
// 500을 더하는 방식 -> 겹치지 않는 직사각형을 방문할 여부가 있다.
// 500을 더하고 2를 곱해준다. (모눈종이처럼 색을칠하기위해)
//이 후 직사각형의 각 점을 하나씩 방문했다는 값으로 변경해준다.
//주의 : 맨 처음시작할때 0,0에서 펜 내렸으므로 1000,1000방문했다면 1빼주자

#include <iostream>
#include <vector>
#include <queue>
#define MAX 2001

using namespace std;

int MAP[MAX][MAX]; //이게 마이너스값이 들어갈수없기때문에
bool visit[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

//main과 solution 또는 dfs와 solution을 합친 코드를 만들면?

void dfs(int y, int x) {
	if (y < 0 || x < 0 || x >= MAX || y >= MAX) //범위가아니면
		return;
	if (MAP[y][x] == 2 || MAP[y][x] == 0) //dfs종료의 조건
		//MAP이 1이 아니고 2(이미dfs를거쳤다) 0(아무것도없다)
		return;
	MAP[y][x] = 2; //dfs방문처리해준다.
	for (int i = 0; i < 4; i++) { //방향을 모두탐색하여 dfs해준다.
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(ny, nx);
	}
}

void solution() {
	int cnt;
	cnt = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (MAP[i][j] == 1) { //탐색하다가 드디어 칠해져있는 곳을 만났다면
				dfs(i, j); //dfs를 하고 
				cnt++; //한붓그리기 종료되었으므로 ++해준다.
			}
		}
	}
	if (MAP[1000][1000] == 2) //1000 , 1000 이라는것은 0,0이다.
		cnt--; //0,0거쳤다면 cnt를 하나 줄여준다. 이미 펜을 내렸었기때문
	cout << cnt << endl;
}

int main() {
	int N;
	int x1, y1, x2, y2;
	cin >> N;
	//입력받는 부분이 중요할것
	//한붓그리기와 동일

	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;
		for (int i = x1; i <= x2; i++) {
			MAP[y1][i] = 1;
			MAP[y2][i] = 1;
		}
		for (int i = y1; i <= y2; i++) {
			MAP[i][x1] = 1;
			MAP[i][x2] = 1;
		}
	}
	solution();

	return 0;
}