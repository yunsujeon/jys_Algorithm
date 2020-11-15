//A가 비어있을 때 C에 담겨있을 수 있는 물의 양을 모두 구하라
#include <iostream>
#include <algorithm> //sort 쓰기위함
#include <queue>

using namespace std;

struct Data {
	int a, b, c;
};

int A, B, C; //최대치
bool chk[202][202], ans[202];

void bfs() {
	queue <Data> q;
	q.push({ 0,0,C });
	while (!q.empty()) {
		Data now = q.front();
		q.pop();

		//이미 확인한 것이라면 다음 while문으로 가서 확인
		if (chk[now.a][now.b])
			continue;

		chk[now.a][now.b] = true;

		if (now.a == 0)
			ans[now.c] = true;

		//옮기는 경우의 수는 총 6개 반복 a->b a->c b->a b->c c->a c->b

		//a->b
		/*현재 a에 담겨있는양 + 현재 b에 담겨있는 양이
		입력값 B보다 큰 경우 B물통은 최대용량만큼
		물이 가득 채워지게 되고, A물통은 현재 a양 +현재 b양 -최대용량 만큼
		물이 남게 된다. */
		if (now.a + now.b > B)
			q.push({ (now.a + now.b) - B,B,now.c });
		//현재 a + 현재 b 용량이 B보다 작은 경우
		/* A물통에서 물이 전부 옮겨지므로 A는 0
		B는 현재 a+ 현재 b 용량이 된다.
		C는 변화가 없으므로 현재 용량 now.c를 넣어준다. */
		else
			q.push({ 0,now.a + now.b,now.c });

		//a->c
		if (now.a + now.c > C)
			q.push({ (now.a + now.b) - C,now.b,C });
		else
			q.push({ 0,now.b,now.a + now.c });

		//b->a
		if (now.b + now.a > A)
			q.push({ A,(now.b + now.a) - A,now.c });
		else
			q.push({ now.b + now.a, 0, now.c });

		//b->c
		if (now.b + now.c > C)
			q.push({ now.a,(now.b + now.c) - C,C });
		else
			q.push({ now.a, 0, now.b + now.c });

		//c->a
		if (now.c + now.a > A)
			q.push({ A,now.b,(now.c + now.a) - A });
		else
			q.push({ now.c + now.a,now.b,0 });

		//c->b
		if (now.c + now.b > B)
			q.push({ now.a,B,(now.c + now.b) - B });
		else
			q.push({ now.a,now.c + now.b,0 });
	}

}

void print() {
	for (int i = 0; i <= C; i++) {
		if (ans[i])
			printf("%d ", i);
	}
}

int main() {
	cin >> A >> B >> C; //C는 꽉 차있는것 A,B는 비어있다.
	bfs();
	print();
	return 0;
}