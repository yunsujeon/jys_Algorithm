#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int map[501][501] = { 0, };
int dp[501][501] = { 0, };
int N;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int K = 0;

int Big(int A, int B) {
	return A > B ? A : B; //큰 수 반환
}
//int bfs(int a, int b) {
//	queue <pair<int, int>> q;
//	q.push({ a,b });
//
//	while (!q.empty()) {
//		int na = q.front().first;
//		int nb = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nna = na + dx[i];
//			int nnb = nb + dy[i];
//			if (nna >= 0 && nna < N && nnb >= 0 && nnb < N) {
//				if (map[na][nb] < map[nna][nnb]) {
//				
//
//					 DFS와 backtracking??????
//				}
//			}
//		}
//	}
//}

int solution_dfs(int a, int b) {
	int value = 0;
	if (dp[a][b] != 0) { //이미 dp에 값이 있다면 그 값을 반환한다.
		return dp[a][b];
	}
	dp[a][b] = 1; // 처음 시작점에서 언제나 하루는 살아있으므로
	for (int i = 0; i < 4; i++) // 상 좌 하 우 순서
	{
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) //범위 맞으면 
		{
			if (map[a][b] < map[nx][ny]) // 크다는 조건 맞으면 
			{
				dp[a][b] = Big(dp[a][b], solution_dfs(nx, ny) + 1); //dp를 갱신한다
			}
		}
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			K = Big(K, solution_dfs(i, j));
		}
	}
	cout << K << '\n';

	return 0;
}