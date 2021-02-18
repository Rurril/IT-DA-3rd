#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M, sx, dx;
vector<pair<int,int>> v[1001];
int result[1001];
bool visited[1001];

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, d, cost;
		cin >> s >> d >> cost;
		v[s].push_back({ d,cost });
	}
	cin >> sx >> dx;
	memset(result, 1000000, sizeof(result));
}
void solve(int x) {
	result[x] = 0;
	priority_queue<pair<int, int>> q; 
	q.push({ x,0 });
	while (!q.empty()) {
		int current = q.top().first;
		int distance = -q.top().second; // 길이가 짧은 것이 먼저 와야하니까 - 붙이기
		q.pop();
		if (result[current] < distance) continue; // 최단거리가 아니면 스킵
		for (int i = 0; i < v[current].size(); i++) {
			int nx = v[current][i].first;
			int nd = distance + v[current][i].second;
			if (nd < result[nx]) { // 기존의 최소비용보다 저렴하면 교체
				result[nx] = nd;
				q.push({ nx,-nd });
			}
		}
	}
}
/* 메모리 초과
void dfs(int n, int val) {
	if (n == dx) {
		result = min(val, result);
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		visited[n] = true;
		dfs(v[n][i].first, val + v[n][i].second);
		visited[n] = false;
	}
	return;
}
*/

int main(void) {
	init();
	solve(sx);
	cout << result[dx];
}
