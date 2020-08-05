/*스택: 입구와 출구가 같다.
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}