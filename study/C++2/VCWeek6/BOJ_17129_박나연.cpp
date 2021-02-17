#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
string A[3005];
int visited[3005][3005] = {0,};
int res[3005][3005] = { 0, };

int result[] = { 987654321,987654321,987654321 };

int dx[] = { 0, -1, 0 ,1 };
int dy[] = { 1, 0, -1, 0 };

void bfs() {

	int a, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == '2') {
				a = i;
				b = j;
				break;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(a , b));
	//visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];

			if (cx >= 0 && cy >= 0 && cx < n && cy < m) {
				if (visited[cx][cy] == 0 && A[cx][cy] == '0') {
					q.push(make_pair(cx, cy));
					visited[cx][cy] = 1;
					res[cx][cy] = res[x][y] + 1;
					
					//cout << "0" << endl;
				}
				if (visited[cx][cy] == 0 && A[cx][cy] == '3') {
					q.push(make_pair(cx,cy));
					visited[cx][cy] = 1;
					res[cx][cy] = res[x][y] + 1;
					result[0] = res[cx][cy];
					//cout << "3" << endl;
				}
				if (visited[cx][cy] == 0 && A[cx][cy] == '4') {
					q.push(make_pair(cx, cy));
					visited[cx][cy] = 1;
					res[cx][cy] = res[x][y] + 1;
					result[1] = res[cx][cy];
					//cout << "4" << endl;
				}
				if (visited[cx][cy] == 0 && A[cx][cy] == '5') {
					q.push(make_pair(cx, cy));
					visited[cx][cy] = 1;
					res[cx][cy] = res[x][y] + 1;
					result[2] = res[cx][cy];
					//cout << "5" << endl;
				}
			}
		}

	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j];
		}
		cout << endl;
	}*/

}



int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		A[i] = str;
	}

	bfs();

	int min = 987654321;
	for (int i = 0; i < 3; i++) {
		if (result[i] < min)
			min = result[i];
	}

	if (min == 987654321) {
		cout << "NIE" << endl;
	}
	else {
		cout << "TAK" << endl;
		cout << min << endl;
	}


}