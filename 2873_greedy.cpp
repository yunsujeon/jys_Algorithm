#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1000
#define INF 1000000000 //10억으로 최대값을 표현
using namespace std;

int graph[MAX][MAX];
string result;

int main() {
	int R, C;
	cin >> R >> C;
	pair<int, int> no;// 지나지 말아야 할 지점. 가장 행복지수 낮은지점
	int minscore = INF;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> graph[y][x];
			//거치지 않아도 될 칸 중에 최소점수라면
			if ((y + x) % 2 && minscore > graph[y][x])
			{
				minscore = graph[y][x]; //minxcore를 갱신해주고 (계속찾기위해)
				no = { y,x }; //거치지 말아야 할 점을 저장해준다.
			}
		}
	}
	//그래프생성완료 no 까지 만들었으니 방법4)에서 그걸 피해서 움직여보자.

	if (R % 2){ //세로가 홀수 즉 탐색방법 1,2의 경우이다.
		for (int y = 0; y < R; y++){ //세로
			for (int x = 0; x < C - 1; x++) 
				if (y % 2 == 0) //짝수번 라인이면
					result += 'R'; //R
				else //홀수번 라인이면 
					result += 'L'; //L
			if (y != R - 1) //끝이라면 Down을 해야할것
				result += 'D';
		}
	}

	else if (!(R % 2) && C % 2){ 	//세로가 짝수 가로가 홀수
		for (int x = 0; x < C; x++){ //가로
			for (int y = 0; y < R - 1; y++)
				if (x % 2 == 0)
					result += 'D';
				else
					result += 'U';
			if (x != C - 1)
				result += 'R'; //끝이라면 오른쪽으로 이동
		}
	}

	else if (!(R % 2) && !(C % 2)) {
		//우선 no 좌표 전까지 위에서 아래로 내려오는 코드이다.
		int nR, nC;
		if (no.first % 2 == 1) //홀수번째 라인이면
			nR = no.first - 1; //그 전줄까지만 내려오도록한다.
		else
			nR = no.first;
		for (int y = 0; y < nR; y++) {
			for (int x = 0; x < C - 1; x++) {
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
			result += 'D';
		}
		//그 다음 움직임은 no 좌표의 대각선 아래까지 움직이는거다.
		nC = no.second; //x좌표
		for (int x = 0; x < nC; x++) {
			if (x % 2 == 0)
				result += 'DR';
			else
				result += 'UR';
		}
		//no좌표를 넘어갔으면 최 우측으로 이동시켜줄것이다.
		for (int x = nC; x < C - 1; x++) {
			if (x % 2 == 0)
				result += 'RD';
			else
				result += 'RU';
		}

		//마지막 구분동작
		if (no.first % 2 == 0)
			nR = R - (no.first + 2);
		else
			nR = R - (no.first + 1);

		for (int y = 0; y < nR; y++) {
			result += 'D';
			for (int x = 0; x < C - 1; x++) {
				if (y % 2 == 0)
					result += 'L';
				else
					result += 'R';

			}
		}
	}
	cout << result << '\n';
	return 0;
}
