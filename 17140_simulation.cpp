#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int rsize=3, csize=3; //초기는 3
int r, c, k;
int square[101][101] = { 0, };
int cnt = 0;

int solution() {
	int copymap[101][101] = { 0, };
	while (cnt<=100) {
		if (square[r-1][c-1] == k) return cnt; //R연산인지 C연산인지를 결정하는 부분
		if (rsize >= csize) {//R연산이라면
			int MAX = 0;
			for (int i = 0; i < rsize; i++) { //행마다 실행
				vector <int> v1;
				for (int j = 0; j < csize; j++) {
					if (square[i][j] != 0) v1.push_back(square[i][j]);
				}
				sort(v1.begin(), v1.end());
				vector<pair<int, int> >v2;
				int ct = 1;
				for (int h = 0; h < v1.size(); h++) {
					if (h==v1.size()-1){
						v2.push_back({ ct, v1[h] }); //sort 쉽게하기위해 일부러 거꾸로넣는다.
						ct = 1;
					}
					else if (v1[h] != v1[h + 1]) {
						v2.push_back({ ct, v1[h] }); //sort 쉽게하기위해 일부러 거꾸로넣는다.
						ct = 1;
					}
					else if (v1[h] == v1[h + 1]) {
						ct++;
						continue;
					}
				}
				if (MAX <= v2.size()*2) MAX = v2.size()*2;
				sort(v2.begin(), v2.end());
				for (int h = 0; h < v2.size(); h++) {
					if (h == 50) break;
					else {
						copymap[i][h * 2] = v2[h].second;
						copymap[i][h * 2 + 1] = v2[h].first;
					}
				}
			}
			csize = MAX;
		}

		else {//C연산이라면
			int MAX = 0;
			for (int j = 0; j < csize; j++) { // 열마다 실행
				vector <int> v1;
				for (int i = 0; i < rsize; i++) {
					if (square[i][j] != 0) v1.push_back(square[i][j]);
				}
				sort(v1.begin(), v1.end());
				vector<pair<int, int> >v2;
				int ct = 1;
				for (int h = 0; h < v1.size(); h++) {
					if (h == v1.size() - 1) {
						v2.push_back({ ct, v1[h] }); //sort 쉽게하기위해 일부러 거꾸로넣는다.
						ct = 1;
					}
					else if (v1[h] != v1[h + 1]) {
						v2.push_back({ ct, v1[h] }); //sort 쉽게하기위해 일부러 거꾸로넣는다.
						ct = 1;
					}
					else if (v1[h] == v1[h + 1]) {
						ct++;
						continue;
					}
				}
				if (MAX <= v2.size() * 2) MAX = v2.size() * 2;
				sort(v2.begin(), v2.end());
				for (int h = 0; h < v2.size(); h++) {
					if (h == 50) break;
					else {
						copymap[h * 2][j] = v2[h].second;
						copymap[h * 2 + 1][j] = v2[h].first;
					}
				}
			}
			rsize = MAX;
		}

		cnt += 1;
		memcpy(square, copymap, sizeof(copymap)); //copymap을 map에 복사한다.
		memset(copymap, 0, sizeof(copymap));
	}
	return -1;
}

int main() {
	cin >> r >> c >> k;
	int in=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> in;
			square[i][j] = in;
		}
	} //초기 map을 만들어준다.
	cout << solution() << '\n';
	return 0;
}