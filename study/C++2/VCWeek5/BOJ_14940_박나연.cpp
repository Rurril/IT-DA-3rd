#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int map[1005][1005];
int result[1005][1005];


int dx[] = { 0, 0, 1, -1 };//남 북 동 서
int dy[] = { 1, -1, 0, 0 };

void bfs(int nn, int mm) {//세로 가로
	
	result[nn][mm] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(nn, mm));
	
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; //세로
			int ny = y + dy[i]; //가로
			if (nx >= 0 && nx < n && ny >= 0&& ny < m) {
				if (map[nx][ny] == 1) {
					if (result[nx][ny] > result[x][y] + 1) {
						result[nx][ny] = result[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
					
				}
			}
		}

	}

	result[nn][mm] = 0;

}


int main() {

	cin >> n >> m;
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = 999999999;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}

	bfs(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && result[i][j] == 999999999) {
				cout << "-1" << ' ';
			}
			else if (map[i][j] == 0 && result[i][j] == 999999999) {
				cout << "0 ";
			}
			else { cout << result[i][j] << ' '; }
		}
		cout << endl;
	}

}