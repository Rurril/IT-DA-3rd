#include<iostream>
#include <queue>
using namespace std;
int N, K, pivot;
int arr[200001][3];
int visit[200001][3];
queue<pair<pair<int, int>, int>> q; 
bool bfs() {
	int direct[4][2] = {
1,0, //아래
K,-1,//왼
-1,0,//위
K,1  //오른
	};
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		int y = p.first;
		int x = p.second;
		int time = q.front().second;
		q.pop();
		if (time >= N) return false;

		for (int i = 0;i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];		
			if (ny >= N && nx>=0 && nx<2 )return true;
			if (arr[ny][nx] == 0 || ny < time || nx < 0 || nx > 1 || visit[ny][nx]== 1 || ny>0) {
				continue;
			}
			visit[ny][nx] = 1;
			q.push(make_pair(make_pair(ny, nx), time+1));
		}
	}
	return false;
}
int main (void) {
	cin >> N >> K;
	for(int j=0; j<2; j++){
		for (int i = 0; i < N; i++) {
			char k;
			cin >> k;
			arr[i][j] = k - '0';
		}
	}
	visit[0][0] = 1;
	q.push(make_pair(make_pair(0, 0),0));
	if (bfs()) cout << 1;
	else cout << 0;
}