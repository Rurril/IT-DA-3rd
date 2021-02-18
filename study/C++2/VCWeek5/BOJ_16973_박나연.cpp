#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int H, W, sr, sc, fr, fc;
int map[1005][1005];
int visited[1005][1005];
int dx[] = { 0, 0, 1, -1 };//³² ºÏ µ¿ ¼­
int dy[] = { 1, -1, 0, 0 };
int result = 99999999;
int isW = 0;


void bfs() {

	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(sr, sc),0));
	visited[sr][sc] = 1;

	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		if (x == fr && y == fc) {
			if (result > z)
				result = z;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny + fc - 1 <= M && ny >= 1 && nx + fr - 1 <= N) {
				if (visited[nx][ny] == 0) {
					for (int j = nx; j <= nx + fc - 1; j++) {
						for (int k = ny; k <= ny + fr - 1; k++) {
							if (map[j][k] == 1)
								isW = 1;
						}
					}
					if (isW == 0) {
						cout << z << endl;
						q.push(make_pair(make_pair(nx, ny),z+1));
						visited[nx][ny] = 1;	
					}
				}
			}
		}
	}


}


int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> H >> W >> sr >> sc >> fr >> fc;

	bfs();
	cout << result << endl;
	

}