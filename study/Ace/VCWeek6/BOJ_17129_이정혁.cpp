#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, sx, sy, result;
char arr[3001][3001];
int arr2[3001][3001];
bool visited[3001][3001];
int movement[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j] - 48;
			if (arr2[i][j] == 2) {
				sx = i; sy = j;
			}
			if (arr2[i][j] == 1) {
				visited[i][j] = true;
			}
		}
	}
}

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sx,sy}, 0 });
	visited[sx][sy] = true;
	while (!q.empty()) {
		pair < pair<int, int>, int> current = q.front();
		if (arr2[current.first.first][current.first.second] == 3 || arr2[current.first.first][current.first.second] == 4 || arr2[current.first.first][current.first.second] == 5) {
			result = current.second ;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first.first + movement[i][0];
			int ny = current.first.second + movement[i][1];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && !visited[nx][ny]) {
				if (arr2[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ {nx,ny}, current.second + 1 });
				}
				else {
					visited[nx][ny] = true;
					q.push({ {nx,ny}, current.second + 1 });
					
				}
			}
		}
	}
}
int main(void) {
	init();
	bfs();
	if (result == 0) {
		cout << "NIE" << '\n';
		return 0;
	}
	else {
		cout << "TAK" << '\n';
		cout << result;
	}
	return 0;
}
