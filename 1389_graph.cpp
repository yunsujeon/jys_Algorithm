//�ɺ������� ���� ���� ���� ���
//��� ����� ������ ���� �� ���� ���� ���� ���

#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
int fnd[101][101] = { 0, };
int d[101][101] = { 0, }; //�Ÿ��迭
int result=INF;

int main() {
	int A, B, result_index;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		fnd[A][B] = 1;
		fnd[B][A] = 1;
	}

	// d �ʱ�ȭ
	for (int i = 1; i <= N; i++) { //��� ��
		for (int j = 1; j <= N; j++) {
			if (fnd[i][j] != 0) { //������ �ִٸ�
				d[i][j] = fnd[i][j]; //���� �־��ش�.
			}
			else { //������ ���ٸ�
				d[i][j] = INF; //���Ѵ밪
			}
		}
	}
	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) { //k�� ���İ��°�츦 �����ش�.
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int result_bar[101] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			else {
				result_bar[i] += d[i][j];
			}
		}
		if (result_bar[i] < result) {
			result = result_bar[i];
			result_index = i;
		}
	}

	cout << result_index << '\n';

	return 0;
}