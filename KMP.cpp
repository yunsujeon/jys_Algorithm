//잘 이해안가는 알고리즘 KMP
//https://bowbowbow.tistory.com/6


/*KMP알고리즘은 대표적인 문자열(String)매칭 알고리즘
특정한 글이 있을때 그 글안에서 하나의 문자열을 찾는 알고리즘
*/

/*
//일반 문자열 매칭 알고리즘 
//BCDEF가 있고 그중 DE를 찾을거면
//자리를 하나씩 옮기며 비교하면서 매칭한다.
//O(N*M)

#include <iostream>

using namespace std;

int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	for (int i = 0; i <= parentSize - patternSize; i++) { //그 시작점까지만 찾으면됨.
		bool finded = true; //finded를 true로
		for (int j = 0; j < patternSize; j++) { //패턴사이즈 내에서 돌면서 각각글자가맞는지
			if (parent[i + j] != pattern[j]) { //맞지않으면
				finded = false; //finded를 false로
				break; //for문 빠져나온다.
			}
		}
		if (finded) { //true면
			return i; //1반환
		}
	}
	return -1; //안맞으면 -1반환
}

int main() {
	string parent = "Hello World";
	string pattern = "llo W"; //llo W
	int result = findString(parent, pattern);
	if (result == -1) {
		printf("찾을 수 없습니다.");
	}
	else {
		printf("%d번째에서 찾았습니다.", result + 1);
	}
	return 0;
}
*/

/*KMP (Knuth-Morris-Pratt) 로 모든 경우를 다 비교하지 않아도 부분 문자열을 찾을 수 있다.
접두사와 접미사의 개념을 활용하여 반복되는 연산을 얼마나 줄일수있는지 판별
우리가 구해야 할 것은 접두사와 접미사가 일치하는 최대길이
abacaab 에서 접두사=접미사=ab 이다.
abacaaba 에서 접두사=접미사=aba이다
접두사와 접미사가 일치하는 경우에 한해서는 점프를 수행할 수 있다.
최대일치길이를 구하자
비교를 하다가 서로 다른 문자가 발견되면 일치하는 접두사 크기에 한해서 부분 문자열의 인덱스를 이동
*/
//즉 매칭에 실패했을때 접두사 접미사 기준으로 얼마나 점프할수 있을지를 알려주는것
//영상에서 00101123은 접두사 접미사 최대길이를 의미한다.
//실패했을때 현재 접두사와 접미사가 같다면 다음 접두사는 지금의 접미사 위치로 뛸수있다!!

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0); //크기 8이고 0으로 초기화
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern); //테이블생성 여기서는 00101123
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] = pattern[j]) {
			if (j == patternSize - 1) {
				printf("%d번째에서 찾았습니다.\n", i - patternSize + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}


int main() {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);
	return 0;
}