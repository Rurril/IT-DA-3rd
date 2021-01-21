#include<iostream>
#include<vector>

using namespace std;

int N, K, L, time;
int arr[105][105];
vector<pair<int, char>> v;
int movement[4][2] = { {0,1},{1,0}, {0,-1}, {-1,0} };
vector<pair<pair<int, int>,int>> turn;

void init() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = -1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char direction;
		cin >> t >> direction;
		v.push_back({ t,direction });
	}
}

void solution() {
	int HeadX = 1, HeadY = 1, tailX = 1, tailY = 1;
	int tx = 0, ty = 0, td = 0;
	arr[1][1] = 1;
	int direc = 0, idx = 0, direc2 = 0, idx2 = 0;
	while (1) {
		int nx = HeadX + movement[direc][0];
		int ny = HeadY + movement[direc][1];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N) {
			time++;
			return;
		}
		if (arr[nx][ny] == 1) {
				time++;
				return;
		}
		if (arr[nx][ny] == -1) {
			arr[nx][ny] = 1;
			HeadX = nx; HeadY = ny;
			time++;
		}
		if (arr[nx][ny] == 0) {
			if (idx > idx2) {
				if (turn[idx2].first.first == tailX && turn[idx2].first.second == tailY) {
					direc2 = turn[idx2].second;
					idx2++;
				}
			}
			arr[tailX][tailY] = 0;
			tailX += movement[direc2][0];
			tailY += movement[direc2][1];
			arr[nx][ny] = 1;
			HeadX = nx; HeadY = ny;
			time++;
		}
		if (idx < L) {
			if (time == v[idx].first) {
				if (v[idx].second == 'L') {
					if (direc == 0) direc = 3;
					else direc--;
				}
				if (v[idx].second == 'D') {
					if (direc == 3) direc = 0;
					else direc++;
				}
				idx++;
				turn.push_back({ { HeadX,HeadY}, direc });
			}
		}
	}
}
int main(void) {
	init();
	solution();
	cout << time;
	return 0;
}
