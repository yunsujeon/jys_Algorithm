/*가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
즉 최소비용신장트리를 만들기 위한 대표알고리즘
여러 도시가있을때 도로로연결할때 비용을 최소화하고자 하는문제
모든 간선정보를 오름차순으로 정렬한뒤에 비용이적은 간선부터 그래프에포함
정렬된 순서에 맞게 그래프에 포함시키고 사이클을 형성하지않도록 함
잇기만 하면되는것이므로 사이클 발생하면 최소가 아니다
이는 사이클 테이블로 판별하는데 사이클테이블의 값이 동일하다면X*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//부모노드를 가져옴
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

//부모노드를 병합
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	//더 숫자가 작은 부모로 병합
	if (a < b) set[b] = a;
	else set[a] = b;
}

//같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

//간선 클래스 선언
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	/*bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}*/
};

bool compare(Edge a, Edge b) {
	return(a.distance < b.distance);
}

//메인
int main(void) {
	int n = 7; //노드수
	int m = 11; //간선수

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end(), compare);

	//각 정점이 포함된 그래프가 어디인지 저장한다
	//사이클 테이블 초기화 시켜주는것
	int set[1000];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	//거리의 합을 0으로 초기화한다
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//동일한 부모를 가리키지 않는경우, 즉 사이클이 발생하지않을때만!

		// -1 해주는 이유 : find는 사이클테이블을 검사하면서 같은부모인지 확인
		// 인자로는 사이클 테이블인 set[]배열의 인덱스가 들어온다. 이때 set[]배열의
		// 인덱스가 0부터 시작하기때문에 1이아닌 0부터 읽어주기 위해 -1해준다.
		if (!find(set, v[i].node[0]-1 , v[i].node[1]-1 )) {
			//이미 오름차순으로 정렬해놓았으니 사이클이 발생하지않으면 더해주면된다.
			sum += v[i].distance;
			unionParent(set, v[i].node[0]-1 , v[i].node[1]-1 );
		}
	}
	printf("%d\n", sum);
}