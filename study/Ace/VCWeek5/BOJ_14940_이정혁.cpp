#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[1001][1001];
int n, m, sx, sy;
int result[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
int movement[4][2] = { {0,1},{1,0}, {0,-1},{-1,0} };

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	}
}

void bfs(int x, int y, int len) {
	pair<int, int> current;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + movement[i][0];
			int ny = current.second + movement[i][1];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && !visited[nx][ny] && arr[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				result[nx][ny] = result[current.first][current.second] + 1;
			}
		}
	}
}
int main(void) {
	init();
	bfs(sx, sy, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (result[i][j] == 0 && arr[i][j] == 1) {
				result[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
