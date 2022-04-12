#define MAX 21

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, k;
vector <int> map[MAX][MAX]; //map�� �������� �� ������ �� ������ vector�� ��������
vector <pair<int, int>> smellmap[MAX][MAX];
vector <int> tempmap[MAX][MAX]; //map�� �������� �� ������ �� ������ vector�� ��������
vector <pair<int, int>> smelltempmap[MAX][MAX];
int sharkstate[MAX];
int sharkd[MAX][4][4];

int a = 1;
int b = 2;

void spread() { //�� �ڽ��� ������ �Ѹ���. move����
	//�ڽ��� ��ġ�� �ڽ��� ������ �Ѹ���.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j][0] != 0) { //spread�� �Ҷ� 0�����ۿ� �������� �����״�
				smellmap[i][j].push_back({ map[i][j][0],k});
				smelltempmap[i][j].push_back({ map[i][j][0],k });
			}
		}
	}
}

void eatshark() {
	//��ĭ�� ���������� �� �ִٸ� ���� ��ȣ ���� �Ѱܳ���.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() != 1) {
				int max = *max_element(map[i][j].begin(), map[i][j].end());
				memset(map[i][j], 0, map[i][j].size());
				map[i][j][0] = max;
			}
		}
	}
}

void move() {
	//�˰��� ���� �����δ�.
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			if (map[i][j][0] != 0) { //map�� �� �ְ� ( ���������� ã���� �ȵǰ� �ѹ��� �̵��ؾ��ϹǷ� temp�迭 �̿��Ѵ�.)
				
				int name = map[i][j][0]; //����� ��ȣ, �ڱ⳿��
				int state = sharkstate[name]; //����ǹ���
				int check = 0;

				for (int z =0; z<4; z++){ //4������ �����鼭 (�켱������� �ݺ�)
					int way = sharkd[name][state][z];
					int up = map[i - 1][j][0];
					int down = map[i + 1][j][0];
					int left = map[i][j - 1][0];
					int right = map[i][j + 1][0];
					//way�� ���� ���, ���⿡ �´� �����̴�.
					switch (way) { //�� �Ʒ� ���� ������
					case 0 : 
						if (i - 1 >= 0 && i-1 < N) { //����Ȯ��
							if (up == 0) {
								sharkstate[name] = 1; //����� ������ ������
								smelltempmap[i - 1][j].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
								tempmap[i - 1][j].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
								smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
								tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
								check = 1;
							}
						}
					case 1:
						if (i + 1 >= 0 && i+1 < N) { //����Ȯ��
							if (down == 0) {
								sharkstate[name] = 2; //����� ������ ������
								smelltempmap[i + 1][j].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
								tempmap[i + 1][j].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
								smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
								tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
								check = 1;
							}
						}
					case 2:
						if (j-1 >= 0 && j - 1 < N) { //����Ȯ��
							if (left == 0) {
								sharkstate[name] = 3; //����� ������ ������
								smelltempmap[i][j-1].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
								tempmap[i][j-1].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
								smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
								tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
								check = 1;
							}
						}
					case 3:
						if (j + 1 >= 0 && j + 1 < N) { //����Ȯ��
							if (down == 0) {
								sharkstate[name] = 4; //����� ������ ������
								smelltempmap[i][j+1].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
								tempmap[i][j+1].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
								smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
								tempmap[i][j].pop_back();
								smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
								tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
								check = 1;
							}
						}
					}
				}
				if (check == 0) { //�ѱ������� �����ٸ� �ٽ� for�� ���鼭 �ڽ��� ������ �ִ�ĭ�� ���ߵȴ�.
					for (int z = 0; z < 4; z++) { //4������ �����鼭 (�켱������� �ݺ�)
						int way = sharkd[name][state][z];
						int up = map[i - 1][j][0];
						int down = map[i + 1][j][0];
						int left = map[i][j - 1][0];
						int right = map[i][j + 1][0];
						//way�� ���� ���, ���⿡ �´� �����̴�.
						switch (way) { //�� �Ʒ� ���� ������
						case 0:
							if (i - 1 >= 0 && i - 1 < N) { //����Ȯ��
								if (up == name) {
									sharkstate[name] = 1; //����� ������ ������
									smelltempmap[i - 1][j].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
									tempmap[i - 1][j].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
									smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
									tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
									check = 1;
								}
							}
						case 1:
							if (i + 1 >= 0 && i + 1 < N) { //����Ȯ��
								if (down == name) {
									sharkstate[name] = 2; //����� ������ ������
									smelltempmap[i + 1][j].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
									tempmap[i + 1][j].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
									smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
									tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
									check = 1;
								}
							}
						case 2:
							if (j - 1 >= 0 && j - 1 < N) { //����Ȯ��
								if (left == name) {
									sharkstate[name] = 3; //����� ������ ������
									smelltempmap[i][j - 1].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
									tempmap[i][j - 1].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
									smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
									tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
									check = 1;
								}
							}
						case 3:
							if (j + 1 >= 0 && j + 1 < N) { //����Ȯ��
								if (down == name) {
									sharkstate[name] = 4; //����� ������ ������
									smelltempmap[i][j + 1].push_back({ name,k }); //�̵��Ѱ��� ���� �Ѹ���.
									tempmap[i][j + 1].push_back(name); //�̵��� ���� ��ġ�Ѵ�.
									smelltempmap[i][j].pop_back(); //������ [0] �ۿ�������
									tempmap[i][j].pop_back();
									smelltempmap[i][j].push_back({ name, k - 1 });//��ġ�ߴ� ���� ������ ������ ����� �� ������ -1 ��Ų��.
									tempmap[i][j].push_back(0); //��ġ���� �ʴ´�. 0���ιٲٱ�
									check = 1;
								}
							}
						}
					}
				}

			}
		}
	}

	//������ ������ �͵��� ��������ߵ��ٵ�... �� ����� ������ �ƴҰ�

	eatshark();
}

int main() {
	cin >> N >> M >> k; //NxN ũ�⿡ M������ ���, ������ �� k���̵��� �������.
	int in1;
	//���� map�� �� ��ȣ�� ������ ��ġ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> in1;
			map[i][j].push_back(in1);
		}
	}

	//������ �ʱ� ����
	for (int i = 1; i <= N; i++)
		cin >> sharkstate[i]; //1�� ������ N�������� ���� ����
	//�� �Ʒ� ���� ������ ������� 1, 2, 3, 4

	//�켱����
	for (int k = 1; k <= N; k++) { //1~N�� ���
		for (int i = 0; i < N; i++) { //�� �Ʒ� ���� ������ ������ ����
			for (int j = 0; j < N; j++) { //�켱���� ����
				cin >> sharkd[k][i][j];
			}
		}
	}
	spread();

	move();

	return 0;
}