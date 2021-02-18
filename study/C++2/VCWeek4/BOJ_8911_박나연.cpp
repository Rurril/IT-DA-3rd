#include<iostream>
#include<cstring>
using namespace std;

//À§, ¿À, ¾Æ·¡, ¿Þ
//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };

//À§, ¿Þ, ¾Æ·¡, ¿À
int dx[] = { 0, 1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int main() {

	int T;
	string str;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> str;
		int d = 0;
		int x = 0; 
		int y = 0; 
		int  maxX, maxY, minX, minY;
		maxX = maxY = minX =minY = 0;
		for (int j = 0; j <= str.length(); j++) {
			//cout <<"d:"<< d << endl;
			if (str[j] == 'F') {
				//cout << "gg" << endl;
				//cout << j << ":" << d << endl;
				x += dx[d];
				y += dy[d];
				//cout << y << endl;
			}
			if (str[j] == 'B') {
				x -= dx[d];
				y -= dy[d];
			}
			if (str[j] == 'R') {
				/*if (d == 0){ d = 1; }
					
				if (d == 1){ d = 2; }
					
				if (d == 2){d = 3;}
				
				if (d == 3){ d = 0; }*/
				d = (d + 3) % 4;
					
			}
			if (str[j] == 'L') {
				/*if (d == 0) {
					d = 3; 
					cout << d << endl;
					cout << "dhodkdks"<< endl;
				}
				
				if (d == 1){ d = 0; }
					
				if (d == 2){ d = 1; }
					
				if (d == 3){ d = 2; }*/
				d = (d + 1) % 4;
			}
			//cout << x << endl;
			maxX = max(maxX, x);
			maxY = max(maxY, y);
			minX = min(minX, x);
			minY = min(minY, y);
			//cout << maxX << maxY << minX << minY << endl;
		}

		cout << (maxX - minX) * (maxY - minY) << endl;
	}

}