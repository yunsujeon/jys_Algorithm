
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int N, M, K;
int plus_map[11][11] = { 0, }; //매년 추가해줄 양분
int map[11][11]; //초기 양분 5
//vector<vector<vector<int>>> t(11, vector<vector<int>>(11, vector<int>(11)));
//vector<vector<vector<int>>> copy_t(11, vector<vector<int>>(11, vector<int>(11)));
vector <int> t[11][11]; //나무의 정보 저장
int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };


void sol() {
	fill(&map[0][0], &map[10][11], 5);
	//memset(map, 5, sizeof(map));
	while (K--) { //K년이 지난 후
		//봄 + 여름
		//sort(t[0][0].begin(), t[0][0].end()); //나이작은순정렬
		for (int i = 0; i < N; i++) { //for문 안돌리고 좌표를 queue에 다 저장해둔다면?
			for (int j = 0; j < N; j++) { //vector에 나무가 있는곳을 찾는다.
				if (!t[i][j].empty()) { //나무가 있다면
					int size = t[i][j].size(); //나무개수
					int vita = map[i][j]; //위치의 양분 양
					sort(t[i][j].begin(), t[i][j].end());
					for (int k = 0; k < t[i][j].size(); k++) { 
						if (t[i][j][k] <= vita) {
							vita -= t[i][j][k]; //양분에서 나무나이만큼 뺀다.
							t[i][j][k]++; //먹였다면 나무의 나이증가
							map[i][j] = vita;
						}
						else { //양분이 부족한 경우 나무 죽는다.
							//0으로 처리할 경우 나이가 0인게 되므로 없애야됨
							for (int er = t[i][j].size()-1; er >= k; er--) {
								int die_vita = t[i][j][er]/2;
								map[i][j] += die_vita; //양분보충
								t[i][j].pop_back();
							} //뒤에서부터 다 지운다.
							break; //for문 탈출한다. 삭제해서 다음인덱스가 없기때문
						}
					}
				}
			}
		}
		//가을
		for (int i = 0; i < N; i++) { //for문 안돌리고 좌표를 queue에 다 저장해둔다면?
			for (int j = 0; j < N; j++) { //vector에 나무가 있는곳을 찾는다.
				if (!t[i][j].empty()) { //나무가 한그루라도 있다면 진행
					for (int k = 0; k < t[i][j].size(); k++) {
						int age = t[i][j][k];
						if ((age % 5) == 0) { //5의 배수라면
							for (int z = 0; z < 8; z++) { //8방으로 나무를 퍼뜨린다.
								int nr = i + dr[z];
								int nc = j + dc[z];
								if (nr >= 0 && nr < N && nc >= 0 && nc < N) { //범위만족
									t[nr][nc].push_back(1); //나이 1인 나무 추가
								}
							}
						}
					}
				}
			}
		}
		//겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += plus_map[i][j];
			}
		}
	}
}

int main() {
	cin >> N >> M >> K; //배열크기, 심은나무갯수, K년후
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			plus_map[i][j] = input;
		}
	}
	int x, y, age;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> age;
		t[x - 1][y - 1].push_back(age);
	}
	sol();
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += t[i][j].size();
		}
	}
	cout << result << '\n';
	return 0;
}

//이후 삼성코테보다 기본적인 알고리즘 다시복습