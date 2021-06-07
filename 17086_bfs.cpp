// 최단거리의 최대

#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
    int x, y, val;
};
info tmp;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int arr[50][50];
int check[50][50];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int row, col;
    cin >> row >> col;
    queue<info> q;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            check[i][j] = MAX;
            if (arr[i][j] == 1) {
                tmp.x = j;
                tmp.y = i;
                tmp.val = 0;
                q.push(tmp);
                check[i][j] = 0;
            }
        }
    }
    int result = 0;
    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cv = q.front().val;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < col && ny<row && check[ny][nx]>cv + 1) {
                check[ny][nx] = cv + 1;
                tmp.x = nx;
                tmp.y = ny;
                tmp.val = cv + 1;
                q.push(tmp);
                result = max(result, cv + 1);
            }
        }
    }
    cout << result << '\n';
    //cout << result << endl;

    //system("pause");

    return 0;
}