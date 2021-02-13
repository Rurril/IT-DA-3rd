#include<iostream>
#include <queue>
using namespace std;
int map[101][101];
bool visit[101][101];
int n, m, a, b;
int res;
queue<pair<int,int>> que;
queue<pair<int, int>> path;
int bfs(int start) {
	while (!path.empty()) {

		pair<int, int> now = path.front();
		path.pop();
		int head = now.first;
		int cnt = now.second;

		for (int i = 1; i <= n;i++) {
			if (map[head][i] == 1 && !visit[start][i]) {
				res += cnt;
				visit[start][i] = true;
				path.push(make_pair(i, cnt+1));
			}
		}
	}
	return res;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 1;i <= n; i++) {
		res = 0;		
		visit[i][i] = true;
		path.push(make_pair(i,1));
		que.push(make_pair(bfs(i),i));
	}
	int min = 999;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pair<int, int> now = que.front();
		int xx = now.first;
		int yy = now.second;
		if (xx < min) {

			min = xx;
			ans = yy;
		}
		que.pop();
	}
	cout << ans;
}