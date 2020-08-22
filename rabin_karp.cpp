/* 특이한 문자열 매칭 알고리즘이다.
해시기법을 사용한다. (해시:긴 데이터를 그것을 상징하는 짧은 데이터로 바꾸어주는 기법
예를들어 abacaaba의 해시값은 97*2^7+98*2^6+....=24833이다.
각 문자의 아스키코드값에 2의 제곱수를 차례대로 곱해서 더해준 것.
서로 다른 문자열이라면 해시값이 다르게 된다.
물론 충돌하는경우도 있는데 이때는 포인터를 이용해 연결자료구조를 이용해 해결한다.
*/

#include <iostream>
#include <string>

using namespace std;

void hashs(string parent, string pattern) {
	int parentHash=0, patternHash=0, power = 1;
	int parentSize = parent.size();
	int patternSize = pattern.size();
	for (int i = 0; i <= parentSize - patternSize; i++) {
		//처음 해쉬값 생성
		if (i == 0) {
			for (int j = 0; j < patternSize;j++) {
				//그냥 문자에다 곱하는것 = 즉 아스키코드값에 곱하는 것
				parentHash += parent[patternSize - 1 - j] * power;
				//7 6 5 4 3 2 1 0
				//7번째 문자에 * power(1) + 6번째문자에 *power(2)...
				patternHash += pattern[patternSize - 1 - j] * power;
				//패턴 문자열의 사이즈보다 j가 작다면 2씩 곱해줘라
				if (j < patternSize - 1) {
					power *= 2;
				}
			}
		}
		//이미 생성되었다면 parentHash만 바꿔주면된다.
		//긴 글 해시값 = 2*(긴글해시값-가장앞에있는 문자의 수치)+새롭게 들어온 문자의 수치
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}
		//해시가 일치한다면 find
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				printf("%d번째에서 발견했습니다.\n", i + 1);
			}
		}
	}
}



int main() {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	hashs(parent, pattern);
	return 0;
}