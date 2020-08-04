/*계수정렬 counting Sort
크기를 기준으로 세는 알고리즘이다.
132432531234435123523143512111 을 정렬한다할때
12345 공간을 만들어놓고 나오는 족족 공간에 +1을 해준다.
*/

#include <stdio.h>
int main(void) {
	int count[6];
	int array[30] = { 1,3,2,3,2,5,3,1,2,3,3,5,1,2,3,5,2,3,1,3,5,1,2,1,1,1 };
	for (int i = 1; i <= 5; i++) {
		count[i] = 0; //count[0]을 굳이 0만들필요없음 1,2,3,4,5만 쓰기때문
	}
	for (int i = 0; i < 30; i++) {
		count[array[i]]++; //그에 맞는 배열만 ++해준다.
	}
	for (int i = 1; i <= 5; i++) {
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++) {
				printf("%d", i);
			}
		}
	}
	return 0;
}