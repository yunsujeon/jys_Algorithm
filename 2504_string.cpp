#include <iostream>
#include <string>
#include <stack>

using namespace std;

//계산결과를 다시 stack에 넣는다는 생각을 못함 vector 쓰려했음

string gual;
stack <string> st;
int res=1;
int sum_;

void solution() {
	int cnt = gual.size();
	string tmp;
	for (int i = 0; i < cnt; i++) {
		tmp = gual.at(i); //gual 을 하나씩 본다.
		if (tmp == "(" || tmp == "[") { //들어오는 괄호면	
			st.push(tmp); //stack 에 넣는다.
		}
		else { //나가는 괄호
			sum_ = 1; //0이면 곱할수가 없으니 초기값 1
			
			// 나가는 괄호인데 top이 숫자면 반복
			while (!st.empty() && //닫는 괄호라는 조건은 여기서 삭제됨
				st.top() != "(" && 
				st.top() != "[" ) { //세가지조건 만족
				sum_ *= stoi(st.top()); //곱한다.
				st.pop(); // 스택 맨 위에있던 값 pop한다.
			}

			//예외처리
			if (st.empty() ||
				(tmp == ")" && st.top() != "(") ||
				(tmp == "]" && st.top() != "[")) { //스택빈것 or 매칭이 안되는것
				res = 0; //아예 성립하지 않음 result를 0으로 하고 탈출
				break;
			}

			//기본사항 
			if (tmp == ")") sum_ *= 2;
			else sum_ *= 3;
			st.pop();

			//숫자가 맨위에 있는경우 sum에 더해주고 pop한다
			while (!st.empty() &&
				st.top() != "(" &&
				st.top() != "[") {
				sum_ += stoi(st.top()); //sum에 더해준다.
				st.pop();
			}

			//계산된 sum을 string으로 바꿔서 stack에 push 한다
			st.push(to_string(sum_));
		}
	}
}

void out() {
	if (res == 0 || st.size() != 1 || st.top() == "[" || st.top() == "(") {
		cout << 0;
	}
	else
		cout << st.top();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> gual;
	solution();

	out();

	return 0;
}