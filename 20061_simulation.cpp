#include <iostream>
#include <string>

using namespace std;

int map[10][10] = { 0, };
int N, t, x, y;
int result;

void input() {
	if (t == 1) { //블럭하나
		for (int i = 4; i <= 9; i++) { //파란색에 넣어준다.
			if (i == 9) { //9로 가면 i+1이 존재하지 않기때문에 9에 넣어준다.
				map[x][i] = 1;
				break;
			}
			if (map[x][i + 1] == 1) { //그다음게 막혀있다면
				map[x][i] = 1; //i 칸에 1을 넣고 break 한다.
				break;
				//만약 막혀있지 않다면 i가 break되지않고 계속 증가할것
			}
		}
		for (int i = 4; i <= 9; i++) { //초록색에 넣어준다.
			if (i == 9) {
				map[i][y] = 1;
				break;
			}
			if (map[i + 1][y] == 1) {
				map[i][y] = 1;
				break;
			}
		}
	}
	else if (t == 2) { // 가로로 두칸짜리가 들어갈때
		int idx = 10; // 하나도 없을때는 map[x][i]==1에 걸리지 않기때문에 조치가 필요하다.
		for (int i = 4; i <= 9; i++) { //파란색에 들어갈 때
			if (map[x][i] == 1){ //그칸이 막혀있다면 이 전칸 두개에 넣어줘야됨
				idx = i;
				break;
			}
		}
		map[x][idx - 1] = 1; //걸리든 안걸리든 한번에 여기서 넣어준다.
		map[x][idx - 2] = 1;

		idx = 10;

		for (int i = 4; i <= 9; i++) { //초록색일때 2번은 가로로 들어갈것이다.
			if (map[i][y] == 1 || map[i][y + 1] == 1) {
				idx = i;
				break;
			}
		}
		map[idx - 1][y] = 1; 
		map[idx - 1][y + 1] = 1;
	}
	
	else if (t == 3) {
		int idx = 10;
		for (int i = 4; i <= 9; i++) { //파란색일때 3번은 가로로 들어간다.
			if (map[x][i] == 1 || map[x + 1][i] == 1) { //둘중하나 막혀있다면 못들어가
				idx = i;
				break;
			}
		}
		map[x][idx - 1] = 1;
		map[x + 1][idx - 1] = 1;

		idx = 10;
		for (int i = 4; i <= 9; i++) { //초록색
			if (map[i][y] == 1) {
				idx = i;
				break;
			}
		}
		map[idx - 1][y] = 1; 
		map[idx - 2][y] = 1;
	}
}

void cntplus() {
	for (int i = 9; i >= 6; i--) { //파란색일때 열을 지워가며 점수올린다.
		int flag = 0; //열을 돌때마다 플래그를 세운다.
		for (int j = 0; j < 4; j++) {
			if (map[j][i] == 0) { 
				flag = 1; //하나라도 0이면 flag가 1이 될것 
				break; 
			}
		}
		if (flag == 0) { //해당 i 열이 1로 꽉 찬경우
			result++; //점수를 한점 올린다.
			for (int k = i; k >= 4; k--) { //이동시키기
				for (int l = 0; l < 4; l++) {
					map[l][k] = map[l][k - 1];  //한칸씩 뒤로 민다.
				}
			}
			i++; //다 1이여서 한칸씩 미룬 경우에는 다시 i부터 확인해줘야될 것이다.
		}
	}
	//초록색
	for (int i = 9; i >= 6; i--) {
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 0) { 
				flag = 1; 
				break;
			}
		}
		if (flag == false) {
			result++;
			for (int k = i; k >= 4; k--) {
				for (int l = 0; l < 4; l++) {
					map[k][l] = map[k - 1][l]; 
				}
			}
			i++; 
		}
	}
}

void pastel() { //연한 경우 
	int checkingcount = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[j][i] == 1) { 
				checkingcount++; //몇칸을 미룰지 결정하는 count이다
				break; 
			}
		}
	}
	if (checkingcount != 0) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				map[j][i] = map[j][i - checkingcount];
			}
		}
	}
	for (int i = 4; i <= 5; i++) { //처음 input을 줄때 3열에 input이 들어갈 수도 있었다.
		for (int j = 0; j < 4; j++) { //따라서 여기서 4,5 전체를 비워준다.
			map[j][i] = 0;
		}
	}
	//연한 초록색
	checkingcount = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) {
				checkingcount++;
				break; 
			}
		}
	}
	if (checkingcount != 0) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = map[i - checkingcount][j];
			}
		}
	}
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y; //x,y에 넣고 바로 실행하니 어디있는지 찾는과정이 필요없다.
		input(); //블럭을 파란색, 초록색으로 집어넣기
		cntplus(); //꽉찬 행,열을 지우고 점수를 획득한다.
		pastel(); //연한 곳 처리
	}
	cout << result << endl;
	int hap = 0;
	for (int i = 9; i >= 4; i--) {
		for (int j = 0; j <= 3; j++) {
			if (map[j][i] == 1)
				hap += 1;
			if (map[i][j] == 1)
				hap += 1;
		}
	}

	cout << hap;
	return 0;
}