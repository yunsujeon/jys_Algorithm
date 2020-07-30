#define _CRT_SECURE_NO_WARNINGS

//기초 정렬 문제 풀어보기
// 백준 2752번 세수정렬 - 숫자 세개 입력받은 후 오름차순정렬
/*
#include <stdio.h>
int main() {
	int a[3]; //크기가 4인배열 - 0,1,2,3까지있다.
	int temp;
	printf("숫자 세 개를 입력해주세요\n");
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	//bubble_sort로 풀어보자. 맨 뒤부터 정렬될것.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2-i; j++) { //젤 중요한부분
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

//백준 2750번 - 수 정렬하기 N개의 숫자를 오름차순 정렬 
#define MAX 1001
#include <stdio.h>
int main() {
	int a[MAX] = {};
	int number;
	int temp;
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &a[i]);
	}
	//insertion_sort를 이용해보자. (거의 정렬되어있을 때 빠르다)
	//하나씩 올라가면서 그 잡은 숫자를 앞의 숫자들과 비교하는것.
	for (int i = 0; i < number - 1; i++) { //하나씩 거쳐가면서 but맨마지막 X
		int j = i;
		while (a[j]>a[j+1]) {//계속 반복하며 바꿔준다. j--로 내리면서
			temp = a[j + 1]; 
			a[j + 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
	for (int i = 0; i < number; i++)
	{
		printf("%d\n",a[i]);
	}
}


//100만개 정렬 O(N*logN)으로 풀어야 된다. 따라서 quickSort 사용한다.
#include <stdio.h>
int number, data[1000001];

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1, j = end, temp;
	while (i <= j) {//엇갈릴때까지 반복
		while (data[i] <= data[key]) //키보다 큰 값을 만날때까지
			i++; //만나기 전까지는 계속 ++해준다.
		while (data[j] >= data[key] && j > start) {
			j--;
		}
		if (i > j) {//엇갈린다면 피벗과바꾼다.
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { //아니면 둘이바꾼다.
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	quickSort(data, 0, number-1);
	for (int i = 0; i < number; i++) {
		printf("%d", data[i]);
	}
	return 0;
}
*/

