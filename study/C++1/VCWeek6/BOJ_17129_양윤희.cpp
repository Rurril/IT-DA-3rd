#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int map[3001][3001];
int visit[3001][3001];
int direct[4][2] = { 1,0,0,-1,-1,0,0,1 };//위왼아래오른
int n, m, y, x, tmp, ans = 999;

queue<pair<int,int>> q;
queue<int> cnt;
void bfs() {
	while (!q.empty()) {
		pair<int, int>now = q.front();
		int yy = now.first;
		int xx = now.second;
		int count = cnt.front();
		q.pop();
		cnt.pop();
		if (map[yy][xx] > 2) {
			ans = count;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = yy + direct[i][0];
			int nx = xx + direct[i][1];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && visit[ny][nx] == 0 && map[ny][nx] != 1) {
				visit[ny][nx] = 1;
				q.push(make_pair(ny,nx));
				cnt.push(count+1);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for(int j=0;j<m;j++){
			map[i][j] = input.at(j) - '0';
			if (map[i][j] == 2) { y = i;x = j; }
		}
	}
	q.push(make_pair(y,x));
	cnt.push(0);
	bfs();
	if (ans == 999) {
		cout << "NIE";
	}
	else {
		cout << "TAK" << endl;
		cout << ans;
	}
}