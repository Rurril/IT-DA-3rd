#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> start;
vector<string> dept;
int N, result;
bool visited[1001];
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		start.push_back(s);
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		dept.push_back(s);
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (start[i] == dept[j]) {
				visited[j] = true;
				break;
			}
			if (visited[j]) {
				continue;
			}
			visited[j] = true;
			cnt++;
		}
		result += cnt;
	}
}
int main(void) {
	init();
	solve();
	cout << result;
	return 0;
}
