//scanf("%1d",&temp)와 같이 %1d를 사용하면 붙어있어도 한 번에 한 개씩 입력받을 수 있습니다.
//

#include <iostream>
#include<stdio.h>
#include <queue>
#include <algorithm>
#define MAX 25

using namespace std;
int map[MAX][MAX] = { 0, }; //값이 들어가는 배열 
int visit[MAX][MAX]= { 0, }; //방문배열
int N, outcnt, incnt; //갯수, 카운트배열
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int inarr[MAX*MAX] = { 0, };

void bfs(int x,int y) {
	incnt = 0;
	queue <pair<int, int>>q;
	q.push({ x, y });
	visit[x][y] = true;
	incnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ex = x + dx[i];
			int ey = y + dy[i];

			if (ex>=0 && ex<N && ey>=0 && ey<N &&(visit[ex][ey] == 0 && map[ex][ey] == 1)) { //map값이 1일경우에만 큐에 넣어준다.
				visit[ex][ey] = 1; //방문체크해준다
				q.push({ ex,ey }); //큐에넣어준다
				incnt++; //카운트 증가 
			}
		}
	}
	inarr[outcnt] = incnt;
}

int main() {
	int s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &s);
			map[i][j] = s;
		}
	}
	outcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]&&map[i][j]==1) {
				bfs(i, j);
				outcnt++;
			}
		}
	}
	sort(inarr, inarr + (MAX * MAX));
	cout << outcnt << endl;;
	int count = 0;
	for (int i = 0; i < MAX*MAX; i++) {
		if (inarr[count]) {
			cout << inarr[count] << endl;
		}
		count++;
	}

	return 0;
}
