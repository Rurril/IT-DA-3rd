#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

char arr[13][7];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visited[13][7];
int change,result;
bool boom;
queue<pair<int, int>> q;


// 1. 밑에 . 이 있다면 아래로 한칸씩 이동
// 2. 같은 모양이 4개 이상 붙어 있다면 전부 . 으로 변환 이때 cnt ++;
// 3. 다시 밑에 . 이 있다면 밑으로 이동. 다시 4개 이상인거 전부 . 으로 변환 cnt++;
void down() {
	change = 0;
	for (int i = 1; i <= 6; i++) {
		vector <pair<int, int>> v;
		int cnt = 0;
		int cx,cy;
		for (int j = 1; j <= 12; j++) {
			if (arr[j][i] == '.') continue;
			v.push_back({ j,i });
		}
		int x = 12;
		if (v.size() > 0) {
			for (int k = v.size() - 1; k >= 0; k--) {
				if (arr[x][i] == arr[v[k].first][i]) {
					x--;
					continue;
				}
				arr[x][i] = arr[v[k].first][i];
				arr[v[k].first][i] = '.';
				x--;
				change++;
				
			}
		}
	}
}
void bfs(int x, int y) {
	vector<pair<int, int>> deleted;
	int cnt = 0;
	visited[x][y] = true;
	char color = arr[x][y];
	q.push({ x,y });
	while(!q.empty()){
		pair<int, int> current = q.front();
		deleted.push_back({ current.first,current.second });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + movement[i][0];
			int ny = current.second + movement[i][1];
			if (nx >= 1 && ny >= 1 && nx <= 12 && ny <= 6 && visited[nx][ny] == false) {
				if (arr[nx][ny] == color) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (deleted.size() >= 4) {
		while (!deleted.empty()) {
			arr[deleted.back().first][deleted.back().second] = '.';
			deleted.pop_back();
			boom = true;
		}
	}
}
int main(void) {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		boom = false;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				if (arr[i][j] == '.') continue;
				else {
					bfs(i, j);
				}
			}
		}
		down();
		if (boom == false) {
			cout << result;
			return 0;
		}
		result++;
		if (change == 0) {
			break;
		}
		
	}
	cout << result;
	return 0;
}
