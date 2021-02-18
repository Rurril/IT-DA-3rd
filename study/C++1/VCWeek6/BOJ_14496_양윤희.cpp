#include<iostream>
#include<queue>
using namespace std;
int map[1001][1001];
int visit[1001];
int a, b, n, m, y, x;
queue<pair<int, int>> q;

int bfs() {
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int move = now.first;
		int cnt = now.second;
		if (move == b) {
			return cnt;
		}
		for (int i = 1; i <= n; i++) {
			if (map[move][i] == 1 && visit[i]==0) {
				visit[i] = 1;
				q.push(make_pair(i, cnt + 1));
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		map[y][x] = 1;
		map[x][y] = 1;
	}
	visit[a] = 1;
	q.push(make_pair(a,0));
	cout<< bfs();
	
}