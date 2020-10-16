
#include <iostream>
#define MAX 1001
using namespace std;

int graph[MAX][MAX];
int result = 0;

int main() {
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> graph[i][j];
		}
	}
	//그래프생성완료

	//세로가 홀수
	if (R % 2){
		for (int y = 0; y < R; y++){
			for (int x = 0; x < C - 1; x++)
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			if (y != R - 1)
				result += 'D';
		}
	}

	//세로가 짝수 가로가 홀수
	else if (!(R % 2) && C % 2){
		for (int x = 0; x < C; x++){
			for (int y = 0; y < R - 1; y++)
				if (x % 2 == 0)
					result += 'D';
				else
					result += 'U';
			if (x != C - 1)
				result += 'R';
		}
	}

	//가로 세로가 모두 짝수일때 : 복잡
	/*
	알고리즘
	최소 하나의 위치를 방문하지 못한다.
	전체를 탐색해서 가장 작은 수를 골라서 그수를 지나지 않는게 아닌
	골라서 지나지 말아야 한다.
	전체를 체스판처럼 검정, 흰색으로 칠하면 시작점과 끝점은 검정색이 되게 된다.
	그 때 중간에서 검정색 점을 지나지 말게 하면 경로가 그려지지 않는다.
	흰색 점 중에 가장 작은 값 중 하나를 지나지 말게 해야된다.
	만나기 전까지는 아까와 같이 뱀처럼 이동한다음에
	만나는 줄에서는 세로뱀으로 구불부불하게 지나가야 한다. 
	그래야 피해갈수있다.
	*/



}
