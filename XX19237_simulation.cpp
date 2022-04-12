#define MAX 21

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, k;
vector <int> map[MAX][MAX]; //map에 여러마리 상어가 존재할 수 있으니 vector로 선언하자
vector <pair<int, int>> smellmap[MAX][MAX];
vector <int> tempmap[MAX][MAX]; //map에 여러마리 상어가 존재할 수 있으니 vector로 선언하자
vector <pair<int, int>> smelltempmap[MAX][MAX];
int sharkstate[MAX];
int sharkd[MAX][4][4];

int a = 1;
int b = 2;

void spread() { //상어가 자신의 냄새를 뿌린다. move전에
	//자신의 위치에 자신의 냄새를 뿌린다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j][0] != 0) { //spread를 할땐 0번에밖에 존재하지 않을테니
				smellmap[i][j].push_back({ map[i][j][0],k});
				smelltempmap[i][j].push_back({ map[i][j][0],k });
			}
		}
	}
}

void eatshark() {
	//한칸에 여러마리의 상어가 있다면 높은 번호 상어는 쫓겨난다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() != 1) {
				int max = *max_element(map[i][j].begin(), map[i][j].end());
				memset(map[i][j], 0, map[i][j].size());
				map[i][j][0] = max;
			}
		}
	}
}

void move() {
	//알고리즘에 따라 움직인다.
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			if (map[i][j][0] != 0) { //map에 상어가 있고 ( 순차적으로 찾으면 안되고 한번에 이동해야하므로 temp배열 이용한다.)
				
				int name = map[i][j][0]; //상어의 번호, 자기냄새
				int state = sharkstate[name]; //상어의방향
				int check = 0;

				for (int z =0; z<4; z++){ //4방향을 번갈면서 (우선순위대로 반복)
					int way = sharkd[name][state][z];
					int up = map[i - 1][j][0];
					int down = map[i + 1][j][0];
					int left = map[i][j - 1][0];
					int right = map[i][j + 1][0];
					//way가 지금 상어, 방향에 맞는 방향이다.
					switch (way) { //위 아래 왼쪽 오른쪽
					case 0 : 
						if (i - 1 >= 0 && i-1 < N) { //범위확인
							if (up == 0) {
								sharkstate[name] = 1; //상어의 방향을 재지정
								smelltempmap[i - 1][j].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
								tempmap[i - 1][j].push_back(name); //이동한 곳에 위치한다.
								smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
								tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
								check = 1;
							}
						}
					case 1:
						if (i + 1 >= 0 && i+1 < N) { //범위확인
							if (down == 0) {
								sharkstate[name] = 2; //상어의 방향을 재지정
								smelltempmap[i + 1][j].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
								tempmap[i + 1][j].push_back(name); //이동한 곳에 위치한다.
								smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
								tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
								check = 1;
							}
						}
					case 2:
						if (j-1 >= 0 && j - 1 < N) { //범위확인
							if (left == 0) {
								sharkstate[name] = 3; //상어의 방향을 재지정
								smelltempmap[i][j-1].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
								tempmap[i][j-1].push_back(name); //이동한 곳에 위치한다.
								smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
								tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
								check = 1;
							}
						}
					case 3:
						if (j + 1 >= 0 && j + 1 < N) { //범위확인
							if (down == 0) {
								sharkstate[name] = 4; //상어의 방향을 재지정
								smelltempmap[i][j+1].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
								tempmap[i][j+1].push_back(name); //이동한 곳에 위치한다.
								smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
								tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
								check = 1;
							}
						}
					}
				}
				if (check == 0) { //한군데에도 못들어갔다면 다시 for문 돌면서 자신의 냄새가 있는칸에 들어가야된다.
					for (int z = 0; z < 4; z++) { //4방향을 번갈면서 (우선순위대로 반복)
						int way = sharkd[name][state][z];
						int up = map[i - 1][j][0];
						int down = map[i + 1][j][0];
						int left = map[i][j - 1][0];
						int right = map[i][j + 1][0];
						//way가 지금 상어, 방향에 맞는 방향이다.
						switch (way) { //위 아래 왼쪽 오른쪽
						case 0:
							if (i - 1 >= 0 && i - 1 < N) { //범위확인
								if (up == name) {
									sharkstate[name] = 1; //상어의 방향을 재지정
									smelltempmap[i - 1][j].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
									tempmap[i - 1][j].push_back(name); //이동한 곳에 위치한다.
									smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
									tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
									check = 1;
								}
							}
						case 1:
							if (i + 1 >= 0 && i + 1 < N) { //범위확인
								if (down == name) {
									sharkstate[name] = 2; //상어의 방향을 재지정
									smelltempmap[i + 1][j].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
									tempmap[i + 1][j].push_back(name); //이동한 곳에 위치한다.
									smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
									tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
									check = 1;
								}
							}
						case 2:
							if (j - 1 >= 0 && j - 1 < N) { //범위확인
								if (left == name) {
									sharkstate[name] = 3; //상어의 방향을 재지정
									smelltempmap[i][j - 1].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
									tempmap[i][j - 1].push_back(name); //이동한 곳에 위치한다.
									smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
									tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
									check = 1;
								}
							}
						case 3:
							if (j + 1 >= 0 && j + 1 < N) { //범위확인
								if (down == name) {
									sharkstate[name] = 4; //상어의 방향을 재지정
									smelltempmap[i][j + 1].push_back({ name,k }); //이동한곳에 냄새 뿌린다.
									tempmap[i][j + 1].push_back(name); //이동한 곳에 위치한다.
									smelltempmap[i][j].pop_back(); //어차피 [0] 밖에없으니
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//위치했던 곳의 냄새와 강도만 남기고 그 냄새는 -1 시킨다.
									tempmap[i][j].push_back(0); //위치하지 않는다. 0으로바꾸기
									check = 1;
								}
							}
						}
					}
				}

			}
		}
	}

	//냄새가 잊혀진 것들은 삭제해줘야될텐데... 그 상어의 영역이 아닐것

	eatshark();
}

int main() {
	cin >> N >> M >> k; //NxN 크기에 M마리의 상어, 냄새는 상어가 k번이동시 사라진다.
	int in1;
	//현재 map에 각 번호별 상어들의 위치
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> in1;
			map[i][j].push_back(in1);
		}
	}

	//상어들의 초기 방향
	for (int i = 1; i <= N; i++)
		cin >> sharkstate[i]; //1번 상어부터 N번상어까지 방향 지시
	//위 아래 왼쪽 오른쪽 순서대로 1, 2, 3, 4

	//우선순위
	for (int k = 1; k <= N; k++) { //1~N번 상어
		for (int i = 0; i < N; i++) { //위 아래 왼쪽 오른쪽 순서로 저장
			for (int j = 0; j < N; j++) { //우선순위 저장
				cin >> sharkd[k][i][j];
			}
		}
	}
	spread();

	move();

	return 0;
}