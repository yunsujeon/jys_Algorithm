/*대표적인 그래프 알고리즘으로 합집합찾기
여러개의 노드가 존재할때 두개의 노드를 선택해서
현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘
1과 2가 연결되어있을 때 2의 인덱스에 1이 들어간다. 즉 부모는 더 작은값
2와 3이 연결되면 부모가 2이지만 1과도 연결되어있으므로 부모는 다 1*/


//parent[] 의 의미 파악

#include <stdio.h>

int getParent(int parent[], int x) { //핵심 재귀알고리즘
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]); //계속 찾아들어간다
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) { //현재집합에 속하는지확인
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1; //현재집합에 속한다.
	else return 0; //현재집합에 속하지않는다.
}

int main() {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	} //각자의 parent를 각자의 수로 초기화한다.
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
}