//dfs를 이용한 완전탐색

#include <iostream>
using namespace std;

int n;
int map[11][11];
int visit[11];
int Min = 98765432;
int cnt = 0;

void dfs(int first, int a, int sum) { //0으로 시작 0으로 돌아와야됨
    if (first == a && cnt == n) { //처음으로 돌아왔을 때, N번만큼 돌았으면 인정
        if (Min > sum) {
            Min = sum;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visit[i]==0 && map[a][i]!=0) { //방문하지 않았고 map에 값이 있으면
            visit[i] = 1;
            sum += map[a][i];
            cnt++;
            dfs(first, i, sum);
            //돌았는데 도출이 안됐을 경우에 다른거 돌아야되니깐 dfs전으로 원상복구해줌
            visit[i] = 0;
            sum -= map[a][i];
            cnt--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
        visit[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i, 0);
    }

    cout << Min << '\n';
    return 0;
}
