#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int x,y,dir;
	int dead;
}fish;

const int dx[] = {-1,-1,0,1,1,1,0,-1}; //상 부터 반시계방향으로 흘러감 index 1로두기위해
const int dy[] = {0,-1,-1,-1,0,1,1,1};

void copymap(int a[4][4], int b[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = b[i][j];
		}
	}
	return;
}
void copyfish(fish a[17], fish b[17]) {
	for (int i = 0; i < 17; i++) {
		a[i] = b[i];
	}
}

int solution_dfs(int o_map[][4], int x, int y, int dir, fish o_fish[17]) {
	int map[4][4];
	fish fish[17];
	copymap(map, o_map);
	copyfish(fish, o_fish);
	int eat = map[x][y]; //상어가 먹는거
	dir = fish[map[x][y]].dir; //먹힌 물고기가 가졌던 이제는 상어가 가지는 방향
	fish[map[x][y]].x = -1; //없애준다.
	fish[map[x][y]].y = -1;
	fish[map[x][y]].dead = true; //상어한테 잡아먹힘
	map[x][y] = 0;

	int answer = 0;

	for (int i = 1; i <= 16; i++) {
		if (fish[i].dead == false) {
			int nx = fish[i].x; //가장 번호가 작은 물고기부터 좌표 
			int ny = fish[i].y;
			for (int j = 0; j < 8; j++) { //8방향을 둘러보며 갈수있는 방향 지정
				int cx = fish[i].x + dx[fish[i].dir]; //후보 좌표 cx, cy
				int cy = fish[i].y + dy[fish[i].dir];
				if (cx == x && cy == y) { //상어가 있다면 방향 하나 바꾸기
					fish[i].dir = (fish[i].dir+1) % 8;
					continue;
				}
				if (cx < 0 || cy < 0 || cx >= 4 || cy >= 4) { //범위를 벗어난다면
					fish[i].dir = (fish[i].dir+1) % 8;
					continue;
				}
				nx = cx; //그게 아니라면 nx와 ny를 갱신한다.
				ny = cy;
				break; //여기까진 한번만 오면 된다.
			}
			if (map[nx][ny] == 0) { //갈수있는 방향은 정했다. 만약 map에 그 좌표가 비었으면
				map[fish[i].x][fish[i].y] = 0; //fish를 옮겨주는 작업
				map[nx][ny] = i;
				fish[i].x = nx;
				fish[i].y = ny;
			}
			else {
				int tx, ty, temp; //현재 위치와 갈 곳의 fish정보를 바꿔주는 일
				tx = fish[i].x;
				ty = fish[i].y;
				fish[i].x = nx;
				fish[i].y = ny;
				fish[map[nx][ny]].x = tx;
				fish[map[nx][ny]].y = ty;
				map[tx][ty] = map[nx][ny];
				map[nx][ny] = i;
			}
		}
	}
	int cx = x + dx[dir]; //상어의 움직임
	int cy = y + dy[dir];
	while (!(cy < 0 || cx < 0 || cy >= 4 || cx >= 4)) { //범위 벗어날때까지 이동
		if (map[cx][cy] != 0) { //가는곳에 물고기가 있다면
			answer = max(answer, solution_dfs(map, cx, cy, dir, fish)); //현재 map, cx, cy, fish 상태 넣어준다.
		}
		cx += dx[dir]; //갈수 있는 방향으로 더 넣어준다.
		cy += dy[dir];
	}
	return answer + eat;
}

int main() {
	int map[4][4] = { 0, };
	fish fish[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; //물고기와 그 방향
			cin >> a >> b;
			fish[a].x = i;
			fish[a].y = j;
			fish[a].dead = false;
			fish[a].dir = b-1;
			map[i][j] = a;
		}
	}
	int result = solution_dfs(map, 0, 0, 0, fish);
	printf("%d", result);
	return 0;
}