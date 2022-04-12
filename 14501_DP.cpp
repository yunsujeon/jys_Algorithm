#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;

int N;
int T, P;
int DP[17] = { 0, }; //DP�� �� ���ں� �� �ִ� �� �� �ִ� P

//vector <pair<int, int>> v;
// ����� ���� ���� ��� ���� ������ �ȴ�.
/*
void solution() {
	// �� ���ں��� �ִ�� ���� �� �ִ� pay�� ����� �����س���. ���� ������Ʈ
	// �켱 DP�� �����Ϸ��� ���۰��� ��������� �Ѵ�.
	for (int i = 0; i < N; i++) {
		int day = v[i].first;
		int pay = v[i].second;
		int targetday = i + day;
		if (targetday <= N && pay>=DP[targetday]) {
			DP[targetday] = pay; //ū�ɷΰ���
		}
	}
	//���� �� �ϼ����� ���ư��� �ִ밪�� �������ֱ⸸ �ϸ�ȴ�.
	for (int i = 0; i < N; i++) {
		int hap = 0;
		int j = i;
		while(j<N){ // �� ������ �������� ���鼭 ����
			int day = v[j].first;
			int pay = v[j].second;
			if (j + day <= N) { // ���ڸ� �ʰ����� �ʴ´ٸ�. �� 0+7<=7 �� ����
				hap += pay; //hap�� pay�� ���Ѵ�.
				if (day == 1) { // �켱 ���ĭ������ 1�̸� DP�� hap�� ���������������
					DP[j + 1] = hap;
				}
				else {
					for (int k = j; k < j - 1 + day; k++) {
						DP[k + 1] = hap-pay;//1���� �ƴ϶�� �ٷ� ���� �� ����.
					}
				}
			}
			else {
				DP[j + 1] = hap; //DP�� �ִ밪�� �־��ش�.
			}
			j++;
		}
	}

}*/

// but DP�� �̿��غ���.
// ������ ���� ���� �ƴ϶� �ٴ��� ���� �����ؾ� �ִ밡 �Ǵ� ��� ����

pair<int, int> map[1002];

void solution(int now, int time, int value) {
	for (int i = now + time; i <= N; i++) { //DP�� ã�ư� ���� �����Ѵ�. now + time���� ����
		if (i + map[i].first <= N + 1) { //������ ���� �Ѿ�� �ʴ´ٸ�
			DP[i] = max(DP[i], map[i].second + value); //ã�ư� ���� DP�� �װ��� P���� ���� P�� �� vs �װ��� DP��
			solution(i, map[i].first, DP[i]); // ã�ư� �������� �� solution�� �����ش�.
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		map[i].first = T;
		map[i].second = P;
	}

	for (int i = 1; i <= N; i++) {
		if (i + map[i].first <= N + 1) { //������ ���� �Ѿ�� �ʴ´ٸ�
			DP[i] = max(DP[i], map[i].second); //�ش� DP�� ���� ���� �������ش�.
		}
		solution(i, map[i].first, map[i].second); //���� i�� T, P�� �������ش�.
	}

	sort(DP, DP + N + 1, greater<int>());
	cout << DP[0] << '\n';

	return 0;
}