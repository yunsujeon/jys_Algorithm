//BP
//최소경로 bfs사용..
//여태까지의 변화를 저장하는게 키포인트

#include <iostream>
#include <string>
#include <queue>
#include <cstring> //memset위해

using namespace std;

int D, S, L, R;
int T, A, B;
bool visited[10000];

string bfs() {//d s l r 했을때 결과를 가지고 계속 bfs 하는것
	queue <pair<int,string>> q;
	q.push({A, ""});
	visited[A] = true;

	while (!q.empty()) {
		int a = q.front().first;
		string change = q.front().second;
		q.pop();

		if (a == B)
			return change;
		
		int curNum = (2 * a) % 10000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum,change + "D" });
		}

		curNum = (a - 1) < 0 ? 9999 : a - 1;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum,change + "S" });
		}

		curNum = (a / 1000) + (a / 100 - (a / 1000) * 10) * 1000 + (a / 10 - (a / 100) * 10) * 100 + (a - (a / 10) * 10) * 10;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum,change + "L" });
		}

		curNum = (a / 1000) * 100 + (a / 100 - (a / 1000 * 10)) * 10 + (a / 10 - (a / 100) * 10) + (a - (a / 10) * 10) * 1000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum,change + "R" });
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		cin >> A >> B;
		cout << bfs() << endl;
	}
	return 0;
}

/*
	L 1234 -> 2341 1000의 자리가 1의자리로 간다 %연산으로 해결
	1. 문자열로 바꿔서 배열자리바꾼후 다시 int로 바꿔주는방법
	2. 그냥 수식으로 해결하는 방법
	d1 = 1234/1000 = 1
	d2 = 1234/100 = 12 - (1234/1000)*10 = 10 *1000 = 2000
	d3 = 1234/10 = 123 - (1234/100)*10 = 120 *100 = 300
	d4 = 1234 - (1234/10)*10 = 1230 = 4 *10 = 40

	1234 4123
	d1 = 1234/1000 *100 = 100
	d2 = 1234/100 - 1234/1000*10 *10 = 20
	d3 = 1234/10 - 1234/100 *10 = 3
	d4 = 1234 - 1234/10 *10 *1000 = 4000
*/