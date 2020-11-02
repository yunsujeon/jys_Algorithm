//����Ž��
//�̵� ������ ����� �� : X-1, X+1, 2*X
// BFS�̿��Ѵ�. BFS�� �ٸ� ����
#include <iostream>
#include <queue>

using namespace std;
	
int N, K, visited[100001] = { 0, };
queue<int> q;

//�⺻���� : �� visited�� �湮Ƚ���� �Է������ν� ���� x�� �����Ϸ���
//��� ���ߵǴ����� visited�� �� �����صδ°�
int bfs() {
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		//��ġ�� �����ߴٸ� ���
		if (p == K) 
			return visited[p] - 1;
		//������ ������ġ-1 �� ���� 0���� ũ�ų� ���� �湮�� ���̾������
		//���� ������ ������(��ġ��) 1 �������� ť�� �־��ش�.
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1; //���� p�� 1�̶�� 2�� �־��ִ°� 
			q.push(p - 1); //p-1���� push ���ش�
		}
		//������ ���� ��ġ�� +1�� 100000���� �۰ų� ���� �湮�� ���� �������
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		//������ ���� ��ġ�� 2�谡 0���� ũ�ų� ����, �湮������ �������
		if (2 * p <= 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);
		}
	}
}
int main() {
	cin >> N >> K;
	printf("%d", bfs());
}