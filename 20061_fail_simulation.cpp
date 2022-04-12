#include <iostream>
#include <string.h>

using namespace std;

int map[10][10] = { 0, };

int N;
int t, x, y;
int cnt = 0;
int flag = 0;
int clearb[10] = { 0, }; //0�̸� �ƹ��͵� ����. 1�̸� ���� �ִ�.
int clearg[10] = { 0, };

void solution() { //���� map�� ����ϱ� ������ copymap ������� ���� ��
	//�Ķ������� �̵� //���������� �̵��Ѵ�. //�����ʿ� �ִ� �ֺ��� �̵���Ų��.

	flag = 0;
	for (int i = 0; i <= 3; i++) { //������ �Ʒ��� Ž��
		for (int j = 3; j >= 0; j--) { //�����ʿ��� �������� Ž��
			if (map[i][j] == 1 && flag == 0) {
				for (int z = 4; z <= 9; z++) {
					if (t == 1) {
						if (map[i][z] == 0) { //0�϶��� �־��ְ�
							if (z == 4)
								map[i][z] = 1;
							else {
								map[i][z - 1] = 0;
								map[i][z] = 1;
							}
						}
						else {
							flag = 1;
							break; //�ѹ��̶� �ɸ��� ���̻� X
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

	flag = 0;	//�ʷ������� �̵� //���������� �̵��Ѵ�.
	for (int i = 3; i >= 0; i--) { //�Ʒ����� ���� Ž��
		for (int j = 0; j <= 3; j++) { //���ʿ��� ���������� Ž��
			if (map[i][j] == 1 && flag == 0) {
				for (int z = 4; z <= 9; z++) {
					if (t == 1) {
						if (map[z][j] == 0) { //0�϶��� �־��ְ�
							if (z == 4)
								map[z][j] = 1;
							else {
								map[z - 1][j] = 0;
								map[z][j] = 1;
							}
						}
						else {
							flag = 1;
							break; //�ѹ��̶� �ɸ��� ���̻� X
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

	//�Ѵ� �̵��� ������ �� ������ ���� ���� �����ָ� ������ �ø���.
	//�Ķ������� �����ָ� �����ø���.
	for (int i = 9; i >= 4; i--) { //9������ ���� �ٿ����鼭 ����.
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

	//�ʷϻ� �����ָ� �����ø���.
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

	//�������� ��������� (�Ķ���)
	int ii = 10;
	while (ii--) {
		if (clearb[ii] == 0) { //0�� ���ö����� �̷�����.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[z][j+1] = map[z][j]; //�ڷ� �̷��ش�.
					map[z][j] = 0;
				}
			}
		}
		else {
			break; //0�� �ѹ��̶� �ƴ϶�� Ż���ϱ�
		}
	}

	ii = 10;
	while(ii--){
		if (clearg[ii] == 0) { //0�� ���ö����� �̷�����.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[j+1][z] = map[j][z];
					map[j][z] = 0;
				}
			}
		}
		else {
			break; //0�� �ѹ��̶� �ƴ϶�� Ż���ϱ�
		}
	}

	//���� ���� ĭ�� ����� ó�����ش�. 
	int j = 0;
	while (j < 4) {
		j++;
		if (map[j][5] == 1) {
			j = 0; //�ʱ�ȭ���Ѽ� �ٽð˻��ϰ� �ϱ�
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

	//�ʷϻ���
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

	//�������� ��������� (�Ķ���)
	ii = 10;
	while (ii--) {
		if (clearb[ii] == 0) { //0�� ���ö����� �̷�����.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[z][j + 1] = map[z][j]; //�ڷ� �̷��ش�.
					map[z][j] = 0;
				}
			}
		}
		else {
			break; //0�� �ѹ��̶� �ƴ϶�� Ż���ϱ�
		}
	}

	//������ ĭ�� �� ��ĭ�̸� ��� ����
	ii = 10;
	while (ii--) {
		if (clearg[ii] == 0) { //0�� ���ö����� �̷�����.
			for (int j = 8; j >= 4; j--) {
				for (int z = 0; z <= 3; z++) {
					map[j + 1][z] = map[j][z];
					map[j][z] = 0;
				}
			}
		}
		else {
			break; //0�� �ѹ��̶� �ƴ϶�� Ż���ϱ�
		}
	}
}

int main() {
	cin >> N; //����� ���� Ƚ��
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
