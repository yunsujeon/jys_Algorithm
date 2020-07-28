/*삽입정렬 O(N^2) but 거의 정렬되어있을때는 빠르다.
1,10,5,8,7,6,4,3,2,9를 오름차순으로 정렬하시오
각 숫자를 필요할 때만 적절한 위치에 삽입하는 방법
*/
#include <stdio.h>
int main() {
	int array[] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, temp;

	for (i = 0; i < 9; i++) { //바로 뛰어넘을 수 있는게 아니고 한번씩은 거쳐가야됨
		j = i; 
		while (j >= 0 && array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--; //앞단으로 가게 해주는 역할/ 과연 앞에꺼보다 작을까 느낌
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}