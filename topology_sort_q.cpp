/*위상정렬 백준 문제풀이*/

// 2252번
/* N명의 학생들 줄세우려한다. 두 학생의 키를 비교하는 방법 사용, 일부 학생들의 키만 비교
입력 : N(1~32,000) M(1~100,000) M은 키를 비교한 횟수 
ex) 3 2     3명의학생 2번비교함
    1 3     1번학생이 3번학생보다 앞
    2 3     2번학생이 3번학생보다 앞
    */
/*

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n, inDegree[MAX], result[MAX];
vector <int> a[MAX];

void topologySort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) { //차수가 0인걸 일단 큐에 넣는다.
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) { //돌아가면서 조건에맞는걸 계속 큐에 넣고 맨앞에있는거 빼고 반복
        int x = q.front();
        q.pop();
        result[i] = x; //큐 맨앞에있는걸 꺼내고 result에 넣는다
        for (int j = 0; j < a[x].size(); j++) { //연결노드들 확인
            int y = a[x][j]; //그 연결노드를 y로 정의
            if (--inDegree[y] == 0) //차수를 1뺐을 때 y의 진입차수가 0이되면
                q.push(y); //큐에넣는다.
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int m;
    int x, y;

    scanf_s("%d %d",&n,&m);
    for (int i = 0; i < m; i++) {
        scanf_s("%d %d", &x, &y);
        a[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
}
*/

//1516번
//게임개발 - 먼저지어야 될 건물이있다.

//왜 위상정렬하는지? 선행되는 건물을 inDegree로 볼수있다. 진입차수

/*건물의 종류 수가 주어지고 그다음엔 각 건물을 짓는데 걸리는 시간과 그 건물보다 먼저 지어져야될
/건물들의 번호가 주어진다.
/N개의 각 건물이 완성되기까지 걸리는 최소시간을 출력한다.
*/
//입력 ex) 
/*
5           5개의 건물
10 -1       1번건물은 10시간이 걸린다.
10 1 -1     2번건물은 10시간이 걸리고 1번건물이 선행되어야한다.
4 1 -1      3번건물은 4시간이 걸리고 1번건물이 선행되어야한다.
4 3 1 -1    4번건물은 3시간이 걸리고 3번건물과 1번건물이 선행되어야한다.
3 3 -1      5번건물은 3시간이 걸리고 3번건물이 선행되어야한다.
*/
//모든 정점이 수행될수있는 최소시간을 출력하는 것이므로 단순히 임계경로를 출력하면된다
//간선이 연결되는 순간을 기준으로 현재보다 더 오래걸린다면 계속하여 갱신하는 방식으로..

/*
#include <vector>
#include <iostream>
#include <queue>
#define MAX 501

using namespace std;

int n, inDegree[MAX], time[MAX], result[MAX];
vector<int> a[MAX];

void topologySort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            result[i] = time[i];
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            result[y] = max(result[y], result[x] + time[y]); //최댓값을 갱신해주는것
            if (--inDegree[y] == 0) q.push(y);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", result[i]);
    }
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        while (1) {
            int x;
            cin >> x;
            if (x == -1) break;
            inDegree[i]++;
            a[x].push_back(i);
        }
    }
    topologySort();
}
*/

//1948 임계경로
/* 모든 도로가 일방통행. 지도를 그리기 위해서 시작 도시로부터 도착 도시까지 모든 경로를 탐색
도착도시에서 마지막에 모두 모인다. 이들이 만나는 시간은 출발도시로부터 출발한 후 몇시간 후? = 젤 마지막 사람 도착시간
어떤사람은 이 시간에 만나기 위해 1분도 쉬지않고 달려야된다. 이 사람들이 지나는 도로의 수 카운트
입력 ex)
7       도시의 개수
9       도로의 개수
1 2 4   도로의 출발도시:1 / 도로의 도착도시:2 / 도로를 지나는데 걸리는 시간:4
1 3 2   출발도시:1 / 도착도시:3 / 시간:2
....
출력 ex)
12      만나는 시간
5       1분도 쉬지않고 달려야 하는 도로의 수
*/
//모든 임계경로를 구하려면 역추적해야된다.

#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001

using namespace std;

class Edge {
public:
    int node;
    int time;
    Edge(int node, int time) { //생성자로 초기화
        this->node = node;
        this->time = time;
    }
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort() {
    queue<int> q;
    q.push(start); //처음 있는거를 큐에 넣는다. (진입차수0이라그랬음)
    while (!q.empty()) { //큐가 빌때까지 계속한다.
        int x = q.front(); //큐의 맨앞에있는게 x
        q.pop();
        for (int i = 0; i < a[x].size(); i++) { //인접노드를 번갈아가며
            Edge y = Edge(a[x][i].node, a[x][i].time); //y에는 노드뿐 아니라 시간도 같이저장
            if (result[y.node] <= y.time + result[x]) { //시간이 time을 더한것보다 작으면
                result[y.node] = y.time + result[x]; //더 큰값으로 갱신해준다.
            }
            if (--inDegree[y.node] == 0) //새롭게 진입차수가 0이 된것이 있다면
                q.push(y.node); //큐에 삽입해준다.
        }
    }
    //결과를 역추적한다.

    int count = 0;
    q.push(finish); //끝에있는걸 큐에 넣는다.
    while (!q.empty()) { //큐가빌때까지 반복
        int y = q.front();
        q.pop(); //꺼내준다
        for (int i = 0; i < b[y].size(); i++) { //노드의 갯수만큼 반복
            Edge x = Edge(b[y][i].node, b[y][i].time); 
            //도착점에 연결되어있는 시작점을 하나씩 확인하면서 최장경로인지 확인
            if (result[y] - result[x.node] == x.time) {
                count++; //최장경로의 갯수 += 1
                //큐에는 한 번씩만 담아 추적한다.
;                if (c[x.node] == 0) {
                    q.push(x.node);
                    c[x.node] = 1;
                }
            }
        }
    }
    printf("%d\n%d", result[finish], count);
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, node, time;
        cin >> x >> node >> time;
        a[x].push_back(Edge(node, time));
        b[node].push_back(Edge(x, time));
        inDegree[node]++;
    }
    //1 7 이면 7로가는 경로를 찾는데, 가장 오래걸리는 시간을 찾아야된다.
    //가장 오래걸리는 시간을 찾고 그를 지나는 노드들이 바로 쉬지않고 달려야되는 도로의 수이다.
    cin >> start >> finish; 
    topologySort();
}