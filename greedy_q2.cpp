/*2437 저울
N개의 저울추가 주어졌을 때 이 추들을 사용해 측정할 수 없는 양의 정수 무게 중에서 최소값을 구하는 프로그램
- 단순히 저울추들을 정렬한 뒤에 하나씩 더해나가면서 빈공간이 있는지 확인하기
입력)
7 //갯수
3 1 6 2 7 30 1
출력)
21
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int number;
	int a[1001];
	int sum = 1;
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin>>a[i];
	}
	sort(a,a+number);
	for (int i = 0; i < number; i++) {
		if (sum < a[i])
			break;
		sum += a[i];
	}
	cout << sum;
	return 0;
}
*/

/*1783 병든 나이트
나이트가 N*M크기 체스판의 가장 왼쪽아래칸에 위치해있다. 4가지 방향으로만 움직일 수 있다.
1. 2칸위로, 1칸 오른쪽
2. 1칸위로, 2칸 오른쪽
3. 1칸 아래로, 2칸 오른쪽
4. 2칸 아래로, 1칸 오른쪽
방문하는 칸의 횟수를 최대로 하려고 한다. 총 이동횟수가 4번보다 적지않다면 이동방법을 
모두 한번씩 사용해아한다. 방문한칸이 5개 미만이면 이동방법에 제약이 없다.
방문할 수 있는 칸의 최대갯수는?
입력 ) 100 50 (N*M)
출력 ) 48
예시 - 높이가 1이면 움직일 수 없어서 1을 그대로 출력하면 된다.
높이가 2라면 오른쪽으로 두칸씩만 움직일 수 있으니깐 2로 나눠서 출력한다.
높이가 3이면 제약은 없다.
*/
/*
#include <iostream>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	if (n == 1)
		cout << '1';
	else if (n == 2) {
		if ((m + 1) / 2 > 4) //m이 8이상이게되면 이동횟수가 4번 이상이다.
			cout << 4; //그래서 이동방법에 제약이 생겨 최대 방문갯수는 4로 고정
		else // 그 이하의 크기일때는
			cout << (m + 1) / 2; //높이가 2일때 m을 2로나누면 방문한 갯수가 될 것이다.

	}
	else { //이외에는 제약이 없다.
		if (m >= 7) // m이 7보다 크면 (무조건 한번씩은 써야됨)
			cout << m - 2; //방문한 칸의 갯수는 -2만큼이 될것
		else //m이 그 이하이면
			cout << min(m, 4); //(4와 그 이하의 m 중 하나)
	}
}
*/

/*
1969번 DNA
해밍거리가 최소화 되는 문자열을 구하는 문제
AGCAT"와 ”GGAAT"는 첫 번째 글자와 세 번째 글자가 다르므로 Hamming Distance는 2
우리가 할 일은 다음과 같다. n개의 길이가 같은 DNA가 주어져 있을 때(이 DNA를 a1a2a3a4...이라고 하자)
Hamming Distance의 합이 가장 작은 DNA s를 구하는 것이다. 
즉, s와 a1의 Hamming Distance + s와 a2의 Hamming Distance + s와 a3의 Hamming Distance ... 의 합이 최소가 된다는 의미이다.
입력) 5 8		DNA의 수 5개, 문자열의 길이 8개
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
출력
TAAGATAC	해밍거리의 합이 가장 작은 DNA를 출력
7	해밍거리의 합
따라서 모든 문자열을 순서대로 읽으면서 가장 많이 등장한 문자들을 결과문자열에 저장하면 된다.
*/
/*
#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

string a[MAX];
int n, m;//DNA의 개수와 문자열의 길이
string res;
int cnt=0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) { //문자열 입력을 다받는다.
		cin >> a[i];  // 다섯개라면 a[0] a[1] a[2] a[3] a[4] 생겼을것 각각에는 8개들어갔을것
	}
	for (int j = 0; j < m; j++) { //문자열 길이만큼 반복한다.
		sort(a, a + n); //A있는게 앞으로 오게정렬
		//이거때문에 헷갈렸었음
		//AGCGA
		//TGAGT 이렇게 있으면 A와 T를 sort 하고 다음번 for문에서는 G와 G 그 다음번에선 C와 A를 sort 한다.
		int i = 0, counts[4] = { 0, };
		while (i < n && a[i][j] == 'A') { //정렬한것에서 A를 다뽑아낸다. j를 두고 i만 늘려나간다.
			counts[0]++; i++;
		}
		while (i<n && a[i][j] == 'C') {
			counts[1]++; i++;
		}
		while ( i < n && a[i][j] == 'G' ) { //while문에 &&로 건것은 앞에꺼가 먼저 걸리고 뒤에조건을 본다.
			counts[2]++; i++;
		}
		while (i < n && a[i][j] == 'T') {
			counts[3]++; i++; //i를 증가시켜 배열이 들어있지 않은곳을 비교하면 에러뜬다.
		}
		int index = 0, min = 2100000000;
		for (int i = 0; i < 4; i++) { //알파벳숫자만큼
			if (min > n - counts[i]) {
				index = i;
				min = n - counts[i]; //그 외에는 다 해밍거리이다.
			}
		}
		if (index == 0)
			res += 'A'; //result문자열에 A를 더해준다.
		if (index == 1)
			res += 'C';
		if (index == 2)
			res += 'G';
		if (index == 3)
			res += 'T';
		cnt += min; //해밍거리들을 더해준다.
		for (i = 0; i < n; i++) {
			a[i][j] = '0';
		}
	}

	cout << res << '\n' << cnt << '\n';
	return 0;
}
*/

/*2812
크게만들기
N자리 숫자가 주어졌을때 여기서 숫자 K개를 지워서 얻을수있는 가장 큰 수를 구하는
프로그램을 작성하시오
입력)
4 2		N K
1924	N자리숫자
출력)
94
단순히 앞에서부터 숫자를 읽어가며 스택에 넣으면 된다. 다만 새롭게 등장한 뒤에 있는
숫자보다 작은숫자들을 모두 스택에서 빼서 스택에는 오직 큰 숫자들만 넣어주면된다.
스택에 다 넣은 뒤에도 지워야 하는 숫자가 남아있는 경우, 이미 내림차순이 된 것이므로
뒤에서부터 뽑으면 된다.
*/
//주의사항!!!!! 지우기만하고 문자열을 섞을수는 없다!!!!!!!!!!!!! 이거때매 한참고민함
#include <iostream>
#include <vector>

using namespace std;

int n, k;
string a;
vector<char> result;

int main() {
	cin >> n >> k >> a; // N자리 숫자, K개를 지우는 것 a숫자
	int i = 0;
	while (i != a.size()) {
		while (k != 0 && !result.empty() && result.back() < a[i]) {
			result.pop_back(); //들어간 값이 있던값보다 작으면 있던값을 result에서 꺼낸다.
			k--; //k개만 지우면 되므로 -> 근데 이게 어떻게 젤 작은 숫자만 지운거라고 보장하지?
		}
		result.push_back(a[i]); //result에 넣는다.
		i++;
	}
	while (k--) {
		result.pop_back(); //pop_back으로 꺼내지않고 담겨있는 그대로 0부터 출력한거
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}

