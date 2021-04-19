#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int rsize=3, csize=3; //�ʱ�� 3
int r, c, k;
int square[101][101] = { 0, };
int cnt = 0;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution() {
	int copymap[101][101] = { 0, };
	while (cnt<100) {
		if (square[r-1][c-1] == k) return cnt; //R�������� C���������� �����ϴ� �κ�
		if (rsize >= csize) {//R�����̶��
			int MAX = 0;
			for (int i = 0; i < rsize; i++) { //�ึ�� ����
				vector <int> v1;
				for (int j = 0; j < csize; j++) {
					if (square[i][j] != 0) v1.push_back(square[i][j]);
				}
				sort(v1.begin(), v1.end());
				vector<pair<int, int> >v2;
				int ct = 1;
				for (int h = 0; h < v1.size(); h++) {
					if (h==v1.size()-1){
						v2.push_back({ ct, v1[h] }); //sort �����ϱ����� �Ϻη� �Ųٷγִ´�.
						ct = 1;
					}
					else if (v1[h] != v1[h + 1]) {
						v2.push_back({ ct, v1[h] }); //sort �����ϱ����� �Ϻη� �Ųٷγִ´�.
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

		else {//C�����̶��
			int MAX = 0;
			for (int j = 0; j < csize; j++) { // ������ ����
				vector <int> v1;
				for (int i = 0; i < rsize; i++) {
					if (square[i][j] != 0) v1.push_back(square[i][j]);
				}
				sort(v1.begin(), v1.end());
				vector<pair<int, int> >v2;
				int ct = 1;
				for (int h = 0; h < v1.size(); h++) {
					if (h == v1.size() - 1) {
						v2.push_back({ ct, v1[h] }); //sort �����ϱ����� �Ϻη� �Ųٷγִ´�.
						ct = 1;
					}
					else if (v1[h] != v1[h + 1]) {
						v2.push_back({ ct, v1[h] }); //sort �����ϱ����� �Ϻη� �Ųٷγִ´�.
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
		memcpy(square, copymap, sizeof(copymap)); //copymap�� map�� �����Ѵ�.
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
	} //�ʱ� map�� ������ش�.
	cout << solution() << '\n';
	return 0;
}