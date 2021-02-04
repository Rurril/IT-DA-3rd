#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int total;
vector<int> member[51];
bool visited[51];
int result[51];
void init() {
	cin >> total;
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == -1 && y == -1) {
			break;
		}
		member[x].push_back(y);
		member[y].push_back(x);
	}
}

void bfs(int x) {
	queue<pair<int,int>> q;
	visited[x] = true;
	q.push({ x,0 });
	while (!q.empty()) {
		pair<int,int> current = q.front();
		result[x] = current.second;
		q.pop();
		for (int i = 0; i < member[current.first].size(); i++) {
			int next = member[current.first][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, current.second + 1 });
				
			}
		}
	}
}
int main(void) {
	init();
	for (int i = 1; i <= total; i++) {
		memset(visited, false, sizeof(visited));
		bfs(i);
	}
	int minimum = 99, cnt = 0;
	for (int i = 1; i <= total; i++) {
		minimum = min(minimum, result[i]);
	}
	for (int i = 1; i <= total; i++) {
		if (result[i] == minimum) {
			cnt++;
		}
	}
	cout << minimum << ' ' << cnt << '\n';
	for (int i = 1; i <= total; i++) {
		if (result[i] == minimum) {
			cout << i << ' ';
		}
	}
	return 0;
}
