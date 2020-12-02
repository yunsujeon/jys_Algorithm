
//그냥 while문으로 풀어본거 : MAX조건이 들어갈수가없다..
/*
#include <iostream>

using namespace std;
int f, s, g, u, d; //총 층수, 현재 위치, 목표 층, 위로 u층, 아래로 d층

int dp() {
	int i = s;
	int count = 0;
	if (s < g) {
		while (i < g) {
			if (u == 0) {
				break;
			}
			i += u;
			count++;
		}
		if (i == g)
			return count;
		else {
			while (i != g) {
				if (d == 0) {
					break;
				}
				i -= d;
				count++;
				if (i < g) {
					return -1; //못찾은거
				}
			}
			return count;
		}
	}
	else if (s > g) {
		while (i > g) {
			if (d == 0) {
				break;
			}
			i -= d;
			count++;
		}
		if (i == g)
			return count;
		else {
			while (i != g) {
				if (u == 0)
				{
					break;
				}
				i += u;
				count++;
				if (i > g) {
					return -1; //못찾은거
				}
			}
			return count;
		}
	}
	else { //s==g
		return count;
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	int result = dp();
	if (result == -1) {
		printf("use the stairs\n");
	}
	else {
		printf("%d", result);
	}
	return 0;
}*/

//최소를 구하라 : bfs로 구할 수 있다.
//만약 dfs로 구하면 나중에 방문한 경우가 더 짧을 수 있는데
//만일 그럴경우를 전부 중복해서 탐색한다면 시간복잡도가 지수가 될것

#define MAX 1000001
#include <iostream>
#include <queue>

using namespace std;

bool visit[MAX];
int f, s, g, u, d; //총 층수, 현재 위치, 목표 층, 위로 u층, 아래로 d층

int bfs() {
	queue<pair<int,int>> q;
	q.push({ s,0 }); //0은 횟수이다.
	visit[s] = true;

	while (!q.empty()) {
		int position = q.front().first; //위치
		int count = q.front().second; //횟수
		q.pop();

		if (position == g)//목표층에 도달한다면
			return count;
		if (position + u <= f && visit[position + u] == false) {
			q.push({ position + u,count + 1 });
			visit[position + u] = true;
		}
		if (position - d > 0 && visit[position - d] == false) {
			q.push({ position - d,count + 1 });
			visit[position - d] = true;
		}
	}
	return -1;

}

int main() {
	cin >> f >> s >> g >> u >> d;
	int ans = bfs();
	if (ans == -1) {
		printf("use the stairs");
	}
	else {
		printf("%d", ans);
	}

	return 0;
}