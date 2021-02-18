#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char arr[12][12];
char result[12][12];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int R, C, cnt = 0;
	cin >> R >> C;
	int minx = 15, miny = 15, maxx = -1, maxy = -1;
	fill(arr[0], arr[0] + 144, '.');
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j] == '.')
			{
				result[i][j] = arr[i][j];
				continue;
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					if (arr[i + dx[k]][j + dy[k]] == '.')
						cnt++;
				}
				if (cnt >= 3) {
					result[i][j] = '.';
				}
				else {
					result[i][j] = 'X';
					minx = min(minx, i);
					miny = min(miny, j);
					maxx = max(maxx, i);
					maxy = max(maxy, j);
				}
			}
			cnt = 0;
		}
	}
	for (int i = minx; i <= maxx; i++)
	{
		for (int j = miny; j <= maxy; j++)
			cout << result[i][j];
		cout << endl;
	}

}