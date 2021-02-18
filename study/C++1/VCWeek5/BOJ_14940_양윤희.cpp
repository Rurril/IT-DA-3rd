#include<iostream>
#include<queue>
using namespace std;
int direct[4][2] = { 1,0,0,-1,-1,0,0,1 }; //위 왼 아래 오른
int map[1001][1001];
int n, m, y, x, obj;
int dist[1001][1001];
bool visit[1001][1001];

queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int yy = now.first;
		int xx = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = yy + direct[i][0];
			int nx = xx + direct[i][1];
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue; //범위 제한
			if (map[ny][nx] == 0)continue; //0인 곳은 아예 방문x
			if (visit[ny][nx] == 0) { //방문하지 않은 영역이면
					dist[ny][nx] = dist[yy][xx] + 1; //이전 거리에 +1
					visit[ny][nx] = true; //방문처리
					q.push(make_pair(ny, nx));
			}
		}
	}
}
void check() { //방문하지 않은 곳 중에 0이 아닌 곳 -1로 만들기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && map[i][j]!=0) {
				dist[i][j] = -1;
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> obj;
			if (obj == 2) { //2의 위치 저장
				y = i; x = j;
			}
			map[i][j] = obj;
		}
	}
	q.push(make_pair(y,x));

	visit[y][x] = 1;
	bfs();
	check();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}