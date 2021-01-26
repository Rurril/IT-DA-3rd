#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int R, C, T, result;
int arr[51][51];
int movement[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int spread[51][51] = { 0 };
vector<int> air;

void Dust() {
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			for (int i = 0; i < 4; i++) {
				int nx = x + movement[i][0];
				int ny = y + movement[i][1];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] != -1) {
					spread[nx][ny] += (arr[x][y] / 5);
					spread[x][y] -= (arr[x][y] / 5);
				}
			}
		}
	}

	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			arr[x][y] += spread[x][y];
		}
	}
}

//공기 청정
void refresh() {
	vector<pair<int, int>> up;
	vector<pair<int, int>> down;

	for (int x = air[0] - 1; x >= 0; x--) {
		up.push_back({ x, 0 });
	}
	for (int y = 0; y < C; y++) {
		up.push_back({ 0, y });
	}
	for (int x = 0; x <= air[0]; x++) {
		up.push_back({ x, C - 1 });
	}
	for (int y = C - 1; y > 0; y--) {
		up.push_back({ air[0], y });
	}

	for (int i = 0; i < up.size() - 1; i++) {
		arr[up[i].first][up[i].second] = arr[up[i + 1].first][up[i + 1].second];
	}
	arr[up[up.size() - 1].first][up[up.size() - 1].second] = 0;

	for (int x = air[1] + 1; x < R; x++) {
		down.push_back(make_pair(x, 0));
	}
	for (int y = 0; y < C; y++) {
		down.push_back(make_pair(R - 1, y));
	}
	for (int x = R - 1; x >= air[1]; x--) {
		down.push_back(make_pair(x, C - 1));
	}
	for (int y = C - 1; y >= 1; y--) {
		down.push_back(make_pair(air[1], y));
	}
	for (int i = 0; i < down.size() - 1; i++) {
		arr[down[i].first][down[i].second] = arr[down[i + 1].first][down[i + 1].second];
	}
	arr[down[down.size() - 1].first][down[down.size() - 1].second] = 0;
}

int resDust() {
	

	return result;
}

int main() {

	cin >> R >> C >> T;
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cin >> arr[x][y];
			if (arr[x][y] == -1)
				air.push_back(x);
		}
	}

	for (int i = 0; i < T; i++) {
		memset(spread, 0, sizeof(spread));
		Dust();	
		refresh();
	}

	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (arr[x][y] > 0)
				result += arr[x][y];
		}
	}

	cout << result;
	return 0;
}
