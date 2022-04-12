/*
땅콩 먹기
소마는 N 개의 땅콩을 발견했다. 땅콩은 1차원 수직선 위에 존재하고, i번째 땅콩은 원점으로부터 x_ix
i 만큼 떨어져 있으며 소마는 원점으로부터 ee 만큼 떨어져 있는 곳에 있다. 소마는 땅콩을 먹는 것을 아주 좋아하지만, 
모든 땅콩 중에서 M 개만을 먹을 수 있다.

소마는 기억력이 좋지 않아 지금까지 지나온 길에 빨간 선을 그리는 마법을 부려왔다. 물론 이 수직선에서도 마찬가지이다.
즉, 소마가 수직선 위의 위치 3에서 위치 5까지 움직인다면, 위치 3에서 위치 5까지 총 길이 2의 빨간 선이 그려진다. 
단, 이미 빨간 선이 칠해진 곳을 다시 이동하게 될 경우, 새롭게 빨간 선이 그려지지는 않는다.

소마가 N 개의 땅콩 중 M 개의 땅콩을 먹으려 할 때, 그려지게 될 빨간 선 중 최소 길이를 출력하시오.

입력
첫 번째 줄에 땅콩의 개수 N, 먹으려는 땅콩 개수 M, 그리고 소마의 위치 E 순으로 공백을 구분자로 입력받는다. (N, M 그리고 EE는 정수이다.)
1 ≦ N ≦ 10,000
1 ≦ M ≦ N

두 번째 줄에 N개의 숫자에 대하여 땅콩이 있는 위치를 공백을 구분자로 입력받는다. (땅콩의 위치는 정수이다.)

두 개의 땅콩이 같은 위치에 있는 예시는 입력되지 않으며 땅콩의 위치는 오름차순으로 입력된다.

소마의 위치와 땅콩의 위치가 겹치는 경우 소마는 움직이지 않고 땅콩을 바로 먹을 수 있다.

출력
소마가 땅콩을 먹으려 할 때 그려지게 될 빨간 선 중 최소 길이를 출력한다.

입력 예시
6 3 7
2 4 5 8 11 12

출력 예시
4
*/

/*
일단 내가 한것도 맞을 수 있다는 분위기 ㅇㅇ 포인터를 옮겨가며
아니다 반례가 존재할거이다.
4 5 10 15 일때 15를 먼저먹으면.. 15는 먹은것 그리고 10을 먹을텐데..틀리지

슬라이딩 윈도우가 맞는것 같다. (연속된 M개를 먹는다.)
연속된것을 먹을것이다!

1. E가 M개의 범위를 벗어났다면 그 구간과 + 끝점에서 E까지의 거리를 더해줘야 될 것이다.
2. E가 M개의 범위 내에 있다면 그 구간의 거리가 될 것이다.
이중에 최소가 최소값일 것이다.

이건 좀 더 쉬운 문제인거같다.
*/#define INF 987654321;
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;

int N, M, E;
vector <int> v;
int minvalue = INF;

int solution() {
    int pointer = 0;
    while (pointer != N - M + 1) { //볼필요없는 부분까지 포인터가 가면 스탑
        int val1 = v[pointer + M - 1] - v[pointer]; //먹었을 때 빨간선의 길이
        if (E < v[pointer]) {
            val1 = val1 + v[pointer] - E;
        }
        else if (E > v[pointer+M-1]) {
            val1 = val1 + E - v[pointer + M - 1];
        }
        //여기까지 해서 값을 저장해줄 수 있다.
        if (minvalue >= val1) {
            minvalue = val1; //최대값을 갱신한다.
        }
        pointer++; //다음 포인터로 이동시킨다.
    }
    return minvalue;
}

int main(){
    cin >> N >> M >> E;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    cout << solution() << endl;
    return 0;
}






/*
//3번문제
int MIN = 10001;
int N, M, E;
int tant[10001] = { 0 };
int visit[10001] = { 0, };

int main() {
    cin >> N >> M >> E; //땅콩갯수, 먹으려는땅콩갯수, 지금 위치
    int tt;
    for (int i = 0; i < N; i++) {
        cin >> tt;
        tant[i] = tt;
    }
    int point = 0;
    for (int i = 0; i < N; i++) { //다 돌며 e에서 값 뺀게 가장 작은점 찍기
        int j = E - tant[i];
        j = abs(j);
        if (j <= MIN) {
            MIN = j;
            point = i;
        }
    }
    //시작점을 알아냈다. 지금부터 시작

    int left;
    int right;
    if (E < tant[point]) {
        left = E;
        right = tant[point];
    }
    else if (E > tant[point]) {
        left = tant[point];
        right = E;
    }
    else {
        left = E;
        right = E;
    }

    for (int i = 0; i < M; i++) {
        int pleft = point--;
        int tleft = tant[pleft];
        int pright = point++;
        int tright = tant[pright];
        int newleft = abs(left - tleft);
        int newright = abs(tright - right);
        if (newleft < newright) {
            left=
        }


    }

    return 0;

}
아 개 헷갈린다 문제나 저장해놓자.
*/
