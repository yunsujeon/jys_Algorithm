/*모든정점에서 모든정점으로의 최단경로를 구하고싶다면 플로이드와샬
'거쳐가는 정점'을 기준으로 최단거리를 구하는 것
*/

#include <stdio.h>

int number = 4;
int inf = 10000000;

int a[4][4] = {
{0,5,inf,8},
{7,0,9,inf},
{2,inf,0,4},
{inf,inf,3,0}
};

void floydWarshall() {
	int d[4][4];

	//그래프를 초기화한다.
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	for (int k = 0; k < number; k++) { //0 1 2 3
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) { //k를 거쳐가는경우를 따져준다.
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
}

int main() {
	floydWarshall();
}