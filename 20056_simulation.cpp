//맵에 여러 값이 들어가야된다는것에서 막혔다.
//1번이 N번과 이어져 있다는걸 이해못해서 막혔다. 모듈러연산하면될것

/*
#include <iostream>
#include <vector>
#include <string.h>
#define MAX 55

using namespace std;

struct ball {
	int r;
	int c;
	int m;
	int s;
	int d;
};
//8방향을 각 방향의 정의d에 따라 정의해준다
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
//공을 흩뿌려주는 번호
int dir0[] = { 0,2,4,6 };
int dir1[] = { 1,3,5,7 };

int N, M, K;
vector<ball> map[MAX][MAX]; //ball자료형을 가지는게 여러개 들어갈수있다는뜻
vector<ball> fireball;

void move() {
	memset(map, false, sizeof(map)); //초기화
	for (int i = 0; i < fireball.size(); i++) { //움직이는건 공 갯수만큼이다.
		int r = fireball[i].r; //i번째 fireball의 r좌표는
		int c = fireball[i].c; //c좌표
		int m = fireball[i].m; //mass
		int s = fireball[i].s; //speed
		int d = fireball[i].d; //dir
		int move = s % N; //나머지연산으로 speed에 따라 몇번이동할지 정의해준다.
		int nr = r + dx[d] * move; //이동할 r의 위치 
		int nc = c + dy[d] * move; //이동할 c의 위치
		if (nr > N) //만약 N이 3인데 nr이 4가 됐다면(5는될수없다)
			nr -= N; //nr은 4-3 해서 1이 되게된다.
		if (nr < 1)
			nr += N;
		if (nc > N)
			nc -= N;
		if (nc < 1)
			nc += N;
		map[nr][nc].push_back({ nr,nc,m,s,d }); //새로 정해준 좌표를 map의 새 좌표에 심어준다.
		fireball[i].r = nr; //fireball의 r좌표는 nr이 된다.
		fireball[i].c = nc; //fireball의 c좌표는 nc가 된다.
	}
}

void sum() {
	vector<ball> temp; //ball형식을 옮기기 위한 temp
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() == 0)continue;
			if (map[i][j].size() == 1) { //뭔가가 있다면
				temp.push_back(map[i][j][0]); //temp에 옮겨서 계산할거다.
				continue;
			}
			int m_sum = 0; //질량의 합
			int s_sum = 0; //스피드의 합
			int cnt = map[i][j].size(); //이 좌표에 있는것들의 갯수
			bool even = true;
			bool odd = true;
			for (int k = 0; k < cnt; k++) { //좌표에 있는 것들의 갯수만큼 반복
				m_sum += map[i][j][k].m; //돌아가면서 m_sum에 합쳐준다.
				s_sum += map[i][j][k].s; //speed도 합해준다.
				if (map[i][j][k].d % 2 == 0) //d의 홀짝을 결정해준다.
					odd = false;
				else
					even = false;
			}
			int mass = m_sum / 5; 
			int speed = s_sum / cnt;
			if (mass == 0)continue;
			if (even == true || odd == true) {
				for (int k = 0; k < 4; k++) //4방향으로 뿌려주자
					temp.push_back({ i,j,mass,speed,dir0[k] });
			}
			else {
				for (int k = 0; k < 4; k++)
					temp.push_back({ i,j,mass,speed,dir1[k] });
			}
		}
	}
	fireball = temp; //temp의 값을 fireball에 이식
}

int main() {
	int num = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball.push_back({ r,c,m,s,d }); //공 자체를 저장
		//map[r][c].push_back({ r,c,m,s,d }); //맵에 공을 저장 굳이필요없다. map에서 fireball로 재정의 할것이기때문
	}
	for (int i = 0; i < K; i++) { //k번 실행한다.
		move();
		sum();
	}
	int ans = 0;
	for (int i = 0; i < fireball.size(); i++) {
		ans += fireball[i].m; //파이어볼 질량의 합
	}
	cout << ans << endl;
}
*/

#define MAX 51
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int N, M, K;

struct ball {
	int r;
	int c;
	int m;
	int s;
	int d;
};
vector<ball>fireball;
vector<ball>map[MAX][MAX]; //여러 값을 가질수 있다는 것을 내포한다. 값을 push하면 [MAX[MAX][i] 이기때문
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };
int st_0[] = {0,2,4,6};
int st_1[] = {1,3,5,7};

void move() { //이동해주고 map이 저장해주는것
	memset(map, false, sizeof(map)); //초기화
	for (int i = 0; i < fireball.size(); i++) {
		int r = fireball[i].r;
		int c = fireball[i].c;
		int m = fireball[i].m;
		int s = fireball[i].s;
		int d = fireball[i].d;
		int new_s = s % N; //속도(몇칸이나이동)
		int new_r = r + dr[d] * new_s;
		int new_c = c + dc[d] * new_s;
		if (new_r > N)
			new_r -= N;
		if (new_r < 1)
			new_r += N;
		if (new_c > N)
			new_c -= N;
		if (new_c < 1)
			new_c += N;
		//아래와같이 해주면 fireball을 하나 더 생성해주는거다. 벡터이기때문
		//fireball.push_back({ new_r,new_c,m,s,d });
		fireball[i].r = new_r;
		fireball[i].c = new_c;
		map[new_r][new_c].push_back({ new_r,new_c,m,s,d });
	}
}

void hap_spread() {
	vector<ball>temp; //fireball의 바뀐값을 임시로 저장할 벡터 temp 생성
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() == 0) 
				continue;
			if (map[i][j].size() == 1) {
				temp.push_back(map[i][j][0]);
				continue;
			}
			//합할것은 2개 이상일때부터 있을것이므로.
			int odd = 0; //홀수아니고
			int even = 0; //짝수아니야
			int cnt = map[i][j].size();
			int new_m = 0;
			int new_s = 0;
			for (int k = 0; k < cnt; k++) {
				new_m += map[i][j][k].m;
				new_s += map[i][j][k].s;
				if (map[i][j][k].d % 2 == 0) { //짝수라면
					even = 1;
				}
				else {
					odd = 1;
				}
			}
			new_m = new_m / 5;
			new_s = new_s / cnt;
			if (new_m == 0) //보고했음.. 생각못함
				continue;
			if ((odd == 1)&&(even==1)) { //홀이던 짝이던 섞여있다면  1357
				for (int k = 0; k < 4;k++) {
					temp.push_back({ i,j,new_m,new_s,st_1[k] });
				}
			}
			else { //하나만있다면
				for (int k = 0; k < 4; k++) {
					temp.push_back({ i,j,new_m,new_s,st_0[k] });
				}
			}
		}
	}
	fireball = temp; //결국 fireball이 바뀐것이 나타나게 된다. map노필요
}

int main() {
	cin >> N >> M >> K;
	for (int k = 0; k < M; k++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball.push_back({ r,c,m,s,d });
	}
	for (int i = 0; i < K; i++) {
		move();
		hap_spread();
	}
	int ans = 0;
	for (int i = 0; i < fireball.size(); i++) {
		ans += fireball[i].m; //파이어볼 질량의 합
	}
	cout << ans << endl;
	return 0;
}