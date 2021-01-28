#include <iostream>
using namespace std;
int direct[4][2] = { 1,0,0,-1,-1,0,0,1 };
string map[11];
string res[11];
int R, C, cnt;
int maxx, minx = C, maxy, miny = R;

void run(int y, int x) {		
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + direct[i][0];
		int nx = x + direct[i][1];
		if (ny == -1 || nx == -1 || ny == R || nx == C) {
			cnt++;
			continue;
		}
		if (ny<-1 || nx<-1 || ny>R || nx>C)continue;
		if (map[ny][nx] == '.')cnt++;
	}
	if (cnt >= 3) {
		res[y][x] = '.';
		
	}
	if(cnt<3) {
		maxx = max(maxx, x); 
		minx = min(minx, x);
		maxy = max(maxy, y);
		miny = min(miny, y);
	}
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		res[i] = map[i];
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == 'X') {
				run(y, x);
			}
		}
	}
	for (int i = miny+1; i < maxy+1; i++) {
		for (int j = minx; j < maxx+1; j++) {
		cout << res[i][j];
		}
		cout << endl;
	}
}