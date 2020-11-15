//2186 문자판
//DFS + DP문제. DFS로만 BP구성할경우 시간초과가 뜬다.
//점화식 : dp[i][j][idx] = (i,j)위치는 문자열 중 idx번째까지 일치하는 케이스들의 합

#include <iostream>
#include<string>
using namespace std;

int N, M, K;
char map[100][100];
string word;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visit[100][100][80]; //=t 라면 (x,y)에 단어의 길이가 idx 일때 가능한 방법이 t가지라는 것
//visit 이 결국 dp이다.

int dfs(int y, int x, int idx) { //처음들어올땐 idx 1로 들어온다.
	if (idx == word.length()) { //idx ++하며 다 탐색완료한거
		return 1;
	}
	if (visit[y][x][idx] != -1)  //이미 값이 저장된 경우
		return visit[y][x][idx];
	else {
		visit[y][x][idx] = 0; //-1이면 0으로 만들어준다.
		for (int i = 1; i <= K; i++) { //K번 반복해줄거다
			for (int j = 0; j < 4; j++) { //4방향 탐색할거다
				int ny = y + dy[j] * i; //상하좌우 좌표
				int nx = x + dx[j] * i; //상하좌우 좌표
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) //범위안맞으면
					continue; //다음 반복문으로
				if (map[ny][nx] == word[idx]) { //그 글자와 맞으면
					visit[y][x][idx] += dfs(ny, nx, idx + 1);
				}
			}
		}
	}
	return visit[y][x][idx]; //한 시작점에서 출발하여 만들 수 있는 갯수
}

int main() {
	scanf_s("%d %d %d", &N, & M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> word; //이 영단어를 만들 수 있는 경로가 총 몇개인지

	memset(visit, -1, sizeof(visit)); //dp 배열 초기화
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == word[0]) { //string에서 [0]은 한글자라는거
				result += dfs(i, j, 1); //모든 시작점 출발하여 만들수있는 갯수 합
			}
		}
	}
	printf("%d", result);
	return 0;
}