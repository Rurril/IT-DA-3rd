#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
string S;
string T;
int N;
vector <string> v;

void change(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	char c;
	int cindex;
	cin >> S;

	T = S;
	N = S.size();
	sort(T.begin(), T.end());
	c = T.front();
	for (int i = 0; i < N; i++) {
		if (c == S[i]) {
			cindex = i;
		}
	}
	for (int j = 1; j < cindex; j++) {
		if (S[0] < S[j]) {
			if ((cindex - j) % 2 == 0) {
				continue;
			}
			else {
				for (int i = 0; i < j; i++) { //바꾸기
					change(&S[i], &S[j - i]);
				}
			}
		}
		else {
			if ((cindex - j) % 2 == 0) {
				for (int i = 0; i < j; i++) { //바꾸기
					change(&S[i], &S[j - i]);
				}
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i <= cindex/2; i++) { //바꾸기
		change(&S[i], &S[cindex - i]);
	}
	cout << S;
}


