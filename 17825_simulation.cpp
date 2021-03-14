/*
#include <iostream>

using namespace std;

int dice[10]; //주사위에서 무슨 수가 나올지 알고있음
int load0[21] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40 };
int load1[5] = { 10,13,16,19,25 };
int load2[4] = { 20,22,24,25 };
int load3[5] = { 30,28,27,26,25 };
int load4[4] = { 25,30,35,40 };

int solution() {
	int i = 0;
	int flag = 0;
	int loc = 0;
	int result = 0;
	while (i<10) { //열 번 돌자
		int dicenum = dice[i];
		i++;
		loc += dicenum;
		if (flag == 0) {
			if (load0[loc] == 10) {
				flag = 1;
				loc = 0;
			}
			else if (load0[loc] == 20) {
				flag = 2;
				loc = 0;
			}
			else if (load0[loc] == 30) {
				flag = 3;
				loc = 0;
			}
			result += load0[loc];
		}
		if (flag == 1) {
			result += load1[loc];
			if (load1[loc] == 25) flag = 4;
		}
		if (flag == 2) {
			result += load2[loc];
			if (load2[loc] == 25) flag = 4;
		}
		if (flag == 3) {
			result += load3[loc];
			if (load3[loc] == 25) flag = 4;
		}
		if (flag == 4) {
			result += load4[loc];
		}
		
	}
	return result;
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	cout << solution() << endl;
	return 0;
}
*/
/*해결함에 있어 최대값을 만들 수 있는 경로를 생각해보자
한번 출발한 것을 최대한 뒤쪽으로 가게하는게 젤좋다
말을 업을 수는 없다
도착 칸에 들어가더라도 얻는 포인트가 없으니 굳이
들어갈 필요는 없으나 말을 업을수가 없으므로
들어가줌으로써 다른애가 그 자리를 먹을 수 있다면 비켜준다

*/


//하드코딩말고 dfs를 통한 BP 와 back tracking으로 풀어주자

/*
#include <iostream>

using namespace std;

int arr[10];
int mal[4];
int map[35]; //다음 이동할 노드 번호를 저장
int turn[35]; //방향전환되는 10,20,30 을 관리
int check[35]; //해당 노드에 말이있는지 여부
int score[35]; //각 노드의 점수를 관리
int ans = 0;

void setting() {
	for (int i = 0; i < 21; i++) {
		map[i] = i + 1;
	}
	map[21] = 21;
	for (int i = 22; i < 27; i++) {
		map[i] = i + 1;
	}
	map[28] = 29;
	map[29] = 30;
	map[30] = 25;
	map[31] = 32;
	map[32] = 25;
	map[27] = 20;
	turn[5] = 22;
	turn[10] = 31;
	turn[15] = 28;
	turn[25] = 26;
	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[22] = 13;
	score[23] = 16;
	score[24] = 19;
	score[31] = 22;
	score[32] = 24;
	score[28] = 28;
	score[29] = 27;
	score[30] = 26;
	score[25] = 25;
	score[26] = 30;
	score[27] = 35;
}

void dfs(int cnt, int sum) {
	//종료조건을 만들어준다
	if (cnt == 10) { //열번의 움직임을 다 수행했고
		if (sum > ans) //큰값으로 갱신
			ans = sum;
		return; //반환
	}
	//웬만하면 0을 수행하나 그게아니면 1,2,3번말을 움직이도록
	for (int i = 0; i < 4; i++) {
		int prev = mal[i]; //현재의 말
		int now = prev;
		int move = arr[cnt]; //몇칸이나 움직일지
		if (turn[now] > 0) { //turn하는 칸이면
			now = turn[now]; //현재 위치를 turn 한다
			move -= 1;
		}
		//움직이는 만큼 while문 돌려준다.
		while (move--) {
			now = map[now];
		}
		if (now != 21 && check[now] == true) //이미 차있는 곳이면서 도착지점이 아니면 다른 말을 사용한다
			continue;
		check[prev] = false;
		check[now] = true;
		mal[i] = now;

		dfs(cnt + 1, sum + score[now]);
		//백트래킹
		mal[i] = prev;
		check[prev] = true;
		check[now] = false;
	}
}

int main() {
	setting();
	// 주사위 입력 받기
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}
*/




#include <iostream>

using namespace std;

int arr[10];
int map[32];
int turn[32];
int mal[4];
int score[32];
int ans = 0;
int check[32];

void dfs(int cnt, int sum) {
	//return 할 조건을 만들어준다.
	if (cnt == 10) {
		if (sum >= ans) {
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int prev = mal[i]; //현재의 말 선택, backtracking 해주기 위해 설정
		int now = prev; //now 를 가지고 움직일거다.
		int move = arr[cnt]; //arr에 저장된 만큼 움직일거다
		if (turn[now]>0) { //어디서부터 움직이는지와 몇칸 움직이는지를 알았다면 방향정해야된다.
			now = turn[now]; //방향돌려서 한 칸 더 간꼴이 되므로
			move -= 1; //한칸 이동덜할거다
		}
		while (move--) {
			now = map[now];
		}
		if (now != 21 && check[now] == true) {
			continue;
		}
		check[prev] = false;
		check[now] = true;
		mal[i] = now; //말에 현재위치를 기록한다.
		dfs(cnt + 1, sum + score[now]);
		check[prev] = true;
		check[now] = false;
		mal[i] = prev;
	}
}

void settings() {
	for (int i = 0; i < 21; i++) { //총 21개
		map[i] = i + 1; //다음 인덱스를 가리킨다.
	}
	map[21] = 21; //도착지점
	for (int i = 22; i < 27; i++) {
		map[i] = i + 1;
	}
	map[27] = 20;
	map[28] = 29;
	map[29] = 30;
	map[30] = 25;
	map[31] = 32;
	map[32] = 25;

	turn[5] = 22;
	turn[20] = 31;
	turn[15] = 28;

	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[22] = 13;
	score[23] = 16;
	score[24] = 19;
	score[31] = 22;
	score[32] = 24;
	score[28] = 28;
	score[29] = 27;
	score[30] = 26;
	score[25] = 25;
	score[26] = 30;
	score[27] = 35;
}

int main() {
	settings();
	for (int i = 0; i <= 10; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	return 0;
}