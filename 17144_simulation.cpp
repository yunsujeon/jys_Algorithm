#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int R, C, T;
int map[51][51] = { 0, };
int copymap[51][51] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int where[4] = { 0, };
vector<pair<int, int>> v;

void diff() { //미세먼지 확산
	copymap[v[0].first][v[0].second] = -1;
	copymap[v[1].first][v[1].second] = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) { //먼지가 있다면 최대한 사방으로 퍼뜨린다.
				int c = 0; //몇군데나 옮기는지 세야 된다.
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < R && nr >= 0 && nc < C && nc >= 0 && map[nr][nc]!=-1) {
						c++;
						where[k] = 1;
					}
				}
				int ori_dust = map[i][j]; //점에 뭉쳐있는 먼지
				int diff_dust = ori_dust / 5;//퍼질 먼지들
				int cent_dust = ori_dust - (diff_dust * c); //가운데 먼지
				copymap[i][j] += cent_dust;
				for (int k = 0; k < 4; k++) {
					if (where[k] == 1) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						copymap[nr][nc] += diff_dust;
					}
				}
			}
			memset(where, 0, sizeof(where));
		}
	}
}

void clean() {
	int flag = 0;
	for (int i = 0; i < R; i++) {
		if (map[i][0] == -1 && flag == 0) { //반시계로 도는 공기청정기 1
			int r = i;
			while (r > 0) { //아래로 내려감
				r--;
				copymap[r][0] = copymap[r - 1][0];
			}
			int c = 0;
			while (c < C-1) { // 왼쪽으로 이동
				c++;
				copymap[0][c - 1] = copymap[0][c];
			}
			r = 0;
			while (r < i) {	//위로 이동
				r++;
				copymap[r-1][C - 1] = copymap[r][C - 1];
			}
			c = C;
			while (c > 1) {	//오른쪽으로 이동
				c--;
				copymap[i][c + 1] = copymap[i][c];
			}
			copymap[i][1] = 0;
			flag = 1;
		}
		else if (map[i][0]==-1 && flag==1) { //시계로 도는 공기청정기 2
			int r = i;
			while (r < R-1) {
				r++; 
				copymap[r][0] = copymap[r+1][0];
			}
			int c = 0;
			while (c < C-1) {
				copymap[R - 1][c] = copymap[R - 1][c + 1];
				c++;
			}
			r = R - 1;
			while (r > i) {
				copymap[r][C - 1] = copymap[r - 1][C - 1];
				r--;
			}
			c = C - 1;
			while (c > 1) {
				copymap[i][c] = copymap[i][c - 1];
				c--;
			}
			copymap[i][1] = 0;
		}
	}
}

int solution() {
	while (T--) {
		diff();
		clean();
		memset(map, 0, sizeof(map));
		memcpy(map, copymap, sizeof(copymap));
		memset(copymap, 0, sizeof(copymap));
	}
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 0) {
				result += map[i][j];
			}
		}
	}
	return result;
}

int main() {
	cin >> R >> C >> T;
	int dust;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> dust;
			map[i][j] = dust;
			if (dust == -1) v.push_back({ i,j });
		}
	}
	cout << solution() << '\n';
	return 0;
}