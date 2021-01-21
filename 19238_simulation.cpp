#include <iostream>
#include <queue>
#include <vector>
#define MAX 21

using namespace std;

int dx[] = { -1,0,1,0 }; //row
int dy[] = { 0,1,0,-1 }; //col

struct group {
	int r;
	int c;
};

group man[MAX][MAX];
int N, M, f; //맵 크기 NN //사람 수 M // 연료 f
int map[MAX][MAX];
int r, c;
int rX, rY;

int bfs(int x, int y,int cnt, int func) {
	if (func == 1) {
		if (map[x][y] == 2) { //자기자신의 좌표일경우
			return x, y, 0; //기름한방울 안쓰고 그대로 return
		}
	}
	else if (func == 2) {
		if (map[x][y] == 3) { //자기자신의 좌표일경우
			return x, y, 0; //기름한방울 안쓰고 그대로 return
		}
	}
	queue<pair<pair<int, int>, int>>q;
	q.push({ { x,y },cnt });
	int X = MAX;
	int Y = MAX;
	int C=0;
	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nnx = nx + dx[0];
			int nny = ny + dy[0];
			int nc = c + 1;
			if (nnx >= 0 && nnx < N && nny >= 0 && nny < N) {
				if (func == 1) {
					if (map[nnx][nny] == 2) {
						if (X > nnx) {
							X = nnx;
							Y = nny;
							C = nc;
						}
						else if (X == nnx) {
							if (Y >= nny) {
								X = nnx;
								Y = nny;
								C = nc;
							}
						}
					}
					else if (map[nnx][nny] != 1) {
						q.push({ { nnx,nny },nc });
					}
				}
				else if (func == 2) {
					if ((nnx==rX)&&(nny==rY)) { //걍 찾은거. 끝내버려
						X = nnx;
						Y = nny;
						C = nc; //쓴 연료
						return X, Y, C;
					}
					else if (map[nnx][nny] != 1) {
						q.push({ { nnx,nny },nc });
					}

				}
			}
		}
	}
	return X, Y, C;
}

int bfs_flag(int x,int y,int cnt) {

}

int solution(int x,int y,int f) {
	//가장 가까운곳에 있는 사람을 찾아야된다. bfs
	for (int i = 0; i < M; i++) {
		int X, Y, C = bfs(x, y, 0, 1); //다음에 돌아올때는 x와 y를 다시 정의해줘야될것
		//x,y에서 가장 가까운곳에 있는 사람을 찾는다. 그사람 좌표: X,Y
		group go = man[X][Y];
		rX = go.r;
		rY = go.c; //목표위치를 찾았다.
		int fuel = f - C;
		기름양 채워줘야될것
		if (fuel <= 0) 
			return 0;		
		//여기서 다시 bfs돌리면 될것이다. 목표는 사람이 아닌 자신의 깃발
		int nX,nY,nC = bfs(X, Y, 0, 2);
		int fuel2 = fuel - nC;
		if (fuel <= 0)
			return 0;
		기름양채워주기
		x,y 재정의해주고 for문으로 다시 돌아갈것
	}
}

int main() {
	cin >> N >> M >> f;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> r >> c;
	for (int i = 0; i < M; i++) {
		int hr, hc, mr, mc;
		cin >> hr >> hc >> mr >> mc;
		man[hr][hc] = { mr,mc }; //각각의 목표를 담아준다. 
		map[hr][hc] = 2; //2는 사람이 있는 출발위치
		map[mr][mc] = 3; //3은 목적지
	}
	int result = solution(r,c,f);
	if (result == 0)
		printf("-1");

	return 0;
}

//최단거리 bfs사용하자
//손님 위치와 목적지 위치를 vector로 묶던가 struct로 묶자