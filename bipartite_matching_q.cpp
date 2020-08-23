#define _CRT_SECURE_NO_WARNINGS
/*이분매칭 기초문제풀이
이분매칭은 대표적인 네트워크 알고리즘이다.
*/

/*2188번 축사배정
DFS를 이용하여 계속해서 매칭이 가능한 경우를 재귀적으로 모두 매칭시켜 문제해결
축사를 M개의 칸으로 구분하고 한칸에는 한마리의 소만 들어간다.
소는 자신이 희망하는 몇개의 축사 외에는 들어가기를 거부한다.
예시 입력 )
5 5			5마리의 소, 5개의 축사
2 2 5		1번소는 2개의 축사에 들어갈수있다. 2번과 5번
3 2 3 4		2번소는 3개의 축사에 들어갈수있다. 2 3 4 번
2 1 5
3 1 2 5
1 2
출력 : 축사에 들어갈 수 있는 소의 최댓값을 출력한다.
*/
/*
#include <iostream>
#include <vector>
#define MAX 201 //소의 수와 축사의 수는 최대 200개

using namespace std;

int m, n, s;
vector<int> a[MAX];
bool c[MAX];
int d[MAX];

bool dfs(int x) { //깊이우선탐색
	for (int i = 0; i < a[x].size(); i++) { //연결된 노드에 대하여 탐색한다.
		int t = a[x][i];
		if (c[t]) //이미 true라면 볼필요없이 다음 연결노드로 간다.
			continue;
		c[t] = true;
		//비어있거나 점유노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t])) { //재귀
			d[t] = x;
			return true; //매칭 성공시
		}
	}
	return false; //매칭 실패시
}

int main() {
	//scanf_s("%d %d", &m, &n);
	cin >> m >> n;
	for (int i = 0; i < n; i++) { //축사의 수만큼 반복한다.
		//scanf_s("%d", &s); //소가 들어갈 수 있는 축사의 수
		cin >> s;
		for (int j = 0; j < s; j++) { //소가 들어갈 수 있는 축사의 수 만큼 입력을 받아야된다.
			int t;
			//scanf_s("%d", &t);
			cin >> t;
			a[i].push_back(t); //그 축사의 번호에 t를 연결해준다
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false); //dfs 전에 항상 false로 초기화시켜준다.
		if (dfs(i)) //1부터 축사의 수만큼 dfs를 실행한게 1을 반환하면 (소가 축사에 들어가면)
			count++; //count를 증가시킨다.
	}
	printf("%d\n", count);
	return 0;
}
*/

/*11375번 열혈강호
회사에 직원이 n명 해야할 일이 m명
1 ~ n,m ~1000
각 직원은 한개의 일만 할 수 있고 담당하는 사람은 한명이여야한다.
각각의 직원이 할 수 있는 일의 목록이 주어졌을때, m개의 일 중에서 최대 
몇개를 할 수 있는지 구하는 프로그램을 작성해라.
입력)
5 5			직원의 수N 일의 개수M
2 1 2		1번직원은 2가지의 일 할수있고 1번과 2번일을 할수있다.
1 1 
2 2 3
3 3 4 5
1 1
*/
/*
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int m, n,s;
vector<int> a[MAX];
int c[MAX];
int d[MAX];

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		if (c[t])
			continue;
		c[t] = true;
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &s);
		for (int j = 0; j < s; j++) {
			int t;
			scanf_s("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false); //방문체크를 위함
		if (dfs(i))
			count++;
	}
	printf("%d", count);
	return 0;
}
*/

/*열혈강호2-각각의 직원이 두개의 일을 할수있다. - DFS두번씩 수행한다.
입력)
5 5			직원수 5명 일의개수 5개
2 1 2		첫번째직원은 2가지의 일을 할수있고 1번과 2번 일 할수있다.
2 1 2		두번째직원은 2가지의 일을 할수있고 1번과 2번 일 할수있다.
2 1 2
2 4 5
0
*/
/*
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
int c[MAX];
int n, m;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y])
			continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) { //사람 수만큼 반복하며 일의 갯수를 받는다.
		int k; 
		scanf_s("%d", &k); //한사람이 처리할수있는 일의 갯수
		for (int j = 1; j <= k; j++) {
			int y;
			scanf_s("%d", &y);
			a[i].push_back(y);
		}
	}
	int count = 0;
	for (int k = 0; k < 2; k++) { // 두개를 처리할수있으므로 dfs를 두번 돌게하면된다
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i))
				count++;
		}
	}
	printf("%d", count);
	return 0;
}
*/

/*열혈강호3 - 직원은 한개의 일만할수있고 일의 담당은 한명이여야 하나
N명 중에서 K명은 일을 최대 2개 할 수 있다.
목록이 주어졌을때 최대 몇 개의 일을 처리할 수 있는 지 구하시오
입력)
5 5 1		5명의 직원 5개의 일 , 일을 2개할 수 있는 직원의 수 K
3 1 2 3		1번 직원이 할수있는 일은 3개 1 2 3
3 1 2 3
1 5
1 5
1 5
*/
/*
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int m, n, k, s;
vector<int> a[MAX];
int c[MAX];
int d[MAX];

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y])
			continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf_s("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &s);
		for (int j = 1; j <= s; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))
			count++;
	}
	int extra = 0; //2번씩 작업할수 있는 사람을 추가로 dfs 돌려준다
	for (int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))
			extra++;
	}
	printf("%d", count + extra);
	return 0;
}
*/

/*상어의 저녁식사
저녁식사로 서로를 먹는다. 자신들의 크기, 속도, 지능 알고있음
크기, 속도, 지능이 어떤 상어보다 크다면 잡아먹을 수 있다.
먹을 수 있는 최대상어의 마리수는 두마리
능력치가 모두 같다면 A가B를 B가A를 먹을수는 있지만 서로먹진못한다
입력)
5			다섯마리의 수 (50마리이하)
4 5 5		1번상어의 크기:4 속도:5 지능:5 (2,000,000,000이하)
10 10 8
5 7 10
8 7 7
8 10 3
출력 : 살아남을 수 있는 상어 수의 최솟값(최대한 다 먹어)
2
->단순히 두번씩 매칭을 수행해 주면 되는 간단한 문제
그러나 능력 수치를 비교하는 부분이 필요하다.
*/

#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> a[MAX];
int c[MAX];
int d[MAX];
int n;
int stat[MAX][3]; // 스탯을 저장할 배열이 필요하다.

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y])
			continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf_s("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]); //스탯을 입력해준다.
	}
	for (int i = 1; i <= n - 1; i++) { //1 2 3 4
		for (int j = i + 1; j <= n; j++) { // 2 3 4 5
			if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) { //현재와 다음 상어의 스탯이 다 동일하면
				a[i].push_back(j); //i가 j 잡아먹은거 현재 상어 i의 번호에 다음상어 j를 연결해준다.
			}
			//i와 j 관계는 이전 문제들로 생각해보면 
			//i가 j 일을할 수있다. 의 관계로 생각하면 된다. 아직 해결한건 아님. 잡아먹은거 아직아님
			else if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]){
			a[i].push_back(j); //i가 j잡아먹은거
			}
			else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]){
			a[j].push_back(i); //j가 i잡아먹은거
			}
		}
	}
	int count = 0;
	for (int k = 0; k < 2; k++) { //dfs를 두번돌리는 이유는? = 먹을수있는 최대 상어의 마릿수는 두마리
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i))
				count++; //죽는 상어 수
		}
	}
	printf("%d\n", n - count); //전체상어에서 죽는 상어 빼면 살아남은 상어수
	return 0;
}
