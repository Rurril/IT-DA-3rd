#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[105][105];
int dist[105][105];
int people[105];

int N, M;
int result = 0;

void bfs() {

	

	//플로이드 와샬
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i == j)
					continue;
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			people[i] += map[i][j];
		}
	}

}




int main() {

	cin >> N >> M;
	int x, y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 99999999;
			if (i == j)
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	bfs();

	for (int i = 0; i < N; i++) {
		if (result > people[i])
			result = people[i];
	}

	cout << result << endl;

}