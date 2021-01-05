//마법사 상어와 파이어스톰

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 64;
int N;
int Q;
int A[MAX][MAX];
int temp[MAX][MAX];
int play;

//얼음 회전하기, 동시에 융해하는게 중요하다.
void firestorm() {
	int temp;
	for (int a=1;a<=play;a++){
		for (int x = 0; x < pow(2, N); x+=pow(2,a)) { //시작점을 잡아주는
			for (int y = 0; y < pow(2, N); y+=pow(2,a)) { //시작점을 잡아주는
				//이로써 부분 격자별 좌측 상단 시작위치를 찾아내었다.
				for(int i=0;i<pow(2,a)-1;i++){ //시작위치에서 다시 돌려줘야된다.
					for(int j=0;j<pow(2,a)-1;j++){
						temp[x][y] = A[x + i][y + j];


				for (int j = 1; j <= pow(2, i)-1; j++) { //1,3,7까지 더해줘야됨
					//int j = pow(2, i - 1);
					temp = A[x][y]; //시작점 부터
					A[x][y] = A[x + j][y];
					A[x + j][y] = A[x + i][y + j];
					A[x + j][y + j] = A[x][y + j];
					A[x][y + j] = temp;
				}
			}
		}
}


int main() {
	cin >> N >>Q;
	for (int i = 0; i < pow(2,N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < Q; i++) { //횟수만 나타내준다.
		cin >> play;
		firestorm();
	}
	return 0;
}