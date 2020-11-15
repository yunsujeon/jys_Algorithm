/* 퍼즐
입력을 2차원 배열로 받지말고 문자열로 처리한다.
정답문자열은 123456780 이고 swap이 가능한 위치에 swap하면서 찾아낸다
string a = "12345" 에서 a.find('2') 하면 1이 반환 될 것 인덱스번호가 반환됨
0의 인덱스를 찾은 후에 상하좌우의 값을 찾아 바꾸고 bfs 실행한다
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm> //swap 사용위해
using namespace std;

string Start, End;
set<string> visit; //visit을 set화 시키기 위해 set 사용

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<string, int>> q;
	q.push({ Start,0 });
	visit.insert(Start);
	while (q.empty() == 0) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == End)
			return cnt;
		int zero = cur.find('0'); //0의 인덱스
		int x = zero / 3; //0의 인덱스의 x값
		int y = zero % 3; //0의 인덱스의 y값
		for (int i = 0; i < 4; i++) { //0의 상하좌우 보기위해
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) { //범위
				string next = cur;
				swap(next[x * 3 + y], next[nx * 3 + ny]); //일렬로 펼쳐서 swap
				if (visit.find(next) == visit.end()) { //같은문자열이 없다면 (즉.end()라면)
					visit.insert(next); //삽입하기
					q.push({ next, cnt + 1 }); //cnt를 증가시켜 큐에넣기
				}
			}
		}
	}
	return -1;
}

int main() {

	End = "123456780";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			char Tmp = a + '0'; //숫자들어온거에 '0'을 붙여 문자화
			Start = Start + Tmp;
		}
	}
	cout << bfs() << endl;
	return 0;
}