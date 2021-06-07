/*
한칸위에 있는 수 신경 안썼다
for문을 돌며 그 순간 가장 큰 수를 고르려고 하니
시간초과가 날것같다

1500*1500(한번 도는데 걸리는시간) * 1500(횟수)
33억7500만회 => 메모리초과 (1초-1억 본다)
메모리초과

다른방법 생각
표 생각안하고 받는 입력을 모두 pq에 넣자
기본 내림차순이다. => pq도 정렬을 해야해서 
메모리초과

어떻게할까..
들어갈때마다 sort 하지말고 다 넣은다음에 한번에 sort해보자
메모리초과

뭘 더해볼까
최소힙을 가지는 우큐를 만들어서 그것들끼리에서만 우큐를 돌도록

 */

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector <int> v;

bool compare(int a, int  b) {
	return a > b;
}

void solution() {
	int res;
	sort(v.begin(), v.end(),compare);
	//sort(v.begin(), v.end(), greater<int>());
	cout << v[N - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int n;
	for (int i = 0; i < N*N; i++) {
		cin >> n;
		v.push_back(n);
	}

	solution();

	return 0;
}
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> N;
	int n;
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (pq.size() < N) pq.push(n); //사이즈보다 작으면 그냥 넣어
			else if (n > pq.top()) { //젤큰 수보다 크면 교체해
				pq.push(n); //push
				pq.pop(); //pop
			}
			else continue;
		}
	}
	
	cout << pq.top() << '\n';
	//원래는 내림차순이여서 젤 큰 순인데 현재는 top이 오름차순

	return 0;
}