#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char map[10][10];
int R, C;
int ma[4] = { 0,0,1,-1 };
int mb[4] = { 1,-1,0,0 };
vector <pair<int, int>> list;

void globalWarming(int a, int b) {
	int cnt=0;
	for (int i = 0; i < 4; i++) {
		int newa = a + ma[i];
		int newb = b + mb[i];
		if ((newa >= 0) && (newa <= R) && (newb >= 0) && (newb <= C)) {
			if (map[newa][newb] == 'X') {
				cnt++;
			}
		}
	}
	if (cnt <= 1) {
		list.push_back(make_pair(a, b));
	}
}

void sink() {
	for (int k = 0; k < list.size(); k++) {
		int p = list[k].first;
		int q = list[k].second;
		map[p][q] = '.';
	}
}

int main()
{
	int maxx, minx, maxy, miny;
	cin >> R >> C;
	minx = R-1; miny = C-1; maxx = 0; maxy = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				globalWarming(i, j);
			}
		}
	}
	sink();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		} 
	}
	for (int i = minx; i <= maxx;i++) {
		for (int j = miny; j <= maxy;j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
   
}
