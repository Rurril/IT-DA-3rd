#include<iostream>
#include <queue>
using namespace std;
int N, K, pivot, time;
int arr[100001][2];
queue<pair<int, int>> q; 

bool bfs() {
	int direct[4][2] = {
1,0, //아래
K,-1,//왼
-1,0,//위
K,1  //오른
	};
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int y = p.first;
		int x = p.second;
		q.pop();
		for (int i = 0;i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];		
			if (ny >= N)return true;
			if (arr[ny][nx] == 0 || ny < time || nx < 0 || nx > 1) {
				continue;
			}
			q.push(make_pair(ny, nx));
		}
		time++;
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
	q.push(make_pair(0, 0));
	if (bfs()) cout << 1;
	else cout << 0;
}