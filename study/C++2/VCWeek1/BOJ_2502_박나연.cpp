#include<iostream>
using namespace std;
int F[35];
int S[35];

int main() {

	int D, K;

	cin >> D >> K;
	F[1] = 1;
	F[2] = 0;
	S[1] = 0;
	S[2] = 1;

	for (int i = 3; i <= 30; i++) {
		F[i] = F[i - 2] + F[i - 1];
		S[i] = S[i - 2] + S[i - 1];

	}

	int a = F[D];
	int b = S[D];

	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (K == (a * i) + (b * j)) {
				cout << i << endl;
				cout << j << endl;
				return 0;
			}
		}
	}
}
//3: x + y, 4 : y+x+y = x + 2y, 