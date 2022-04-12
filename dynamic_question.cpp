//Ÿ�Ϲ��� : ��ȭ���� �� �����ߵȴ�. ������ ���� ������ �� �����ؼ� �ļ����

/*
11726�� 2*nŸ�ϸ�����
2*n ũ���� ���簢���� 1*2, 2*1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷� �ۼ�
���� �������� ���� Ÿ���� �������� �����غ������� ������ ���� ���� �ΰ����̴�.
1*2 (���������� N-1��) or 2*1 2*1 ��ġ (���������� N-2��)
*/
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 1) return 1; 
	if (x == 2) return 2;
	if (d[x] != 0) return d[x]; //d[x]�� 0�̵ɶ����� dp�ݺ�
	return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}

*/

//2*n ���簢���� 1*2 2*1 2*2 Ÿ�Ϸ� ä��� ����� �� ���ϴ� ���α׷� �ۼ�
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3; //3���� ����� ��
	if (d[x] != 0) return d[x]; //d[x]�� 0�̵ɶ����� dp�ݺ�
	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007; //N-2���� ���� ��Ȳ�� �ΰ�������
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/

//3*n ũ���� ���� 2*1 1*2 ũ���� Ÿ�Ϸ� ä��� ����� ����?
/*
#include <iostream>
using namespace std;
int d[1001];

int dp(int x) {
	if (x == 0) return 1; //��ä��°��
	if (x == 1) return 0;
	if (x == 2) return 3; //3���� ����� ��
	if (d[x] != 0) return d[x]; //d[x]�� 0�̵ɶ����� dp�ݺ�
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) { //4���϶����� ¦�������� ��찡 �ΰ����� ������
		if (i % 2 == 0) //¦�����϶�
			result += 2 * dp(x - i); //�ΰ�����쾿 �߰��� �ٿ��ش�.
	}
	return d[x] = result;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/

//2*nũ���� ���� 2*1 1*2 1*1 Ÿ�Ϸ� ä��� ����� ���� ���غ���
/*
#include <iostream>
using namespace std;
int d[1000001]; 

int dp(int x) {
	if (x == 0) return 1; //��ä��°��
	if (x == 1) return 2;
	if (x == 2) return 7; //3���� ����� ��
	if (d[x] != 0) return d[x]; //d[x]�� 0�̵ɶ����� dp�ݺ�
	int result = 3 * dp(x - 2) + 2 * dp(x - 1);
	for (int i = 3; i <= x; i++) { //4���϶����� �ϳ��� �ö󰥶����� ��찡 �ΰ����� ������
		result += 2 * dp(x - i); //�ΰ�����쾿 �߰��� �ٿ��ش�.
	}
	return d[x] = result;
}

int main() {
	int x;
	cin >> x;
	printf("%d", dp(x));
}
*/
//������ �ð����⵵�� O(N^2) �� �ǹǷ� �鸸�� ���ؼ��� �ð��ʰ��� ���Եȴ�.
//���� 2���� ���̳��� ���α׷��� ����� ����ؾߵȴ�.
//2���� dp�� �����ν� ���� ����� ���� ���ְ� �Ϸ� �Ŀ� �����ش�. 
#include <iostream>
using namespace std;

long long int d[1000001][2];

long long int dp(int x) {
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]); //[i][1]�� ���Ŵ� ���ܸ� ���� ������ֱ����ؼ�
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]); //�Ϸ�� ��
	}
	return d[x][0];
}

int main() {
	int x;
	cin >> x;
	printf("%lld", dp(x));
}