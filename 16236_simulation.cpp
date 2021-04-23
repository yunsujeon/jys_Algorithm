
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N;
int map[21][21] = { 0, };
int eat_able[21][21] = { 0, };
int stop[21][21] = { 0, }; //1이면 못지나가는거
int shark_size = 2;
int eat = 0;
int dr[] = { -1,0,0, 1 }; //상좌하우 X 상좌우하
int dc[] = { 0,-1,1, 0 };
int MIN = 987654321;
int eat_cnt = 0;
int second = 0;
int hap = 0;

struct ff {
	int x;
	int y;
	int cnt;
};

struct compare {
	bool operator()(ff a, ff b) {
		if (a.cnt == b.cnt) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			return a.x > b.x;
		}
		return a.cnt > b.cnt;
	}
};

int bfs(int r, int c) { //4방향 bfs 최단거리찾기
	priority_queue<ff, vector<ff>, compare> pq;
	//priority_queue<pair<pair<int, int>,int>,compare >q;
	int visit[21][21] = { 0, };
	//q.push({ { r,c },0 });
	pq.push({ r,c,0 });
	//q.push(make_pair(make_pair(r, c), 0));
	visit[r][c] = 1;
	MIN = 987654321;
	while (!pq.empty()) {
		//int x = q.top().first.first;
		//int y = q.top().first.second;
		//int cnt = q.top().second;
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		if (eat_able[x][y] == 1) { //중단조건
			MIN = cnt;
			//거리가 가장 가까운 물고기
			map[r][c] = 0;
			map[x][y] = 9; //새로운 좌표에 아기상어를 놓는다.
			eat_cnt++;
			if (shark_size == eat_cnt) {
				shark_size++;
				eat_cnt = 0;
				if (shark_size >= 7) shark_size = 7;
			}
			return MIN;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N&& visit[nx][ny]==0) {
				if (stop[nx][ny] != 1) {
					//q.push({ {nx,ny},cnt + 1 });
					pq.push({ nx,ny,cnt + 1 });
					visit[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

int sol(int r, int c) {
	if (eat != 0) { //최단거리 출력하면된다.
		if (eat == 1) {
			int na = bfs(r, c);
			if (na == -1) {
				return 0;
			}
			else
				return na;
		}
		int E = eat;
		while (E>0) {
			int na = bfs(r, c);
			if (na != -1) hap += na;
			if (na == -1) { //움직일수가 없다면
				return hap; //지금까지 더했던걸 반환하면된다.
			}
			eat = 0;
			memset(eat_able, 0, sizeof(eat_able));
			memset(stop, 0, sizeof(stop));
			//map을 재구성해준다.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int inp = map[i][j];
					if (shark_size < inp) {
						stop[i][j] = 1;
					}
					else {
						stop[i][j] = 0;
					}
					if (shark_size > inp && inp > 0) {
						eat_able[i][j] = 1;
						eat++;
					}
					if (inp == 9) {
						r = i;
						c = j;
					}
				}
			}
			second += MIN;
			E = eat;
		}
		return second;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> N;
	int inp, r, c;
	for (int i = 0; i < N; i++) { //이정도는 계속 수행해도 시간초과X
		for(int j = 0; j < N; j++){
			cin >> inp;
			map[i][j] = inp;
			if (shark_size < inp) {
				stop[i][j] = 1;
			}
			else if (shark_size > inp&& inp > 0) {
				eat_able[i][j] = 1;
				eat++;
			}
			if (inp == 9) {
				r = i;
				c = j;
			}
		}
	}
	cout << sol(r, c) << '\n';
	return 0;
}