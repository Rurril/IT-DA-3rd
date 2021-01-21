#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int S;
int visited[1005][1005];//화면, 클립보드

int bfs() {

	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair( 1,0), 0 ));
	visited[1][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		if (x == S) //화면에 있는 이모티콘 개수
			return t;
		if (0 < x && x < 1001) { //화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
			if (visited[x][x] == 0) {
				visited[x][x] = 1;
				q.push(make_pair(make_pair(x,x),t+1));
			}
			if (y > 0 && x + y < 1001) {
				if (visited[x + y][y] == 0) {
					visited[x + y][y] = 1;
					q.push(make_pair(make_pair(x+y, y), t + 1));
				}
			}
			if (visited[x - 1][y] == 0) {
				visited[x - 1][y] = 1;
				q.push(make_pair(make_pair(x - 1, y), t + 1));
			}

		}

	}


}


int main() {

	cin >> S;
	cout << bfs();

}