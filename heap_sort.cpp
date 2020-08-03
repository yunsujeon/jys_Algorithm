/* 힙 트리구조를 이용하는 정렬방법 
이진트리, 완전이진트리 개념
힙은 최솟값이나 최댓값을 빠르게 찾아내기위해 완전 이진트리를 기반으로하는 !트리!
최대힙 : 부모노드가 자식노드보다 큰 힙
힙정렬을 하려면 정해진 데이터를 힙구조를 가지도록 만들어야한다.
힙생성 알고리즘 : 큰자식과 자신의 위치를 바꾸는것. O(log N)
전체 트리를 힙구조로 만드는 복잡도는 결국 O(N*logN)
이를 가지고 루트의 값을 가장 뒤쪽으로 보내면서 힙트리의 크기를 1씩빼준다.
가장뒤쪽으로 보낸거 : 정렬완료 -> 다시 나머지에 대해 힙생성알고리즘
결국 전체 힙 정렬의 전체 시간 복잡도 : O(N*logN)*/

#include <stdio.h>

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	//힙 생성하는 알고리즘
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// 하나씩 뒤로보내고 다시 힙을 생성하는 알고리즘
	for (int i = number - 1; i >= 0; i--) {
		// 루트의 값을 맨뒤로 보내는데 그 맨뒤 라는것은 하나씩 줄어든다.
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0; //루트는 항상 0일것
		int c = 1; //힙을 다시 구성하기 위한 변수
		//
		do {
			c = 2 * root + 1; //c는 root의 자식이 될것(자식의 왼쪽값)
			//자식중에 더 큰 자식을 찾는것
			if (c < i - 1 && heap[c] < heap[c + 1]) {//오른쪽값이 크다면 오른쪽값을 가리킴
				c++;
			}
			//루트보다 자식이 더 크다면 교환한다.
			if (c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c; //이제 그 자식이 root가 될것. 그리고 반복
		} while (c < i); //c가 하나씩 작아지는 i(최대값)보다 크게될경우 중단
	}
	for (int i = 0; i < number; i++) {
		printf("%d", heap[i]);
	}
}