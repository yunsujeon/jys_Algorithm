#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dq[51][51] = { 0, };
vector <int> temp;
int N, M, T;
int x, d, k;

void rotate(int x,int d,int k) {
	//x의 배수원판, 방향d로, k번
	int i = 0;
	i++;
	while (i <= N) {
		if (i % x == 0) {
			temp.clear();
			if (d == 0) { //시계방향이라면
				int end = M; //원소갯수리턴
				int idx = end - k;
				for (int j = idx; j < end; j++) { //갯수만큼 옮겨담기
					temp.push_back(dq[i][j]);
				}
				for (int j = idx-1; j >= 0; j--) { //나머지 값들을 뒤로 미루기
					dq[i][j + k] = dq[i][j];
				}
				for (int j = 0; j < k; j++) { //앞으로 갖다붙힌다
					dq[i][j] = temp[j];
				}
			}
			else { //반시계방향이라면
				int end = k;
				int idx = 0;
				for (int j = idx; j < end; j++) { //갯수만큼 옮겨담기
					temp.push_back(dq[i][j]);
				}
				for (int j = k; j < M; j++) { //나머지 값들을 앞으로 가져오기
					dq[i][j -k] = dq[i][j];
				}
				for (int j = M-k; j < M; j++) { //뒤에 갖다붙힌다
					dq[i][j] = temp[j-M+k];
				}
			}
		}
		i++;
	}
}

void sol(int x, int d, int k) {
	//회전한다
	rotate(x,d,k);
	//원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
	//연속으로 인접한 것도 지우기 위해 복사배열을 만들어 준다.
	int copy[51][51] = { 0, };
	memcpy(copy, dq, sizeof(dq));
	int flag = 0; //바뀌면 숫자가 있는것
	int sum = 0;
	int num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			sum += dq[i][j];
			if (dq[i][j] != 0) {
				num++;
				int v = dq[i][j];
				if (dq[i][(j + 1) % M] == v) { //오른쪽 살피기 = 같다면
					copy[i][(j + 1) % M] = 0;
					copy[i][j] = 0;
					flag = 1;//맞는 숫자가 하나이상 있다
				}
				if (j == 0) { //왼쪽살피기
					if (dq[i][M - 1] == v) {
						copy[i][M-1] = 0;
						copy[i][j] = 0;
						flag = 1;//맞는 숫자가 하나이상 있다
					}
				}
				else {
					if (dq[i][j - 1] == v) {
						copy[i][j-1] = 0;
						copy[i][j] = 0;
						flag = 1;//맞는 숫자가 하나이상 있다
					}
				}
				if(i!=1) {
					if (dq[i - 1][j] == v) {
						copy[i-1][j] = 0;
						copy[i][j] = 0;
						flag = 1;//맞는 숫자가 하나이상 있다
					}
				}
				if (i!=N) {//하위 원판살피기
					if (dq[i + 1][j] == v) {
						copy[i + 1][j] = 0;
						copy[i][j] = 0;
						flag = 1;//맞는 숫자가 하나이상 있다
					}
				}
			}
		}
	}
	memcpy(dq, copy, sizeof(copy));
	if (flag == 0) {
		float avr = float(sum)/float(num);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				if (dq[i][j] != 0) {
					if (dq[i][j] < avr) dq[i][j]++;
					else if (dq[i][j] > avr) dq[i][j]--;
				}
			}
		}
	}
}

int result() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			res += dq[i][j];
		}
	}
	return res;
}

int main() {
	cin >> N >> M >> T;
	int val;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> val;
			dq[i][j] = val;
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		sol(x, d, k);
	}
	cout << result() << '\n';
	return 0;
}
