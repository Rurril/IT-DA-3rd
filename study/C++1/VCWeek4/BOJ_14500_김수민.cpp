#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int g[501][501];
int ma[4] = { 1,-1,0,0 };
int mb[4] = { 0,0,-1,1 };
bool visited[501][501];
int result = 0, realresult = 0;


void dfs(int cnt, int a, int b) { //테트로미노 dfs돌며 최대값 갱신
	int newa, newb;
	if (cnt == 0) {
		realresult = max(result, realresult);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		newa = a + ma[i];
		newb = b + mb[i];
		if ((newa >= 0) && (newa < N) && (newb >= 0) && (newb < M) && (visited[newa][newb] == false)) {
			visited[newa][newb] = true;
			result += g[newa][newb];
			dfs(cnt - 1, newa, newb);
			result -= g[newa][newb];
			visited[newa][newb] = false;
		}
	}
}
void fuck(int a, int b) { //dfs로 안구해지는 ㅗ모양
	if ((a + 1 < N) && (b >= 1) && (b + 1 < M)) { //ㅗ
		realresult = max(realresult, g[a][b] + g[a + 1][b - 1] + g[a + 1][b] + g[a + 1][b + 1]);

	}
	if ((a + 2 < N) && (b + 1 < M)) { //ㅓ
		realresult = max(realresult, g[a][b] + g[a + 1][b] + g[a + 1][b + 1] + g[a + 2][b]);
	}
	if ((a+2<N)&&(b<M)&&(b-1>=0)){//ㅓ
		realresult = max(realresult, g[a][b] + g[a + 1][b] + g[a + 1][b - 1] + g[a + 2][b]);
	}
	if ((a + 1 < N) && (b + 2 < M)) { //ㅜ
		realresult = max(realresult, g[a][b] + g[a][b+1] + g[a][b + 2] + g[a + 1][b+1]);
	}
}
int main()
{
	cin >> N >> M ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
				visited[i][j] = true;
				result += g[i][j];
				dfs(3, i, j);
				result -= g[i][j];
				fuck(i, j);
				visited[i][j] = false;
		}
	}
	cout << realresult;
}
