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

/*
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
*/

/* 1541
잃어버린 괄호
양수와 + - 괄호를 가지고 길이가 최대 50인 식을 만들고 괄호를 모두 지웠다.
이후 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
입력)
55-50+40
출력)
-35
마이너스뒤부터는 괄호연다(마이너스로더한다) 다시 마이너스가 나오면그 앞에서닫아준다.
*/
/*
#include <iostream>
#include <string>

using namespace std;

string a;

int main() {
	cin >> a;
	int result = 0;
	string temp = "";
	bool minus = false;

	for (int i = 0; i <= a.size(); i++) {
		//숫자를 먼저 만들고 그 숫자의 부호를 나중에 만들어서 더하거나 빼준다.
		cout << a[i];
		if (a[i] == '+' || a[i] == '-' || a[i] == '\0') { //부호가있을때만 걸린다.
			if (minus == true) //마이너스가 한번 true로 셋되면 계속 마이너스로 더한다
				result += -stoi(temp); //문자열을 숫자로 변환하는 함수 atoi도 쓸수있음
			else
				result += stoi(temp);
			temp = ""; //temp를 비워준다.
			if (a[i] == '-')
				minus = true;
			continue;
		}
		temp += a[i];
	}
	printf("%d", result);
	return 0;
}
*/

/*10610번
양수 n에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
n은 최대 10^5개의 숫자로 구성되어있다.
입력)
102
출력) - 1, 0, 2 로 만들수 있는 30의 최대 배수
210
정수론의 기초개념 : 각 숫자 자릿수의 합이 3의 배수라면 전체 숫자는 항상 3의 배수가 된다.
각 자리수 합이 3이 되는지 확인하고 0이 있어야 30의 배수가 될것이다.
큰숫자대로 출력하면될것
*/
/*
#include <iostream>
using namespace std;
int number[10];
int main() {
	string a; 
	cin >> a; //숫자입력받는다.
	int temp = 0;
	for (int i = 0; i < a.size(); i++) { //string 크기만큼
		number[a[i] - '0']++; //0~9 배열에 그 숫자가 있으면 ++해준다.
		temp = temp + (a[i] - '0'); //3의 배수인지 판별하기 위해 더해준다.
	}
	if (temp % 3 == 0 && number[0] != 0) { //3의 배수이고 0이 있을 경우에
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < number[i]; j++) {
				cout << i;
			}
		}
	}
	else {
		cout << -1;
	}
	return 0;
}
*/

/*신입사원
서류심사와 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는자만 선발한다는 원칙
신규채용에서 선발할 수 있는 신입사원의 최대인원수는?
입력)
2		2개의 테스트케이스
5		첫번째 테스트케이스의 지원자의 수
3 2		1번지원자의 서류심사성적, 면접 성적
1 4		2번...
4 1
2 3
5 5
7		두번째 테스트케이스의 지원자의 수
3 6		1번 지원자의 서류심사성적, 면접 성적
7 3
....
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;

int main() {
	int a, b, c, d;
	cin >> a; //테스트케이스
	for (int i = 0; i < a; i++) {
		v.clear(); //사용한 vector 배열을 다 지워준다.
		int min = 100001, result = 0;
		cin >> b;
		for (int j = 0; j < b; j++) {//테스트케이스의 사람수
			cin >> c >> d;//서류심사성적, 면접성적
			v.push_back(make_pair(c, d));
		}
		sort(v.begin(), v.end()); //오름차순으로 정렬한다. first 원소를 기준으로 정렬
		for (int i = 0; i < b; i++) { //사람 수만큼 반복하면서 min값을 갱신한다.
			//여기서 이미 first조건은 순위대로 정렬되어 있으므로 여기서 min을 갱신해야만 붙을것이다.
			//갱신하지 못한다면 first 순위도 밀리고 second 순위도 밀리는것.
			if (min > v[i].second) {
				min = v[i].second;
				result++;
			}
		}
		printf("%d", result);
	}
	return 0;
}
