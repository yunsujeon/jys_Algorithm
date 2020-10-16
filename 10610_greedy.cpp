//입출력을 한번더 생각해보게되는문제

#include <iostream>
#include <algorithm>
using namespace std;

int num[10];

//정해지지 않은 수를 반복해야 할때 string 받아서 돌리기
int main() {
	string a;
	cin >> a;
	int temp = 0;
	for (int i = 0; i < a.size(); i++) {
		num[a[i] - '0']++;
		temp += a[i] - '0'; //만약 102가 들어왔으면 3이 저장될것
	}

	//30의 배수라면
	if (temp % 3 == 0 && num[0] != 0) { //temp를 더한게 3으로나눠지고
		//0이 있으면 (30의배수이기때문에 0 꼭필요하다)
		for (int i = 9; i >= 0; i--) { //큰수부터 출력하기
			for (int j = 0; j < num[i]; j++) { //큰수의 개수만큼 출력
				cout << i;
			}
		}
	}

	//아예 30의 배수가 아니라면
	else { 
		cout << -1;
	}
	return 0;
}