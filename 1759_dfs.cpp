//1759 암호만들기
//백트래킹을 이용한방법 이해 필수 dfs의 이해 재귀호출
//자음모음 조건 확인

#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char word[16];

void backtracking(int position, string s, int mo, int ja) {
	int length = s.size();
	if (length == l) {
		if (mo >= 1 && ja >= 2) {
			cout << s << endl;
			return;
		}
	}
	else {
		for (int i = position; i < c; i++) {
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
				backtracking(i + 1, s + word[i], mo + 1, ja);
			}
			else
				backtracking(i + 1, s + word[i], mo, ja + 1);
		}
		return;
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> word[i];
	}
	sort(word, word + c);
	backtracking(0, "", 0, 0);
}
