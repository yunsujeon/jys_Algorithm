#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int fishnum;
	int dir;
}fish;

fish map[4][4]; //맵에는 fishnum과 dir가 저장된다.

int dx[] = {-1,-1,0,1,1,1,0,-1}; //상 부터 반시계방향
int dy[] = {0.-1.-1.-1.0,1,1,1};

void solution() {

}

int main() {
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			map[i][j] = { a, b };
		}
	}

	solution();
	return 0;
}