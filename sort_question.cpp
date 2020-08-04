//심화정렬문제 풀이

/*문자열정렬 알파벳소문자로 이루어진 n개의 단어가 들어오면
길이가 짧은것부터, 길이가 같으면 사전순으로 정렬하시오
단어의 갯수는 20000개 이하, 문자열의길이 <= 50*/

/*
#include<iostream>
#include<algorithm>

using namespace std;
string a[20000];
int n;

bool compare(string a, string b) {
	if (a.length() < b.length()) //길이가짧은순으로 정렬
		return 1;
	else if (a.length() > b.length())
		return 0;
	else
		return a < b; //길이가 같으면 사전순으로 정렬
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1])continue;
		cout << a[i] << '\n';
	}
	return 0;
}
*/

/*좀더 복잡한 정렬 : 길이가 다르면 짧은것이 먼저온다.
길이가 같다면 모든자리수의 합이 작은게 먼저온다
비교할수없다면 사전순으로 비교한다. 숫자가 알파벳보다 작다
===> 기타의 개수N이 주어진다. N<=1000 시리얼번호 최대길이는 50
대문자 또는 숫자로만 이루어져있다.*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector <string> v;

int getSum(string a) {
	int n = a.length(), sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) { //string 중 숫자만 구분해서 더한다.
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	if (a.length < b.length) //첫번째 고려사항 길이가 짧은것이 먼저온다.
		return 1; //이게 뜻하는게 곧 a<b인지??
	else { //두번째 고려사항 길이가 같다면 합이 작은게 먼저온다.
		int aSum = getSum(a);
		int bSum = getSum(b);
		if (aSum != bSum) { //합이 다르다면 합이 작은게 먼저오도록
			return aSum < bSum;
		}
		else {
			return a < b; //비교할수없다면 사전순으로정렬하게끔
		}
	}
}
int main(void) {
	cin >> n; //몇개의 입력을 줄건지
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input); //v배열에 하나씩 밀어넣는다.
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
	return 0;
}
*/

/*N개의 수를 오름차순으로 정렬하는 프로그램을 작성하라
수의 개수는 10,000,000 이하이다. 수는 10,000 보다 작거나 같은 자연수
여기서 N*logN 도 1억 이하이기 힘들기 때문에 무조건 O(N)을 요구하는 문제이다.
매우 빠르게 정렬하기 : 시간복잡도 O(N)을 요구하는 문제 - 계수정렬알고리즘 사용*/

#include <iostream>

using namespace std;
int n,m;
int a[10001]; //모든 수마다 자리가 있어야 된다.

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		a[m]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++) {
				printf("%d ", i);
			}
		}
	}

}