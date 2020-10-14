//E는 15의 배수이고 S는 28의 배수 M은 19의 배수이므로 이 모든 조건을 만족해야됨
//해당조건이 만족되면 break 해서 출력하면됨
#include <iostream>
using namespace std;

int E, S, M;

int year() {
	int result;
	int year = 1; //아무것도 안해도 1임
	while (1) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			result = year;
			break;
		}
		year++;
	}
	return result;
}

int main() {
	cin >> E >> S >> M;
	year();
	cout << year() << endl;
	return 0;
}