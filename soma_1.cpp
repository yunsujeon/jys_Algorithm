/*
소마 스토리 앤 파이터 M
코더랜드의 인기 게임 소마 스토리 앤 파이터 M에는 많은 단독 스킬과 연계 스킬이 존재하며 사용자들은 스킬을 다양하게 조합하여 사용할 수 있다.

여기서 단독 스킬이란 다른 스킬에 영향을 받지 않고 단독적으로 사용할 수 있는 스킬을 의미하며
연계 스킬은 단독 스킬과 달리 단독적으로 사용이 불가하여 사전에 다른 스킬을 사용한 후 사용할 수 있는 스킬을 의미한다.

예를 들어 마법사 직업의 스킬로는 근접 공격, 염력, 불 뿜기, 물 뿌리기, 회복으로 구성되어 있고 아래의 연계 구조를 가진다고 가정한다.

근접 공격 후 염력 또는 불 뿜기를 사용할 수 있다. 이때 근접 공격은 염력 또는 불 뿜기의 선행 스킬이며 염력 또는 불 뿜기 스킬은 근접 공격의 후행 스킬이라고 한다.
염력 후 회복 또는 물 뿌리기를 사용할 수 있다. 이때 염력은 회복 또는 물 뿌리기의 선행 스킬이며 회복 또는 물 뿌리기 스킬은 염력의 후행 스킬이라고 한다.
근접 공격과 같이 특정 연계 구조가 제시되어 있지 않다면 단독 스킬로 규정하고 각 스킬은 아래의 표와 같이 구분된다.

스킬 명	구분
근접 공격	단독 스킬
염력	연계 스킬
불 뿜기	연계 스킬
물 뿌리기	연계 스킬
회복	연계 스킬
위의 내용을 토대로 마법사 직업은 총 3가지의 스킬 구성이 가능하다.

근접 공격 → 염력 → 회복
근접 공격 → 염력 → 물 뿌리기
근접 공격 → 불 뿜기
단, 연계 스킬들은 아래의 조건을 가지고 있다.

근접 공격 → 염력 이후 회복이나 물 뿌리기와 같이 스킬 사용 이후 연계되는 스킬이 있다면 중간에 스킬을 중단할 수 없다.
염력 스킬과 같은 연계 스킬의 경우 단독으로 사용할 수 없다.
단독 스킬 하나로만 구성된 경우는 스킬 구성에서 제외한다.
하나의 스킬은 여러 개의 후행 스킬을 가질 수 있지만 (1:N) 여러 개의 선행 스킬을 가질 수는 없다. (1:1)
스킬이 무한으로 연계되는 상황은 없다고 가정한다.
소마가 구성할 수 있는 연계 스킬 구성을 모두 출력하시오.

입력
첫 번째 줄에는 KK 개의 스킬을 공백을 구분자로 입력받는다. 이때 스킬은 각 스킬을 나타내는 영문자로 이뤄진 문자열로 입력되며 대소문자를 구분한다. (a 스킬 ≠ A 스킬)

(1 < K ≦ 100)
두 번째 줄에는 연계 스킬의 개수 정수 N을 입력받는다.
(1 ≦ N < K)
세 번째 줄부터 N+2번째 줄까지 x와 y를 공백을 구분자로 연계 스킬의 관계를 입력받는다. (x 스킬 이후 y 스킬을 사용할 수 있다는 의미이며 반대로 사용은 불가능하다.)

출력
소마가 구성할 수 있는 연계 스킬 구성을 공백을 구분자로 모두 출력한다.
출력의 순서는 입력된 순서대로 출력한다.
입력 예시
h g f w r
4
h g
h f
g r
g w

출력예시
h g r
h g w
h f


*/

/*
이 그래프를 구성할 수 있느냐 가 첫번째 문제
트리구조 !
Directed Acycle Graph
자기에게 들어오는 간선이 없는게 단독스킬
자기한테 들어오는 간선이 있는게 연계스킬
dfs bfs 탐색하면서
모든 out degree 가 0인점이 끝점일텐데..
시작점으로부터 dfs를 하자
입력을 받았으면 단독스킬을 찾아서 DFS를 하고 스킬트리를 출력하는것

def dfs(idx, path) : // idx : 현재 스킬의 번호, path : 단독 스킬부터 현재 스킬까지 경로를 기억
    if len(adj[idx]) == 0 :
        print(path)
        return
    for nxt in adj[idx]:
        dfs(nxt,path+[skills[nxt]])

dfs부분은 길지않았다 입력을 잘받자 그래프로

시간복잡도는 O(V+E)일것이다. dfs랑 동일하니깐
근데 입력까지 다 하면 O(V^2)까진 올라갈지도모른다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;
vector <int> v[1000];
map<string, int>m; //그래프를 그리기 위해.. 이런 일련의 과정이 복잡하다. python으로하면 편함
map<int, string>rm; //반대의경우도 생성해놓자.
int indegree[1000] = { 0, };

void dfs(int idx, string path) { //현재스킬의번호, 단독스킬부터 현재스킬까지의 경로기억
    if (v[idx].size()==0) { //종료조건 vector에 원소가 없을때. 즉 끝에도달하면 리턴
        cout << path<<endl;
        return;
    }
    for (int next = 0; next < v[idx].size();next++ ) { //연결된 노드들을 봐야된다.
        int asf=v[idx].size(); //확인용도
        dfs(v[idx][next], path.append(rm[v[idx][next]]));
        path.erase(path.end() - 1); //맨 마지막 값 지워준다. 백트래킹같이
    }
}

int conv(string skill_name) {//스킬의 이름을 정점의 번호로 반환하는 함수
    return m[skill_name];
}

int main() {
    int cnt = 0, K=0;

    //array에 인풋을 받기
    string Kin;
    getline(cin, Kin);
    char* buffer = new char[1000];
    strcpy(buffer, Kin.c_str());
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        m[string(token)] = cnt++;
        rm[cnt-1] = string(token);
        token = strtok(NULL, " ");
        K++;
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        int aa= conv(a);
        int bb = conv(b);
        v[aa].push_back(bb); //그래프 생성
        indegree[bb]++; //방문한거를 하나씩 증가
    }

    for (int i = 0; i < K; i++) {
        if (indegree[i] == 0) {
            dfs(i,rm[i]);
        }
    }
    
    return 0;
}


