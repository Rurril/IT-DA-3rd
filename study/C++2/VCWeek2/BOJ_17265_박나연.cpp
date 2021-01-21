#include<iostream>
#include<algorithm>
using namespace std;

char map[6][6];
int  big[6][6];
int small[6][6];

int operation(int a, int b, char c) {
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else
		return a * b;
}


int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	small[1][1] = big[1][1] = map[1][1] - '0';

	for (int i = 2; i <= N; i++) {
		if (map[i][1] == '+' || map[i][1] == '-' || map[i][1] == '*')
		{
			big[i][1] = big[i - 1][1];
			small[i][1] = small[i - 1][1];
			continue;
		}
		else {
			if (map[i - 1][1] == '+') {
				big[i][1] = big[i - 1][1] + (map[i][1]-'0');
				small[i][1] = big[i][1];
			}
			if (map[i - 1][1] == '-') {
				big[i][1] = big[i - 1][1] - (map[i][1] - '0');
				small[i][1] = big[i][1];
			}
			if (map[i - 1][1] == '*') {
				big[i][1] = big[i - 1][1] * (map[i][1] - '0');
				small[i][1] = big[i][1];
			}
		}
	}

	

	for (int i = 2; i <= N; i++) {
		if (map[i][1] == '+' || map[i][1] == '-' || map[i][1] == '*')
		{
			big[1][i] = big[1][i-1];
			small[1][i] = small[1][i-1];
			continue;
		}
		else {
			if (map[1][i-1] == '+') {
				big[1][i] = big[1][i-1] + (map[1][i] - '0');
				small[1][i] = big[1][i];
			}
			if (map[1][i-1] == '-') {
				big[1][i] = big[1][i - 1] - (map[1][i] - '0');
				small[1][i] = big[1][i];
			}
			if (map[1][i-1] == '*') {
				big[1][i] = big[1][i - 1] * (map[1][i] - '0');
				small[1][i] = big[1][i];
			}
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << big[i][j];
		}
		cout << endl;
	}*/

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (map[i][j] == '+' || map[i][j] == '-' || map[i][j] == '*')
			{
				big[i][j] = max(big[i - 1][j], big[i][j - 1]);
				small[i][j] = min(small[i - 1][j], small[i][j - 1]);
			}
			else {
				big[i][j] = max(operation(big[i - 1][j], map[i][j] - '0', map[i - 1][j]), operation(big[i][j - 1], map[i][j] - '0', map[i][j - 1]));
				small[i][j] = min(operation(small[i - 1][j], map[i][j] - '0', map[i - 1][j]), operation(small[i][j - 1], map[i][j] - '0', map[i][j - 1]));
			}
		}
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << big[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << big[N][N] <<endl<< small[N][N] << endl;




}