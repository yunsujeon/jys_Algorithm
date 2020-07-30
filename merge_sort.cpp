/*병합정렬 O(N*logN)보장
76584591 을 오름차순으로 정렬하시오
일단 정확히 반으로 나누고 나중에 합쳐서 정렬하기*/

#define number 8
#include<stdio.h>
int size;
int sorted[8];
int count = 0;

void merge(int a[], int m, int middle, int n) { //합칠 때 숫자를 비교하여 합치는 부분
	int i = m; //첫번째 배열의 맨 앞
	int j = middle + 1; //두번째 배열의 맨 앞
	int k = m; //합쳐질 배열의 맨 앞

	while (i <= middle && j <= n) { //범위를 넘지않는선에서
		if (a[i] <= a[j]) {
			sorted[k] = a[i]; //합쳐질 배열 저장공간 sorted
			i++; //i를 다음칸으로 옮긴다.
		}
		else {
			sorted[k] = a[j]; //sorted에 j값넣는다.
			j++; //j도 다음칸으로 옮긴다.
		}
		k++; //k를 증가하면서 sorted배열을 완성해나가는거
	}
	//남은 데이터들도 삽입 (한쪽만 다 비었다면=범위넘었다면)
	if (i > middle) { //i가 초과라면 j를 넣어줘야겠지
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else { //j가 초과라면 i를 넣어줘야겠지
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열을 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t]; //sorted만들고 a배열 도출
	}
}

void mergeSort(int a[],int m,int n) { //정렬하는 부분
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n); //정렬한 후 merge를 수행한다.
		//어떻게 sort를 수행하나면 끝까지 mergeSort로 쪼개면
		//merge 부분에서 하나 : 하나 를 비교하게 됨
		//a[i] <= a[j] 를 따지기 때문에 sort가 된다.
	}
}

int main() {
	int array[number] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d", array[i]);
	}
}