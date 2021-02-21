#define MAX 2000000
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, m, n;
int A[1000], B[1000];
vector<long> vA,vB;
long cnt = 0;

long sol() {
	long poa = 0, pob = 0;//시작포인터 지정
	while (!(poa == vA.size() || pob == vB.size())) {
		if (vA[poa] + vB[pob] < T) {
			poa++;
		}
		else if (vA[poa] + vB[pob] == T) {
			long cntA = poa, cntB = pob;
			long ha = poa, hb = pob;
			while (vA[cntA] == vA[poa]) {
				cntA++;
				if (cntA==vA.size())
					break;
			}
			while (vB[cntB] == vB[pob]) {
				cntB++;
				if (cntB==vB.size())
					break;
			}
			poa = cntA;
			pob = cntB;
			cnt += ((poa - ha) * (pob - hb));
		}
		else {
			pob++;
		}
	}
	return cnt;
}

int main() {
	cin >> T >> m;
	int input;
	for (int i = 0; i < m; i++) { //정수갯수
		cin >> A[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	//A로 만들 수 있는 부배열의합을 모두 구해서 vector에 pushback
	//문제이해가 중요 처음엔 연속적이지 않다고 생각했으나 A[i]...A[j]합이 부분합이란걸알게됨
	for (int i = 0; i < m; i++) {
		int num = A[i];
		vA.push_back(num);
		for (int j = i + 1; j < m; j++) {
			num += A[j];
			vA.push_back(num);
		}
	}

	for (int i = 0; i < n; i++) {
		int num = B[i];
		vB.push_back(num);
		for (int j = i + 1; j < n; j++) {
			num += B[j];
			vB.push_back(num);
		}
	}

	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end(), greater<int>()); //내림차순으로 정렬한다.
	//pq에서는 greater 가 오름차순

	long res = sol(); //이걸 long 으로 선언안한게 72%에서 끊긴이유
	cout << res << endl;
	return 0;
}