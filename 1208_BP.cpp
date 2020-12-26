//1182에서 업그레이드 된 문제이다. 시간제한 2->1초 N의 갯수 20->40

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 40;
int N, S, half;
int basearr[MAX];
vector <int> leftarr;
vector <int> rightarr;
long long int c = 0, c1, c2;
/*연속된 수열이 아니기 때문에 부분집합 2^N 즉 최대 2^40까지 가능 => 시간초과
/해결방법으로는 N을 2로 나눈 후 두 경우로 나누어 해결해야한다. MITM 이라고 한다.
1. N개의 수를 N/2짜리 배열과 N/2짜리 배열 두개로 나누어 담는다.
2. 각각의 배열에 담긴 수의 부분집합의 합을 모두 구하여 새로운 배열 N1 N2에 담는다.
3. N1의 인덱스 하나 N2의 인덱스 하나를 합한 값을 정답S와 비교하여 체크한다
*/

void dfs(int index, int end, int sum, int isleft) {
	if (index == end) {
		if (isleft) 
			leftarr.push_back(sum);	
		else
			rightarr.push_back(sum);
		return;
	}
	dfs(index + 1, end, sum, isleft); //이 수는 더하지 않고 다음수로 넘어간다.
	dfs(index + 1, end, sum + basearr[index], isleft); //더하고 다음수로 넘어간다.
	//즉 모든경우 탐색하는것. 연속된 수열이 아니기때문에 1234 이렇게있으면 1 4 도 탐색가능해야된다.
}

//핵심알고리즘
void solve() {
	for (int s1 = 0, s2 = 0; s1 < leftarr.size() && s2 < rightarr.size();) {
		if (leftarr[s1] + rightarr[s2] == S) { //부분수열의 합을 합했을때 답이 나온다면
			c1 = c2 = 0;
			for (int t = leftarr[s1]; s1 < leftarr.size() && t == leftarr[s1]; s1++, c1++);
			for (int t = rightarr[s2]; s2 < rightarr.size() && t == rightarr[s2]; s2++, c2++);
			c += c1 * c2;
		}
		else if (leftarr[s1] + rightarr[s2] < S)
			s1++;
		else
			s2++;
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> basearr[i];
	}
	dfs(0, N / 2, 0, 1);
	dfs(N / 2, N, 0, 0);

	sort(leftarr.begin(), leftarr.end());
	sort(rightarr.begin(), rightarr.end(), greater<int>()); //내림차순정렬

	solve();
	
	if (S == 0)
		cout << c - 1;
	else
		cout << c;

	return 0;
}