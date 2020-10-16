#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int team=0;
	float result;
	do{
		N= N - 2;
		M= M - 1;
		team++;
	} while (N > 1 && M > 0);
	
	//남은 K들을 소진시킨다
	//하지만 K가 적고 남은 M이나 N들이 많다면?
	K = K - (M + N); // M+N = 팀을 다 꾸리고 남은인원들
	if (K > 0) { //남은 M N으로 소진을 시키고도 K가 남으면 팀에서 갉아먹기
		result = float(K) / 3.0;
		team = team - ceil(result); // 11명이면 4팀이 망가짐 올림연산
	}
	cout << team << endl;
}
