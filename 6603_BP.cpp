//꼭 6개의 숫자를 골라야한다. 주어진 수 중에서.

#define MAX 49
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int k, input[MAX];
	cin >> k;
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> input[i];
		}
		//next permutation 으로 모든 순열 구해보기?
		//오름차순으로 입력이 돼있긴하다.


		memset(input, 0, sizeof(input));
		cin >> k;
	}
	return 0;
}