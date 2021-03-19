//새로운 게임

#include <iostream>
#include <vector>
using namespace std;

struct mal {
	int rr;
	int cc;
};

vector <pair<int, int>> v[13][13]; //말 번호와 방향이 들어갈것
mal loc[13];
int arr[13][13] = { 0, }; //배열
int N, K;

//방향 : 1-우 2-좌 3-상 4-하

int dc[] = { 0,1,-1,0,0 };
int dr[] = { 0,0,0,-1,1 };

int solution(){
	int cnt = 1;
	int dir = 0;
	int era;
	while (cnt <= 1000) {
		for (int i = 1; i <= K; i++) { //말의 갯수만큼 계속 반복
			//말 i의 위치는?
			int r = loc[i].rr;
			int c = loc[i].cc;
			//말 i의 방향은?
			for (int n = 0; n < v[r][c].size(); n++) {
				int num = v[r][c][n].first;
				if (num == i) {
					dir = v[r][c][n].second;
					era = n;
					break;
				}
			}
			//새롭게 갈 방향을 제시한다.
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			//움직인다면 범위를 벗어나는지 확인한다
			int color = 0;
			if (nr < 1 || nr >= N+1 || nc < 1 || nc >= N+1) color = 2; //벗어났다면 파란색
			//범위를 벗어난 것이 아니라면 갈 곳의 색깔을 확인한다

			if (arr[nr][nc] == 0&&color!=2) { //흰색
				//그 칸으로 이동한다. 
				//이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
				for (int a = era; a < v[r][c].size(); a++) {
					v[nr][nc].push_back({ v[r][c][a].first,v[r][c][a].second });
					loc[v[r][c][a].first].rr = nr;
					loc[v[r][c][a].first].cc = nc;
				}
				if (v[nr][nc].size() >= 4) return cnt;
				v[r][c].erase(v[r][c].begin()+era,v[r][c].end()); //정확한 위치를 줘야 지워진다. 그냥 era X
			}
			else if (arr[nr][nc] == 1&&color!=2) { //빨간색
				for (int a = v[r][c].size() - 1; a >= era; a--) {
					v[nr][nc].push_back({ v[r][c][a].first,v[r][c][a].second }); //거꾸로놓자
					loc[v[r][c][a].first].rr = nr;
					loc[v[r][c][a].first].cc = nc;
				}
				if (v[nr][nc].size() >= 4) return cnt;
				v[r][c].erase(v[r][c].begin() + era, v[r][c].end()); //정확한 위치를 줘야 지워진다. 그냥 era X
			}
			else if (arr[nr][nc] == 2||color==2) { //파란색
				int bluenr = r - dr[dir];
				int bluenc = c - dc[dir];
				//일단 말의 방향을 바꾼다
				switch (v[r][c][era].second) {
				case(1):v[r][c][era].second = 2; break;
				case(2):v[r][c][era].second = 1; break;
				case(3):v[r][c][era].second = 4; break;
				case(4):v[r][c][era].second = 3; break;
				}
				if (bluenr < 1 || bluenr >= N+1 || bluenc < 1 || bluenc >= N+1) continue;
				if (arr[bluenr][bluenc] == 2) continue;//방향바꾼쪽도 파란색이면
				else if(arr[bluenr][bluenc]==0){ // 안벗어난다면 반대로 이동한다. 흰색이면 다같이 이동하면될것
					for (int a = era; a < v[r][c].size(); a++) {
						v[bluenr][bluenc].push_back({ v[r][c][a].first,v[r][c][a].second }); //그대로 이동
						loc[v[r][c][a].first].rr = bluenr;
						loc[v[r][c][a].first].cc = bluenc;
					}
					if (v[bluenr][bluenc].size() >= 4) return cnt;
					v[r][c].erase(v[r][c].begin() + era, v[r][c].end()); //정확한 위치를 줘야 지워진다. 그냥 era X
				}
				else if (arr[bluenr][bluenc] == 1) { //빨간색일때
					for (int a = v[r][c].size() - 1; a >= era; a--) {
						v[bluenr][bluenc].push_back({ v[r][c][a].first,v[r][c][a].second }); //거꾸로놓자
						loc[v[r][c][a].first].rr = bluenr;
						loc[v[r][c][a].first].cc = bluenc;
					}
					if (v[bluenr][bluenc].size() >= 4) return cnt;
					v[r][c].erase(v[r][c].begin() + era, v[r][c].end()); //정확한 위치를 줘야 지워진다. 그냥 era X
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	cin >> N >> K;
	int color;
	int r, c, d;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color;
			arr[i][j] = color;
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> r >> c >> d;
		v[r][c].push_back({ i,d });
		loc[i].rr = r;
		loc[i].cc = c;
	}
	cout << solution() << '\n';

	return 0;
}