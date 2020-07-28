/* 선택정렬 개념 O(N^2)
1 10 5 8 7 6 4 3 2 9 다음 숫자들을 오름차순으로 정렬하는
프로그램을 작성하시오 */

#include <stdio.h>
int main(void) {
	int i, j, min, index, temp;
	int array[10] = { 1,10, 5, 8, 7, 6, 4, 3, 2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999; //9999보다 큰 값은 array 내에 없으므로
		for (j = i; j < 10; j++) {//작은값 찾아서 맨 앞에 두겠다
			if (min > array[j]) {
				min = array[j]; //min값 기록
				index = j; //최소일때의 j값을 index에 담아놓음
			}
		}
		temp = array[i]; //array[i]에 최소값인 array[index]즉 array[j]의 값을 넣어준다.
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]); //전체 출력
	}
	return 0;
}