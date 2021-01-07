#include <iostream>
#include <queue>
using namespace std;

int N, M,result;
int g[8][8];
int tempg[8][8];
bool visited[8][8];
queue <pair<int, int>> q;
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,-1,1 };
int cnt = 3;
void find() {
	int a, b, nexta, nextb,safezone=0;
	queue <pair<int, int>> tempq=q;
	int tempg[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tempg[i][j] = g[i][j];
		}
	}
	while(!tempq.empty()) {
		a = tempq.front().first;
		b = tempq.front().second;
		tempq.pop();
		
		for (int i = 0; i < 4; i++) {
			nexta = a + x[i];
			nextb = b + y[i];
			if (nexta >= 0 && nexta < N && nextb >= 0 && nextb < M) {
				if (tempg[nexta][nextb] == 0) {
					tempg[nexta][nextb] = 2;
					tempq.push({ nexta,nextb });
				}
			}
		}
		

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempg[i][j] == 0) {
				safezone++;
			}
		}
	}
	result = max(safezone, result);
}

void dfs(int cnt) {
	if (cnt == 0) {
		find();
		return;
	}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (g[i][j] == 0) {
					g[i][j] = 1;
					dfs(cnt - 1);
					g[i][j] = 0;
				}

			}
		}
}

int main()
{
	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M;j++) {
			cin >> g[i][j];
			if (g[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	dfs(3);
    cout << result<<"\n";
}
