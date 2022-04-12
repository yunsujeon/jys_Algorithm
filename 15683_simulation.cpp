//BP-cctv ȸ���� ����� �� ���θ� �������ߵȴ�.
//dfs���
/*1�� cctv : 4���� ����� ��
2�� cctv : 2����
3�� cctv : 4����
4�� cctv : 4����
5�� cctv : 1���� 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<pair<int, int>, int>> v;

int max;

void load() {
	//cctv ��ȣ�� ��ġ�� �޾Ƽ�
	//vector�� ���� ���� �Լ�
}

void cctv() {
	//cctv�� ����� �� ����ŭ �ݺ��ؾ� ��� ��츦 ������ ���ϰ�
	//1���� 2�� cctv�� �ִٸ� 4*2=8���� �ݺ�
	//8���� ���� ����Ž�� BP�� �ϴ°�

	queue < pair<pair<int, int>, int>> q;

	int cross=1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second != 0 && v[i].second !=6) { //��� cctv��
			if (v[i].second == 1)
				cross *= 4;
			else if (v[i].second == 2)
				cross *= 2;
			else if (v[i].second == 3)
				cross *= 4;
			else if (v[i].second == 4)
				cross *= 4;
			else if (v[i].second == 5)
				cross *= 1;
			q.push({ {v[i].first.first,v[i].first.second}, v[i].second });
		}
	}



}

int main() {
	int N, M, s;
	cin >> N >> M;
	max = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> s;
			v.push_back({ {i,j},s });
		}
	}
	
	cctv();

	//Ž���� �� �� ã���� Ž�����Ѱ��� 0�̵ɰ��̴�.
	//0�ΰ��� ���ڸ� ���� �ɰ��̴�.

	return 0;
}


#include <iostream>
#include <vector>

#define MAX 8
#define INF 987654321

using namespace std;

int map[MAX][MAX];

vector<int> cctv;
vector<pair<int, int>> cctvLocation;

int N, M;
int ans = INF;

void MapCopy(int(*a)[MAX], int(*b)[MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void spread(int dir, int x, int y) {
    //��
    if (dir == 0) {
        int ny = y - 1;
        if (ny < 0) return;
        if (map[ny][x] == 6) return;
        map[ny][x] = 9;
        spread(0, x, ny);
    }
    //��
    else if (dir == 1) {
        int nx = x + 1;
        if (nx > M - 1) return;
        if (map[y][nx] == 6) return;
        map[y][nx] = 9;
        spread(1, nx, y);
    }
    //��
    else if (dir == 2) {
        int ny = y + 1;
        if (ny > N - 1) return;
        if (map[ny][x] == 6) return;
        map[ny][x] = 9;
        spread(2, x, ny);
    }
    //��
    else {
        int nx = x - 1;
        if (nx < 0) return;
        if (map[y][nx] == 6) return;
        map[y][nx] = 9;
        spread(3, nx, y);
    }
}

void check() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cnt += 1;
            }
        }
    }
    if (cnt < ans)
        ans = cnt;
}

void dfs(int cnt) {
    if (cnt > (int)cctv.size() - 1) {
        //�簢���� �˻�
        check();
        return;
    }
    int kind = cctv[cnt];
    int x = cctvLocation[cnt].first;
    int y = cctvLocation[cnt].second;

    int temp[MAX][MAX];

    //1�� cctv�� 4����
    if (kind == 1) {
        for (int i = 0; i < 4; i++) {
            MapCopy(temp, map);
            spread(i, x, y);
            dfs(cnt + 1);
            MapCopy(map, temp);
        }
    }
    //2�� cctv�� 2����
    else if (kind == 2) {
        for (int i = 0; i < 2; i++) {
            MapCopy(temp, map);
            spread(i, x, y);
            spread(i + 2, x, y);
            dfs(cnt + 1);
            MapCopy(map, temp);
        }
    }
    //3�� cctv�� 4����
    else if (kind == 3) {
        for (int i = 0; i < 4; i++) {
            MapCopy(temp, map);
            spread(i, x, y);
            spread((i + 1) % 4, x, y);
            dfs(cnt + 1);
            MapCopy(map, temp);
        }
    }
    //4�� cctv�� 4����
    else if (kind == 4) {
        for (int i = 0; i < 4; i++) {
            MapCopy(temp, map);
            spread(i, x, y);
            spread((i + 1) % 4, x, y);
            spread((i + 2) % 4, x, y);
            dfs(cnt + 1);
            MapCopy(map, temp);
        }
    }
    //5�� cctv�� ���� ����x
    else {
        MapCopy(temp, map);
        for (int i = 0; i < 4; i++) {
            spread(i, x, y);
        }
        dfs(cnt + 1);
        MapCopy(map, temp);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            map[i][j] = temp;
            if (temp != 0 && temp != 6) {
                cctv.push_back(temp);
                cctvLocation.push_back(make_pair(j, i));
            }
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}