/*이진트리의 구현과 순회방식
가장 많이 사용되는 비선형 자료구조는 이진트리이다.
데이터의 탐색속도 증진을 위해 사용하는 구조이다.
실제로 트리를 제대로 구현하기 위해서는 포인터를 사용해야한다.
왜냐하면 완전이진트리가 아닌것은 배열로 표현하기 어렵기때문
전위순회 : 자기자신 -> 왼쪽자식 -> 오른쪽자식
중위순회 : 왼쪽자식 -> 자기자신 -> 오른쪽자식
후위순회 : 왼쪽자식 -> 오른쪽자식 -> 자기자신*/

//완전이진트리가 아니더라도 안정적으로 작동하는 이진트리
#define number 15
#include <iostream>

using namespace std;

//class : 접근제어자 기본 private
//구조체 : 접근제어자 기본 public
typedef struct node* treePointer; //구조체를 포인터형태로 사용하기위해 , 노드 구조체를 treePointer 이름으로 사용한다
typedef struct node {
	int data;
	treePointer leftChild, rightChild; //포인터변수를 만들어준다.
}node; //node 라는 이름의 구조체

//전위순회 구현
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
//중위순회 구현
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위순회 구현
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[number + 1];
	//노드들을 초기화해준다
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	//각 노드들을 연결시켜준다.
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i]; 
		else
			nodes[i / 2].rightChild = &nodes[i];
	}
	//전위순회를 실행한다.
	preorder(&nodes[1]);
	return 0;
}
