/*5585번
손님이 물건을 골라서 1000엔 지폐를 지불한 경우 거슬러 줘야되는 잔돈의 최소갯수는?
지불한 돈은 1000엔미만*/
/*
#include <iostream>

using namespace std;

int main() {
	int n, result=0;
	scanf_s("%d", & n); //손님이 낸 돈 n
	n = 1000 - n; //총 거슬러줘야될 돈 n
	result += n / 500;
	n = n % 500; //500엔으로 거슬러주고 남은 거슬러줘야될 돈
	result += n / 100;
	n = n % 100;
	result += n / 50;
	n = n%50;
	result += n / 10;
	n = n % 10;
	result += n / 5;
	n = n % 5;
	result += n / 1;
	n = n % 1;
	result += n;
	printf("%d", result);
	return 0;
}
*/

/*11047번
거스름돈 줄 화폐의 단위도 입력으로 받는다 - 배열에 저장해놓을것
입력)
10 4200		가지고 있는 동전의 종류:10 만들고싶은 돈의가치:4200
1
5
10
....		돈의 종류
출력) 동전갯수의 최소값*/
/*
#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

vector<int> v;

int main() {
	int n, k, coin, result = 0;
	scanf_s("%d %d", &n, &k); //10개의 동전, k원을 만들어야됨
	for (int i = 0; i < n;i++) {
		scanf_s("%d", &coin);
		v.push_back(coin);
	}
	for (int i = v .size(); i >=0; i--) { //9~0까지 반복
		if (k > v[i]) { //k원이 현재 배열의 숫자보다 클때
			result = result + k / v[i]; //result는 동전의갯수
			k = k % v[i]; //현재 돈에서 기준돈을 나눴을 때 나머지를 k에저장
		}
	}
	result = result + k;
	printf("%d", result);
}
*/


/*11399 ATM
모든사람이 돈을 인출할 때 필요한 시간의 합이 가장 작은 경우를 구해야된다
인출하는데 걸리는 시간이 적은 순서대로 정렬한 후 시간의 합을 구하면 된다*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int n, sum = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sort(a, a + n);
	}
	for(int i=0;i<n;i++){
		sum += a[i] * (n - 1);
	}
	cout << sum << '\n';
	return 0;
}
*/


/*2217 로프 
최대중량을 구하면 된다. 모든 로프의 가용 용량을 기준을 오름차순 정렬을 한다.*/
/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < a[i] * (n - i))
			max = a[i] * (n - i);
	}
	cout << max;
	return 0;
}
*/


/*1138 한줄로 서기
사람들을 키 순서대로 세우면 되는 문제
자신보다 왼쪽에 있는 사람의 숫자를 알려준다
모든 사람에 대해서 왼쪽부터 하나씩 살펴보며 자신이 들어갈 수 있는 위치를 고르면된다.
입력)
4			사람의 수
2 1 1 0		키가 1인사람의 왼쪽에는 자기보다 키큰사람이 두명
키가 2인 사람의 왼쪽에는 자기보다 키큰사람이 한명
키가 3인 사람의 왼쪽에는 자기보다 키큰사람이 한명
키가 4인 사람의 왼쪽에는 자기보다 키큰사람이 없다.
*/

#include <iostream>

using namespace std;
int d[11];

int main() {
	int n;
	cin >> n; //사람의 수 n명
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x; //자기보다 키가 큰 사람이 왼쪽에 몇 명 있었는지 i=1:x=2 , 2:1, 3:1, 4:0 
		int count = 0;
		//사람과 위치 계속 반복하며 빈 위치에 넣어주면된다.
		for (int j = 1; j <= n; j++) { //사람이 서있는 위치
			if (count == x && d[j] == 0) {
				d[j] = i; //d[3]=1 d[2]=2 d[4]=3 d[1]=4 //1번사람은 3번위치에(두명이앞에있으니) 2번사람은 2번위치에 3번사람은 1번아니로 3번안되고 2번안되니깐 4번위치에 4번사람은 1번위치에
				break;
			}
			if (d[j] == 0)
				count++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", d[i]);
		//줄을 선 순서대로 키를 출력한다.
	}
	return 0;
}