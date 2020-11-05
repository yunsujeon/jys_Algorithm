//소수경로
/* 비밀번호는 4자리의 소수
비밀번호를 한번에 한자리밖에 바꾸지 못한다.
1033을 8179로 바꾸려면
1033 1733 3733 3739 8779 8179 로 바꿀 수 있을 것이다.
몇 단계를 거쳐야 비밀번호를 원하는 수로 바꿀 수 있을지 계산하라
항상 네자리를 유지해야되고 1000미만은 안된다*/

#include <iostream>
#include <queue>
#include <cmath>
#include <cstring> //memset 을 위해서
#define MAX 10000
using namespace std;

int a[MAX];
int prime[MAX];
int start, destination;
int cache[MAX];

//에라토스테네스의 체 로 소수판별해놓기
void primeNumberSieve() {
	//각자의 수로 초기화해준다.
	for (int i = 2; i <= MAX; i++) {
		a[i] = i;
	}
	//2부터 소수가 아닌것들을 0으로 변환시켜준다.
	for (int i = 2; i <= MAX; i++) {
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= MAX; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (a[i] != 0)
			prime[i] = i;
	}
}

int BFS(void)
{
	memset(cache, 0, sizeof(cache));
	queue<int> q;
	q.push(start);
	cache[start] = 1;

	while (!q.empty())
	{
		int curNum = q.front();
		q.pop();
		if (curNum == destination)
			return cache[curNum] - 1;
		//현재 숫자 천의 자리숫자부터
		int digit[4] = { curNum / 1000, (curNum / 100) % 10, (curNum / 10) % 10, curNum % 10 };
		//1333 이라면 ( 1, 3, 3, 3 ) 으로 분리된다.
		for (int i = 0; i < 4; i++)
		{
			//천의 자리 수는 0이면 안된다 여기서는 1033 2033 ~9033 까지 바뀐다.
			if (i == 0)
			{
				for (int j = 1; j < 10; j++) // 천의자리수가 0이면 안되니깐
				{
					int changeNum = 0;
					for (int k = 0; k < 4; k++) // 0, 1, 2, 3 번째 자리의 수
						if (i != k)
							changeNum += digit[k] * pow(10, 3 - k);
						else
							changeNum += j * pow(10, 3 - k);
					//바뀐 숫자가 소수이고 방문하지(cache) 않았다면 +1하여 push.
					if (prime[changeNum] == changeNum && cache[changeNum] == 0)
					{
						cache[changeNum] = cache[curNum] + 1;
						q.push(changeNum);
					}
				}
			}
			//천의자리수가 아닐때 여기서는 백, 십, 일의 자리수가 바뀐다.
			else
			{
				for (int j = 0; j < 10; j++)
				{
					int changeNum = 0;
					for (int k = 0; k < 4; k++)
						if (i != k)
							changeNum += digit[k] * pow(10, 3 - k);
						else
							changeNum += j * pow(10, 3 - k);
					//바뀐 숫자가 소수이고
					if (prime[changeNum] == changeNum && cache[changeNum] == 0)
					{
						cache[changeNum] = cache[curNum] + 1;
						q.push(changeNum);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int casecount;
	cin >> casecount;
	primeNumberSieve();

	for (int i = 0; i < casecount; i++) {
		cin >> start >> destination;
		int fin = BFS();
		if (fin == -1)
			cout << "Impossible" << endl;
		else
			cout << fin << endl;
	}
	return 0;
}