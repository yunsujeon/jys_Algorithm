/*
//기본사용법
#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}

//내림차순으로 정렬하기
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b) { //왼쪽이 오른쪽에 비해서 를 기준으로 삼는다. 왼쪽이 있는 것이 더 클 수 있도록 정렬하겠다.
	return a > b;
}
int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10,compare);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}
*/
//데이터를 묶어서 정렬하기
#include <iostream>
#include <algorithm>
using namespace std;
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {//생성자 만든다. (즉 초기화)
		this->name = name;
		this->score = score;
	}
	//정렬기준을 정해준다.
	bool operator < (Student& student) { //함수 (다른학생과비교할때)
		return this->score < student.score; //기준 (내점수가 더 낮다면 우선순위가높다)
	}
}; //클래스 생성완료
/*
bool compare(Student a, Student b) {
	return(a.score < b.score);
}*/
int main() {
	Student students[] = {
		Student("A",35),
		Student("B",24),
		Student("C",45),
		Student("D",12),
		Student("E",72)
	};
	//sort(students, students + 5, compare);
	sort(students, students + 5);

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}