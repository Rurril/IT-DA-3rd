#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char map[11][11];

int minX, minY, maxX, maxY;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

vector <pair <int, int>> v;

int r, c;

bool check(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			if (map[nx][ny] == '.')
				cnt++;
		}
		else
		{
			cnt++;
		}
	}

	if (cnt >= 3)
		return true;
	else
		return false;
}

int main()
{
	cin >> r >> c;

	string s;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
		}
	}

	minX = 11;
	minY = 11;
	maxX = -1;
	maxY = -1;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'X' && check(i, j))
				v.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		map[v[i].first][v[i].second] = '.';
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'X')
			{
				minX = min(minX, i);
				minY = min(minY, j);

				maxX = max(maxX, i);
				maxY = max(maxY, j);
			}
		}
	}

	if (minX == 11 && minY == 11 && maxX == -1 && maxY == -1)
	{
		cout << 'X';
		return 0;
	}

	for (int i = minX; i <= maxX; i++)
	{
		for (int j = minY; j <= maxY; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}


}
