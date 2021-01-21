//컨베이어벨트 위의 로봇

#include <iostream>
#include <vector>

using namespace std;
int N, K;
struct con{
	int robot;//로봇이 있는지
	int dura; //내구도
};
vector<con>belt;
int check = 0;

void move() { //로봇이 닿으면 내구도 -1

	vector<con>temp;
	while (1) {
		check++;

		//1번과정
		belt.push_back({ 0,0 });//out of range 이기 때문에 회전 위해 추가해준다.
		for (int j = 2 * N - 1; j >= 0; j--) {
			belt[j + 1] = belt[j];
			belt[j] = { 0,0 };
		}
		//그리고 N번째 칸에 있는거를 0번째칸으로 옮긴다.
		con last = belt[2 * N]; //last 생성하고
		belt.pop_back(); //맨 뒤값을 뺀다.
		belt[0] = last;

		if (belt[N - 1].robot) { //내리는곳에 로봇이 있다면
			belt[N - 1].robot = 0; //로봇을 내린다.
		}

		//2번과정
		//한번 돌아갔으니깐 로봇들을 스스로 옮길수 있다면 앞으로 옮긴다.
		for (int k = N - 2; k >= 0; k--) { //끝에칸에서는 한번더 갈필요가 없다.
			if ((belt[k].robot == 1) && (!belt[k + 1].robot) && (belt[k + 1].dura)) {
				belt[k + 1].dura -= 1;
				belt[k + 1].robot = 1;
				belt[k].robot = 0;
			}
		}

		//3번과정
		if (belt.front().dura) {
			belt.front().robot = 1; //로봇을 올리고
			belt.front().dura -= 1; //내구도 마이너스
		}
		if (belt[N - 1].robot) { //내리는곳에 로봇이 있다면
			belt[N - 1].robot = 0; //로봇을 내린다.
		}

		int cnt = 0;
		for (int i = 0; i < 2 * N; i++) {
			if (belt[i].dura == 0) {
				cnt++;
			}
		}
		if (cnt >= K)
			break;
	}
}

int main() {
	cin >> N >> K; //내구도 0인게 K개이상이 되면 탈출하는거
	int a;
	for (int i = 0; i < 2*N; i++) {
		cin >> a;
		belt.push_back({ 0,a });
	}
	move();
	cout << check << endl;
	return 0;
}