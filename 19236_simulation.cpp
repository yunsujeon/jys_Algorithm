#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int fishnum;
	int dir;
}fish;

fish map[4][4]; //�ʿ��� fishnum�� dir�� ����ȴ�.

int dx[] = {-1,-1,0,1,1,1,0,-1}; //�� ���� �ݽð����
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