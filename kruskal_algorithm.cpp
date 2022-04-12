/*���� ���� ������� ��� ��带 �����ϱ� ���� ����ϴ� �˰���
�� �ּҺ�����Ʈ���� ����� ���� ��ǥ�˰���
���� ���ð������� ���ηο����Ҷ� ����� �ּ�ȭ�ϰ��� �ϴ¹���
��� ���������� ������������ �����ѵڿ� ��������� �������� �׷���������
���ĵ� ������ �°� �׷����� ���Խ�Ű�� ����Ŭ�� ���������ʵ��� ��
�ձ⸸ �ϸ�Ǵ°��̹Ƿ� ����Ŭ �߻��ϸ� �ּҰ� �ƴϴ�
�̴� ����Ŭ ���̺�� �Ǻ��ϴµ� ����Ŭ���̺��� ���� �����ϴٸ�X*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�θ��带 ������
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

//�θ��带 ����
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	//�� ���ڰ� ���� �θ�� ����
	if (a < b) set[b] = a;
	else set[a] = b;
}

//���� �θ� �������� Ȯ��
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

//���� Ŭ���� ����
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	/*bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}*/
};

bool compare(Edge a, Edge b) {
	return(a.distance < b.distance);
}

//����
int main(void) {
	int n = 7; //����
	int m = 11; //������

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end(), compare);

	//�� ������ ���Ե� �׷����� ������� �����Ѵ�
	//����Ŭ ���̺� �ʱ�ȭ �����ִ°�
	int set[1000];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	//�Ÿ��� ���� 0���� �ʱ�ȭ�Ѵ�
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//������ �θ� ����Ű�� �ʴ°��, �� ����Ŭ�� �߻�������������!

		// -1 ���ִ� ���� : find�� ����Ŭ���̺��� �˻��ϸ鼭 �����θ����� Ȯ��
		// ���ڷδ� ����Ŭ ���̺��� set[]�迭�� �ε����� ���´�. �̶� set[]�迭��
		// �ε����� 0���� �����ϱ⶧���� 1�̾ƴ� 0���� �о��ֱ� ���� -1���ش�.
		if (!find(set, v[i].node[0]-1 , v[i].node[1]-1 )) {
			//�̹� ������������ �����س������� ����Ŭ�� �߻����������� �����ָ�ȴ�.
			sum += v[i].distance;
			unionParent(set, v[i].node[0]-1 , v[i].node[1]-1 );
		}
	}
	printf("%d\n", sum);
}