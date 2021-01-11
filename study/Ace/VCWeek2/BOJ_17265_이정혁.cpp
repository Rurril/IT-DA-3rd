#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, maximum = -987654321; int minimum = 987654321;
char N[5][5];
string s13;
// * = 42, + = 43 , - = 45
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> N[i][j];
		}
	}
}

int calcul(string s,int cnt) {
	int n1 = s[0] - 48;
	int n2 = s[2] - 48;
	if (cnt == 3) {
		int n3;
		if (s[1] == '*') {
			n3 = n1 * n2;
		}
		if (s[1] == '+') {
			n3 = n1 + n2;
		}
		if (s[1] == '-') {
			n3 = n1 - n2;
		}
		int n4 = s[4] - 48;
		if (s[3] == '*') {
			return n3 * n4;
		}
		if (s[3] == '+') {
			return n3 + n4;
		}
		if (s[3] == '-') {
			return n3 - n4;
		}
	}
	if (cnt == 4) {
		int n3;
		if (s[1] == '*') {
			n3 = n1 * n2;
		}
		if (s[1] == '+') {
			n3 = n1 + n2;
		}
		if (s[1] == '-') {
			n3 = n1 - n2;
		}
		int n4 = s[4] - 48;
		int n5;
		if (s[3] == '*') {
			n5 = n3 * n4;
		}
		if (s[3] == '+') {
			n5 = n3 + n4;
		}
		if (s[3] == '-') {
			n5 = n3 - n4;
		}
		int n6 = s[6] - 48;
		if (s[5] == '*') {
			return n5 * n6;
		}
		if (s[5] == '+') {
			return n5 + n6;
		}
		if (s[5] == '-') {
			return n5 - n6;
		}
	}
	if (cnt == 5) {
		int n3;
		if (s[1] == '*') {
			n3 = n1 * n2;
		}
		if (s[1] == '+') {
			n3 = n1 + n2;
		}
		if (s[1] == '-') {
			n3 = n1 - n2;
		}
		int n4 = s[4] - 48;
		int n5;
		if (s[3] == '*') {
			n5 = n3 * n4;
		}
		if (s[3] == '+') {
			n5 = n3 + n4;
		}
		if (s[3] == '-') {
			n5 = n3 - n4;
		}
		int n6 = s[6] - 48;
		int n7;
		if (s[5] == '*') {
			n7 = n5 * n6;
		}
		if (s[5] == '+') {
			n7 = n5 + n6;
		}
		if (s[5] == '-') {
			n7 = n5 - n6;
		}
		int n8 = s[8] - 48;
		if (s[7] == '*') {
			return n7 * n8;
		}
		if (s[7] == '+') {
			return n7 + n8;
		}
		if (s[7] == '-') {
			return n7 - n8;
		}
	}
}
void dfs(int x, int y, string s) {
	if (x >= n || y >= n) {
		return;
	}
	if (x == n - 1 && y == n - 1) {
		maximum = max(maximum, calcul(s, n));
		minimum = min(minimum, calcul(s, n));
		return;
	}
	
	string s1 = s;
	string s2 = s;
	s1.push_back(N[x + 1][y]);
	s2.push_back(N[x][y + 1]);
	dfs(x + 1, y, s1);
	dfs(x, y + 1, s2);
}
int main(void) {
	init();
	s13.push_back(N[0][0]);
	dfs(0, 0, s13);
	cout << maximum << ' ' << minimum;
	return 0;
}
