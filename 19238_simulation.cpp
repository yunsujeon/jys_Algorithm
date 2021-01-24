#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 21

using namespace std;

int dx[] = { -1,0,1,0 }; //row
int dy[] = { 0,1,0,-1 }; //col

struct group {
	int r;
	int c;
};

struct one {
	int X_;
	int Y_;
	int C_;
};

group man[MAX][MAX];
int N, M, f;
int map[MAX][MAX];
int r, c;
int rX, rY;
int visit[MAX][MAX] = { 0, };
int X1 = 0, Y1 = 0, C1 = 0;
int X2 = 0, Y2 = 0, C2 = 0;
int chk;

one bfs(int x, int y,int cnt, int func) {
	chk = 0; //chk가 0인 상태로 나간다면 아무것도 찾지 못했다는 것
	one re = { 0, };
	if (func == 1) { //func 1이라는건 사람을 찾는 bfs
		if (map[x][y] == 2) { //자기자신이 목표 좌표일경우
			re.X_ = x;
			re.Y_ = y;
			re.C_ = 0;
			chk = 1;
			return re; //기름한방울 안쓰고 그대로 return
		}
	}
	else if (func == 2) { //func 2라는건 목표점을 찾는 bfs
		if ((x==rX)&&(y==rY)) { //자기자신이 목표 좌표일경우
			re.X_ = x;
			re.Y_ = y;
			re.C_ = 0;
			chk = 1;
			return re; //기름한방울 안쓰고 그대로 return
		}
	}
	queue<pair<pair<int, int>, int>>q; //좌표,좌표,거리 가 큐에 담길것
	q.push({ { x,y },cnt }); //일반적인 bfs를 돌려준다.
	visit[x][y] = 1;
	int X = MAX; //x와 y, c는 최대값에서부터 최소값이 나올때마다 갱신된다.
	int Y = MAX;
	int C=987654321; //이부분을 실수했었다. C는 21 이상일 수 있는데 21로 잡아놨었다.
	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nnx = nx + dx[i];
			int nny = ny + dy[i];
			int nc = c + 1;
			if (nnx > 0 && nnx <= N && nny > 0 && nny <= N && visit[nnx][nny]==0) {
				if (func == 1) { //func 1이라는건 사람을 찾는 bfs
					if (map[nnx][nny] == 2) { //map에 사람이 있는상황
						chk = 1; //찾았으니 체크
						if (nc <= C) { //nc가 C보다 작은상황에만 수행하자 크면 의미없잖아
							if (X > nnx) { //행이 작은상황이라면
								X = nnx,Y= nny,C = nc;
								re.X_ = X,re.Y_ = Y,re.C_ = C;
							}
							else if (X == nnx) { //행이 동일하다면
								if (Y >= nny) { //열을 비교해주고 넣어준다.
									X = nnx,Y = nny,C = nc;
									re.X_ = X,re.Y_ = Y,re.C_ = C;
								}
							}
						}		
						q.push({ { nnx,nny },nc }); //갱신이 되던말던 지나칠수는 있으니 q에 push
						visit[nnx][nny] = 1; //visit도 했다
					}
					else if (map[nnx][nny] != 1) { //벽이 아니기만 한다면
						q.push({ { nnx,nny },nc }); //q에 push
						visit[nnx][nny] = 1;//visit
					}
				}
				else if (func == 2) { //func 2라는건 목표점을 찾는 bfs
					if ((nnx==rX)&&(nny==rY)) { //찾은거다. 끝내버리자
						chk = 1;
						re.X_ = nnx;
						re.Y_ = nny;
						re.C_ = nc;
						return re;
					}
					else if (map[nnx][nny] != 1&&visit[nnx][nny]==0) { //벽이 아니고 방문X
						q.push({ { nnx,nny },nc });
						visit[nnx][nny] = 1;
					}
				}
			}
		}
	}
	return re;
}

int solution(int x,int y,int f) {
	one re2;
	one re3;
	for (int i = 0; i < M; i++) {

		re2 = bfs(x, y, 0, 1); //다음에 돌아올때는 x와 y를 다시 정의해줘야될것
		map[re2.X_][re2.Y_] = 4; //사람이 있는 지점. map에 4로 지정해준다. 다음엔 사람찾을때 얘 안찾게끔
		group go = man[re2.X_][re2.Y_]; //go는 목표지점을 가리킨다.
		rX = go.r;
		rY = go.c; //목표위치를 찾았다.
		int fuel = f - re2.C_; //기름 쓴 양을 빼준다.
		if ((fuel < 0)||(chk==0)) //기름이 음수거나 아무것도 찾지못했다면 
			return 0;	
		memset(visit, 0, sizeof(visit)); //visit 배열 초기화

		//여기서 다시 bfs돌리면 될것이다. 목표는 사람이 아닌 자신의 깃발
		re3 = bfs(re2.X_, re2.Y_, 0, 2);
		int fuel2 = fuel - re3.C_;
		if ((fuel2 < 0)||(chk==0))
			return 0;
		fuel2 =  fuel2+(2 * re3.C_); //여기선 기름 양을 채워준다.
		f = fuel2;
		x = re3.X_;
		y = re3.Y_;
		memset(visit, 0, sizeof(visit));
	}
	return f;
}

int main() {
	cin >> N >> M >> f;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> r >> c;
	for (int i = 0; i < M; i++) {
		int hr, hc, mr, mc;
		cin >> hr >> hc >> mr >> mc;
		man[hr][hc] = { mr,mc }; //각각의 목표를 담아준다. 
		map[hr][hc] = 2; //2는 사람이 있는 출발위치
	}

	int result = solution(r,c,f);
	if (result == 0)
		printf("-1");
	else
		cout << result << endl;
	return 0;
}