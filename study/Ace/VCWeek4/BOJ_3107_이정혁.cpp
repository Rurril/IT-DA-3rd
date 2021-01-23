#include<iostream>
#include<string>
#include<vector>


using namespace std;
string s;
vector<int> col_pos;
int chk_2 = -1, col_cnt;

void init() {
	cin >> s;
}

void solve() {
	string c2;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			col_pos.emplace_back(i);
		}
	}
	for (int i = 0; i < col_pos.size() - 1; i++) {
		if (col_pos[i + 1] - col_pos[i] == 1) {
			chk_2 = col_pos[i];
		}
	}
	if (chk_2 != -1) {
		if (chk_2 == 0) {
			s.erase(0, 1);
			for (int i = col_pos.size() - 2; i < 7; i++) {
				c2.append("0000:");
			}
			c2.pop_back();
			s.insert(chk_2, c2);
		}
		else if (chk_2 == s.size() - 2) {
			for (int i = col_pos.size() - 2; i < 7; i++) {
				c2.append("0000:");
			}
			c2.pop_back();
			s.insert(chk_2 + 1, c2);
			s.pop_back();
		}
		else {
			for (int i = col_pos.size() - 1; i < 7; i++) {
				c2.append("0000:");
			}
			c2.pop_back();
			s.insert(chk_2 + 1, c2);
		}
	}
	s.push_back(':');
	int idx = 0;
	int n = 0;
	while (1) {
		if (n == 8) {
			break;
		}
		for (int i = 5 * n; i < 5 * n + 5; i++) {
			if (s[i] == ':') {
				idx = 5 * n + 4 - i;
				break;
			}
		}
		string c1;
		for (int i = 0; i < idx; i++) {
			c1.push_back('0');
		}
		s.insert(5 * n, c1);
		n++;
	}
	s.pop_back();
}

int main(void) {
	init();
	solve();
	cout << s;
	return 0;
}
