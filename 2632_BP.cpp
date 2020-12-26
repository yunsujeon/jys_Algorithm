
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000;

int N;
int a, b;
int N1[MAX];
int N2[MAX];
vector <int> pizza1;
vector <int> pizza2;
int c, c1, c2;

vector<int> hap(int arr[],int val) {
	int sum = 0;
	vector<int>ret;
	for (int i = 0; i < val; i++) {
		for (int j = i; j < i+val-1; j++) {
			sum += arr[j%val];
			ret.push_back(sum); //
		}
		sum = 0;
	}
	ret.push_back(0); //0 push
	for (int i = 0; i < val; i++) {
		sum += arr[i];
	}
	ret.push_back(sum); //전체 더한거 push
	return ret;
}

void twopointer() {
	int pointer1 = 0, pointer2 = 0;
	while (pointer1 < pizza1.size() && pointer2 < pizza2.size()) {
		c1 = 0, c2 = 0;
		int result = pizza1[pointer1] + pizza2[pointer2];
		if (result == N) {
			for (int t = pizza1[pointer1]; pointer1 < pizza1.size() && t == pizza1[pointer1]; c1++, pointer1++);
			for (int t = pizza2[pointer2]; pointer2 < pizza2.size() && t == pizza2[pointer2]; c2++, pointer2++);
			c += c1 * c2;
		}
		else if (result > N) {
			pointer2++;
		}
		else
			pointer1++;
	}
}

int main() {
	cin >> N;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> N1[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> N2[i];
	}

	pizza1 = hap(N1,a);
	pizza2 = hap(N2,b);
	//0도 더해주자 아예 포함안되는 경우도 있으니깐

	sort(pizza1.begin(), pizza1.end());
	sort(pizza2.begin(), pizza2.end(), greater<int>());

	twopointer();
	cout << c << endl;

	return 0;
}