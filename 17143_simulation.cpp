#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct shark {
	int s;
	int d;
	int z;
};

int hap = 0;
shark map[101][101] = { 0, };
vector <shark> copymap[101][101];
int R, C, M;
int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,1,-1 };

void solution() {
	for (int c = 1; c <= C; c++) { //낚시왕 움직임 열
		for (int r = 1; r <= R; r++) { //땅에서 가까운데서 부터 탐색
			if (map[r][c].d) { //존재여부판단 가능
				hap += map[r][c].z; //크기합하기
				map[r][c].s = 0;
				map[r][c].d = 0;
				map[r][c].z = 0;
				break; //한마리 잡았으면 for문 나가기
			}
		}
		vector <shark> copymap[101][101]; //초기화 대신 재선언을 택함
		//상어의 이동을 구현하기 여기서 다시 이중 for문 돌려도 시간초과정도까진 X
		for (int x = 1; x <= R; x++) {
			for (int y = 1; y <= C; y++) {
				if (map[x][y].d) { //존재하면
					int speed = map[x][y].s;
					int dir_r = dr[map[x][y].d];
					int dir_c = dc[map[x][y].d];
					int nx = x;
					int ny = y;
					if (map[x][y].d == 3 || map[x][y].d == 4) {
						speed = speed % ((C - 1) * 2);
					}
					else {
						speed = speed % ((R - 1) * 2);
					}
					while (speed > 0) { //여기서 시간초과가 발생
						nx += dir_r; //한칸씩 증가하거나 감소한다.
						ny += dir_c;
						if (nx == 0) { //범위를 넘으면 돌아서고 방향도 바뀐다.
							nx = nx + 2;
							dir_r = -1*(dir_r);//방향을 반대로 바꾼다.
						}
						else if (nx == R + 1) {
							nx = nx - 2;
							dir_r = -1 * (dir_r);
						}
						else if (ny == 0) {
							ny = ny + 2;
							dir_c = -1 * (dir_c);
						}
						else if (ny == C + 1) {
							ny = ny - 2;
							dir_c = -1 * (dir_c);
						}
						speed--;
					}
					shark Shark;
					Shark.s = map[x][y].s;
					Shark.z = map[x][y].z;
					if (dir_r == -1 && dir_c == 0) Shark.d = 1;
					else if (dir_r == 1 && dir_c == 0) Shark.d = 2;
					else if (dir_r == 0 && dir_c == 1) Shark.d = 3;
					else if (dir_r == 0 && dir_c == -1) Shark.d = 4;
					if (copymap[nx][ny].size() == 0) { //아무것도 없다면
						copymap[nx][ny].push_back(Shark); //넣는다
					}
					else if (Shark.z > copymap[nx][ny][0].z) { //비교해서 큰것을 넣는다.
						copymap[nx][ny].pop_back(); //원래 있던걸 빼고
						copymap[nx][ny].push_back(Shark); //넣는다
					}
				}
			}
		}
		//갱신이 다 됐으면 copymap을 map으로 복사한다.
		memset(map, 0, sizeof(map)); //우선 map을 초기화해버려
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (copymap[i][j].size() != 0) {
					map[i][j].d = copymap[i][j][0].d;
					map[i][j].s = copymap[i][j][0].s;
					map[i][j].z = copymap[i][j][0].z;
				}
			}
		}
	}
}

int main() {
	cin >> R >> C >> M;
	int rR, cC, S, D, Z;
	for (int i = 0; i < M; i++) {
		cin >> rR >> cC >> S >> D >> Z;
		map[rR][cC].s = S;
		map[rR][cC].d = D;
		map[rR][cC].z = Z;
	}

	solution();
	cout << hap << '\n';
	return 0;
}