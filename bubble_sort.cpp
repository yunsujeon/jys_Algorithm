/*버블정렬 O(N^2)
1 10 5 8 7 6 4 3 2 9 이 숫자들을 오름차순으로 정렬하라
바로 가까이에 있는 두 숫자끼리 비교해서 당장 더 작은 숫자를 앞으로 보내줌*/

#include <stdio.h>

int main() {
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	int temp,i,j;
	for (i = 0; i < 10; i++) { //10번 훑어봐야됨
		j = 0;
		for (j = 0; j < 9 - i; j++) { //훑는 범위
			if (array[j] > array[j + 1]) { // 바로뒤와 바꿔준다.
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}