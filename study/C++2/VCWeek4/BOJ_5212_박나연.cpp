#include<iostream>
#include<algorithm>
using namespace std;

char map[15][15];
char future[15][15];

int main() {

	int R, C;
	cin >> R >> C;
	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			future[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int count = 0;
			if (map[i][j] == 'X') {
				if (i-1 < 0 || j < 0 || i-1 > R || j > C || map[i - 1][j] == '.') {
					count++;
				}
				if (i < 0 || j-1 < 0 || i > R || j-1 > C || map[i][j - 1] == '.') {
					count++;
				}
				if (i+1 < 0 || j < 0 || i+1 > R || j> C || map[i + 1][j] == '.') {
					count++;
				}
				if (i < 0 || j + 1 < 0 || i > R || j + 1 > C || map[i][j + 1] == '.') {
					count++;
				}
			}
			if (count >= 3) {
				future[i][j] = '.';
			}

		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (future[i][j] == 'X' && startX == 0) {
				startX = i;
			}
			if (future[i][j] == 'X') {
				endX = max(endX, i);
			}
		}
	}
	//cout << startX << endX;

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (future[j][i] == 'X' && startY == 0) {
				startY = i;
			}
			if (future[j][i] == 'X') {
				endY = max(endY, i);
			}
		}
	}

	//cout << startY << endY;

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			cout << future[i][j];
		}
		cout << endl;
	}


}