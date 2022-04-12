#include <iostream>
#include <string.h>

using namespace std;

int map[10][10] = { 0, };

int N;
int t, x, y;
int cnt = 0;
int flag = 0;
int clearb[10] = { 0, }; //0이면 아무것도 없다. 1이면 뭔가 있다.
int clearg[10] = { 0, };

void solution() { //같은 map을 사용하기 때문에 copymap 사용하지 않을 것
	//파란쪽으로 이동 //막힐때까지 이동한다. //오른쪽에 있는 애부터 이동시킨다.

	flag = 0;
	for (int i = 0; i <= 3; i++) { //위에서 아래로 탐색
		for (int j = 3; j >= 0; j--) { //오른쪽에서 왼쪽으로 탐색
			if (map[i][j] == 1 && flag == 0) {
				for (int z = 4; z <= 9; z++) {
					if (t == 1) {
						if (map[i][z] == 0) { //0일때만 넣어주고
							if (z == 4)
								map[i][z] = 1;
							else {
								map[i][z - 1] = 0;
								map[i][z] = 1;
							}
						}
						else {
							flag = 1;
							break; //한번이라도 걸리면 더이상 X
						}
					}
					else if (t == 2) {
						if (z == 4)
							continue;
						else if (z == 5) {
							if (map[i][z] == 0 && map[i][z - 1] == 0) {
								map[i][z] = 1;
								map[i][z - 1] = 1;
							}
						}
						else if (map[i][z] == 0) {
							map[i][z - 1] = 0;
							map[i][z - 2] = 0;
							map[i][z] = 1;
							map[i][z - 1] = 1;
							if (z == 9) {
								flag = 1;
								break;
							}
						}
						if (z == 9) {
							flag = 1;
							break;
						}
					}
					else if (t == 3) {
						if (map[i][z] == 0 && map[i + 1][z] == 0) {
							if (z == 4) {
								map[i][z] = 1;
								map[i + 1][z] = 1;
							}
							else {
								map[i][z - 1] = 0;
								map[i + 1][z - 1] = 0;
								map[i][z] = 1;
								map[i + 1][z] = 1;
								if (z == 9) {
									flag = 1;
									break;
								}
							}
						}
						else {
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}

	flag = 0;	//초록쪽으로 이동 //막힐때까지 이동한다.
	for (int i = 3; i >= 0; i--) { //아래에서 위로 탐색
		for (int j = 0; j <= 3; j++) { //왼쪽에서 오른쪽으로 탐색
			if (map[i][j] == 1 && flag == 0) {
				for (int z = 4; z <= 9; z++) {
					if (t == 1) {
						if (map[z][j] == 0) { //0일때만 넣어주고
							if (z == 4)
								map[z][j] = 1;
							else {
								map[z - 1][j] = 0;
								map[z][j] = 1;
							}
						}
						else {
							flag = 1;
							break; //한번이라도 걸리면 더이상 X
						}
					}
					else if (t == 2) {
						if (map[z][j] == 0 && map[z][j + 1] == 0) {
							if (z == 4) {
								map[z][j] = 1;
								map[z][j + 1] = 1;
							}
							else {
								map[z - 1][j] = 0;
								map[z - 1][j + 1] = 0;
								map[z][j] = 1;
								map[z][j + 1] = 1;

								if (z == 9) {
									flag = 1;
									break;
								}
							}
						}
						else {
							flag = 1;
							break;
						}
					}
					else if (t == 3) {
						if (z == 4)
							continue;
						else if (z == 5) {
							if (map[z][j] == 0 && map[z - 1][j] == 0) {
								map[z][j] = 1;
								map[z - 1][j] = 1;
							}
						}
						else if (map[z][j] == 0) {
							map[z - 2][j] = 0;
							map[z - 1][j] = 0;
							map[z][j] = 1;
							map[z - 1][j] = 1;
							if (z == 9) {
								flag = 1;
								break;
							}
						}
						else {
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}

	if (t == 1) {
		map[x][y] = 0;
	}
	else if (t == 2) {
		map[x][y] = 0;
		map[x][y + 1] = 0;
	}
	else if (t == 3) {
		map[x][y] = 0;
		map[x + 1][y] = 0;
	}

	memset(clearb, 0, sizeof(clearb));
	memset(clearg, 0, sizeof(clearg));

	//둘다 이동을 마쳤을 때 가득찬 열과 행을 지워주며 점수를 올린다.
	//파란색부터 지워주며 점수올린다.
	for (int i = 9; i >= 4; i--) { //9열부터 열을 줄여가면서 본다.
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[j][i];
			else if (j == 1)
				i2 = map[j][i];
			else if (j == 2)
				i3 = map[j][i];
			else
				i4 = map[j][i];
		}
		if (i1 == 1 && i2 == 1 && i3 == 1 && i4 == 1) {
			cnt++;
			for (int j = 0; j <= 3; j++) {
				map[j][i] = 0;
			}
		}
	}
	for (int i = 9; i >= 4; i--) {
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[j][i];
			else if (j == 1)
				i2 = map[j][i];
			else if (j == 2)
				i3 = map[j][i];
			else
				i4 = map[j][i];
		}
		if (i1 == 1 || i2 == 1 || i3 == 1 || i4 == 1) {
			clearb[i] = 1;
		}
	}

	//초록색 지워주며 점수올린다.
	for (int i = 9; i >= 4; i--) {
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[i][j];
			else if (j == 1)
				i2 = map[i][j];
			else if (j == 2)
				i3 = map[i][j];
			else
				i4 = map[i][j];
		}
		if (i1 == 1 && i2 == 1 && i3 == 1 && i4 == 1) {
			cnt++;
			for (int j = 0; j <= 3; j++) {
				map[i][j] = 0;
			}
		}
	}

	for (int i = 9; i >= 4; i--) {
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[i][j];
			else if (j == 1)
				i2 = map[i][j];
			else if (j == 2)
				i3 = map[i][j];
			else
				i4 = map[i][j];
		}
		if (i1 == 1 || i2 == 1 || i3 == 1 || i4 == 1) {
			clearg[i] = 1;
		}
	}

	//지웠으면 합쳐줘야지 (파란색)
	int ii = 10;
	while (ii--) {
		if (clearb[ii] == 0) { //0이 나올때마다 미뤄주자.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[z][j+1] = map[z][j]; //뒤로 미뤄준다.
					map[z][j] = 0;
				}
			}
		}
		else {
			break; //0이 한번이라도 아니라면 탈출하기
		}
	}

	ii = 10;
	while(ii--){
		if (clearg[ii] == 0) { //0이 나올때마다 미뤄주자.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[j+1][z] = map[j][z];
					map[j][z] = 0;
				}
			}
		}
		else {
			break; //0이 한번이라도 아니라면 탈출하기
		}
	}

	//이후 연한 칸의 블록을 처리해준다. 
	int j = 0;
	while (j < 4) {
		j++;
		if (map[j][5] == 1) {
			j = 0; //초기화시켜서 다시검사하게 하기
			for (int z = 9; z >= 4; z--) {
				for (int y = 0; y <= 3; y++) {
					if (z == 9)
						map[y][z] = 0;
					else {
						map[y][z + 1] = map[y][z];
						map[y][z] = 0;
					}
				}
			}
		}
	}

	//초록색도
	j = 0;
	while (j < 4) {
		j++;
		if (map[5][j] == 1) {
			j = 0;
			for (int z = 9; z >= 4; z--) {
				for (int y = 0; y <= 3; y++) {
					if (z == 9)
						map[z][y] = 0;
					else {
						map[z+1][y] = map[z][y];
						map[z][y] = 0;
					}
				}
			}
		}
	}

	memset(clearb, 0, sizeof(clearb));
	memset(clearg, 0, sizeof(clearg));

	for (int i = 9; i >= 4; i--) {
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[j][i];
			else if (j == 1)
				i2 = map[j][i];
			else if (j == 2)
				i3 = map[j][i];
			else
				i4 = map[j][i];
		}
		if (i1 == 1 || i2 == 1 || i3 == 1 || i4 == 1) {
			clearb[i] = 1;
		}
	}

	for (int i = 9; i >= 4; i--) {
		int i1, i2, i3, i4;
		for (int j = 0; j <= 3; j++) {
			if (j == 0)
				i1 = map[i][j];
			else if (j == 1)
				i2 = map[i][j];
			else if (j == 2)
				i3 = map[i][j];
			else
				i4 = map[i][j];
		}
		if (i1 == 1 || i2 == 1 || i3 == 1 || i4 == 1) {
			clearg[i] = 1;
		}
	}

	//지웠으면 합쳐줘야지 (파란색)
	ii = 10;
	while (ii--) {
		if (clearb[ii] == 0) { //0이 나올때마다 미뤄주자.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[z][j + 1] = map[z][j]; //뒤로 미뤄준다.
					map[z][j] = 0;
				}
			}
		}
		else {
			break; //0이 한번이라도 아니라면 탈출하기
		}
	}

	//마지막 칸이 다 빈칸이면 계속 비운다
	ii = 10;
	while (ii--) {
		if (clearg[ii] == 0) { //0이 나올때마다 미뤄주자.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[j + 1][z] = map[j][z];
					map[j][z] = 0;
				}
			}
		}
		else {
			break; //0이 한번이라도 아니라면 탈출하기
		}
	}
}

int main() {
	cin >> N; //블록을 놓은 횟수
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		if (t == 1) {
			map[x][y] = 1;
		}
		else if (t == 2) {
			map[x][y] = 1;
			map[x][y + 1] = 1;
		}
		else if (t == 3) {
			map[x][y] = 1;
			map[x + 1][y] = 1;
		}
		solution();
	}
	cout << cnt << endl;

	int hap = 0;
	for (int i = 9; i >= 4; i--) {
		for (int j = 0; j <= 3; j++) {
			if (map[j][i] == 1)
				hap += 1;
			if (map[i][j] == 1)
				hap += 1;
		}
	}

	cout << hap;
	return 0;
}
