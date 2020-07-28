/*퀵정렬- 분할정렬알고리즘 O(N*logN)
피벗값을 설정하고 나눈다. 보통 첫번째 원소를 피벗으로 설정
피벗값보다 큰 값을 왼쪽부터 찾고 피벗보다 작은값을 오른쪽부터 찾는다.
피벗값보다 작은값,큰값찾으면 : 작은값의 인덱스가 큰 값의 인덱스보다 크면 값끼리자리바꿈
피벗값보다 작은값,큰값찾으면 : 작은값의 인덱스가 큰 값의 인덱스보다 작으면 피벗과 작은값 자리바꿈.

*/
#include <stdio.h>

int number = 10;
int data[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) { //원소가 한개일 경우.
		return;
	}
	int key = start; //키는 첫번째 원소
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {//엇갈릴때까지 반복
		while (data[i] <= data[key] && i<=end) { //큰값을 왼쪽부터 찾는다. 크면 빠져나옴
			i++;
		}
		while (data[j] >= data[key] && j > start) { //작은 값을 오른쪽부터 찾는다. 작으면 빠져나옴
			j--;
		}
		if (i > j) { //피벗과 작은값 바꾼다. (엇갈린경우이다)
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { //그대로 작은값이 오른쪽에 큰값이 왼쪽에 머물러있다면 둘이바꿈
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j-1); //키값 기준 왼쪽 (j자리가 곧 피벗자리가됐으니깐)
	quickSort(data, j + 1, end); //키값 기준 오른쪽
}

void show() {
	int i;
	for (i = 0; i < number; i++) {
		printf("%d", data[i]);
	}
}

int main() {
	quickSort(data, 0, number - 1);
	show();
	return 0;
}
