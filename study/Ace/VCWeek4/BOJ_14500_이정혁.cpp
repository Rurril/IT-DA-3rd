#include<iostream>
#include<algorithm>

using namespace std;

int N, M, answer;
int arr[502][502];
bool visited[502][502];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int x, int y, int cnt, int result) {
	if (cnt == 4) {
		answer = max(answer, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];
		if (!visited[nx][ny] && nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, result + arr[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}
void dfs2(int x, int y) {
	int result1,result2,result3,result4;
	result1 = arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y - 1];
	result2 = arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y + 1];
	result3 = arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x - 1][y];
	result4 = arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y];
	result1 = max(result1, result2);
	result3 = max(result3, result4);
	result1 = max(result1, result3);
	answer = max(result1, answer);
}
int main(void) {
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, arr[i][j]);
			visited[i][j] = false;
			dfs2(i, j);
		}
	}
	cout << answer;
	return 0;
}
