//메커니즘 이해안감..
//BP = 브루트 포스 = 완전탐색

#include <iostream>
#include <stdlib.h>
using namespace std;

int broken[10];
int cnt = 100; //처음 시작점은 100번
int N, M, S;

int controller(int n) {
	int result;
	if (n == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0; //몇번눌러야되는지 계속 판단해야되기때문에 들어올떄마다 초기화해준다
	while (n > 0) {
		if (broken[n % 10])
			return 0;
		n = n / 10;
		len += 1;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> S;
		broken[S] = true; //고장난거만 1
	}
	int result = abs(N - 100); //지금 보고있는 채널이 100번이므로 그냥 쌩으로 눌렀을때
	//눌러야 되는 값이 result이다.
	for (int i = 0; i <= 1000000; i++) { //0번을 눌렀을때 이동해야되는 수 ~1000000을 눌렀을때 이동해야되는수
		//전부 탐색하는 것이다.
		int c = i;
		int len = controller(c); //숫자를 누를 때 눌러야되는 수. 만약 고장났다면 return 0
		if (len > 0) { //len이있을때만
			int press = abs(c - N); // 현재채널(0~100만)-가야되는수 빼서 직접 눌러야되는 수 체크
			if (result > press + len) // press+len한게 result보다 작으면
				result = press + len; // result를 press+len으로 초기화해준다
		} 
	}

	cout << result << endl;

	return 0;
}