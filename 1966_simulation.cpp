#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue <pair<int,int>> q;
int arr[101][2] = { 0, };

int main() {
	int tcase;

	cin >> tcase;
	for (int i = 0; i < tcase; i++) {//테스트케이스 수
		int N, M, s;
		int res1 = 0;
		int find;

		memset(arr, false, sizeof(arr));

		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> s;
			if (j == M) {
				find = s;
				q.push({ s,1 });
			}
			else {
				q.push({ s,0 });
			}
		}
		//큐의 사이즈를 다 돌아보며 큐 front 보다
		//현재보다 큰 수가 있다면 pop후에 다시삽입
		//큐가 빌때까지 반복해준다.

		while (!q.empty()) {
			int MAX = -1;
			int rfront = 0, front =0, size=0, result=0; //초기화
			for (int j = 0; j < q.size(); j++) {
				int front = q.front().first;
				int second = q.front().second;
				if (j == 0)  //처음만 rfront를 지정
					rfront = front;
				if (front > MAX) 
					MAX = front; //MAX를 front로 잡아준다.				
				if (rfront < MAX) //MAX가 한번이라도 바뀌면
					size = 1;
				q.pop();
				q.push({ front,second });
				if (j == (q.size() - 1)) { //마지막때
					if (size == 1){ //MAX가있었다면
						front = q.front().first;
						second = q.front().second;
						q.pop();
						q.push({ front,second });
					}
					else { //rfront가 즉 MAX이면
						result = q.front().first;
						second = q.front().second;
						q.pop();
						arr[res1++][second] = result; //출력이나 마찬가지
					}
				}
			}
		}
		
		for (int j = 0; j < N; j++) {
			for (int z = 0; z < 2; z++) {
				if ((arr[j][z] == find)&&z==1) //하지만 찾고싶은 수가많다면은?
					cout << j + 1 << endl;		//0번째가 아니고 1번째니깐
			}
		}
	}
	return 0;
}

