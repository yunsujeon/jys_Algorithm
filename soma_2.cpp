﻿/*
소마 피시방
소마는 코더랜드에 새로운 피시방을 오픈했다.

소마 피시방은 시간당 1,000원으로 이용할 수 있으며 매일 h 시간 동안 p 대의 PC를 운영하고 있다.

소마 피시방은 인기가 많아 예약제로 운영되며 미리 고객들로부터 사용을 희망하는 PC번호와 사용 희망 시간을 전달받아 운영하고있다.

예를 들어 2대의 PC를 활용하여 하루 4시간 동안 영업을 한다고 가정하고 총 7명의 손님으로부터 아래와 같은 예약을 받았을 때 1번 PC를 통해 0원, 2번 PC를 통해 4,000원의 이익을 얻을 수 있다.

예약 PC	사용 희망 시간
1번	10시간
1번	5시간
1번	7시간
2번	10시간
2번	1시간
2번	3시간
2번	7시간
소마 피시방의 상세 조건은 아래와 같다.

고객이 운영 시간보다 사용 희망 시간을 많이 신청한 경우 해당 고객은 받지 않는다.
고객은 한 시간 단위로 사용 희망 시간을 신청한다.
소마가 각 PC당 얻을 수 있는 최대 수익을 출력하시오.

입력
첫 번째 줄에는 PC의 대수 p, 예약한 손님의 수 n, 피시방 운영 시간 h 순으로 공백을 구분자로 입력받는다. (p, n, h는 정수이다.)
1≦p≦100
0≦n≦1000
0≦h≦24
두 번째 줄부터 n+11번째 줄까지 예약한 손님이 이용할 PC번호 정수 x와 이용할 시간 정수 y를 공백을 구분자로 입력받는다.
1≦x ≦p
0≦y≦∞

출력
PC번호와 각 PC를 통해 소마가 얻을 수 있는 최대 수익을 공백을 구분자로 출력한다.
PC번호를 기준으로 순서대로 출력한다.
PC번호는 1부터 시작하며 p 번 까지 있다.

입력 예시
2 7 4
1 10
1 5
1 7
2 10
2 1
2 3
2 7

출력 예시
1 0
2 4
*/

/*
그리디는 아니다
15시간인데 2 3 4 10 이면.. 작은순서대로 채워도 안되고
큰 순서대로 채워도 안될것이기 때문. 2 3 10 채워야되는디..
(그래서 내가 시도한 sort를 한 방법도 사실.. 흠)

n명의손님이면 어떤 손님들을 선택해야 손님들의 돈을 최대한 빨아먹을수있냐?

봐야할게 많다 - DP가 최고ㅋㅋ
DP는 항상 네가지 스텝이 반복된다.
1. 테이블 정의가 필요 sub optimal problem (structure?)
2. 이 테이블을 가득 채웠다고 치면 문제가 원하는 정답 가능한가
3. 초기값을들 찾아야된다.
4. 점화식으로 표현
4번이 실패하면 1번으로 돌아간다

최대 사용시간만 기록해버린다면 안될것이다.
DP[i][j]=i번째 pc를 j시간동안 사용하도록 사람을 배정하는게 가능하면 1, 아니면 0
ans = 0
for i = 1~p 
    for j = h ~ 0 //이걸 y부터 h까지 증가시키는걸로 구현하려면?
        //
          if DP[i][j]==1:
                ans += j
                    break
print ans

3번째 step : 
DP[1~p][0]=1 //모든 컴퓨터마다 0시간을 쓰는건 가능
나머지는 모두 0 인상황으로 시작한다.

4번째 step : 
새로 들어온 사람이(x번 컴퓨터, y시간 사용하고싶다)
DP[x] 배열에 변화가 생기겠지 ?
DP[x][0...h] 모든 차원에 변화가능성이 있는곳에 1을 써주면 될것
for j = h ~y 로 거꾸로 내려온다.


DP[x][j]를 갱신하고싶다.
    if DP[x][j]==1: 무시
    else : DP[x][j-y]==1 이면 (새로 들어온 사람이 없을때 x번 컴퓨터를 j-y시간 쓰는게 가능했던 상황, 그러면 DP[x][j]=1)
       DP[x][j] |= DP[x][j - y]




    풀어보자

int P, N, H;
void input() {
    cin >> P >> N >> H;
}
int dp[105][25]; //그냥 넉넉하게

void pro() {
    for (int i = 1; i <= p; i++)
        dp[i][0] = 1;
    while (N--) {
        int x, y;
        cin >> x >> y;
        for (int i = H; j >= y; j--) {
            DP[x][j] |= ~~ 위에 꺼
        }

    }
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        for (int j = H; j >= 0;j--) {
            if (DP[i][j]) {
                ans = j
                    break;
            }
        }
    }
    cout << ans;
}
*/

#include <iostream>

using namespace std;
    
int p = 0; //피씨 대수
int n = 0; //손님 명수
int h = 0; //h시간만 운영할거다
int dp[105][25]; //그냥 넉넉하게

void solution() {
    for (int i = 1; i <= p; i++) //dp의 초기값 지정
        dp[i][0] = 1;

    while (n--) { // n만큼 돌면서 dp 수행
        int x, y; //입력받을거
        cin >> x >> y;
        for (int j = h; j >= y; j--) {
            dp[x][j] |= dp[x][j - y];
        }

    }
    int ans = 0;

    for (int i = 1; i <= p; i++) {
        for (int j = h; j >= 0; j--) {
            if (dp[i][j]) {
                ans += j;
                cout << i << '\0' << j << endl;
                break;
            }
        }
    }
}

int main() {
    cin >> p >> n >> h;
    solution();
    return 0;
}
