#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int a, b;
int N, M;
int str[10005][10005];
int visited[10005];
int result = -1;

void bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(a, 0));
	visited[a] = 1;
	


	while (!q.empty()) {
		int at = q.front().first;
		int bt = q.front().second; //치환 개수
		q.pop();

		if (at == b)
		{
			result = bt;
			break;
		}

		for (int i = 1; i <= N; i++) {
			int n = str[at][i];
				if(visited[i] == 0 && n == 1) {
					q.push(make_pair(i, bt + 1));
					visited[i] = 1;
				}
		}



	}

	cout << result << endl;
}

int main() {

	cin >> a >> b;
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		str[x][y] = 1;
		str[y][x] = 1;
	}

	bfs();
}