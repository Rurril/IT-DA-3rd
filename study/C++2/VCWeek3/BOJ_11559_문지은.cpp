#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

char map[12][6];
int visited[12][6];
int num;
int ppuS;

queue <pair<int, int>> q;
queue <pair<int, int>> bomb;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int i, int j)
{
	q.push(make_pair(i, j));
	bomb.push(make_pair(i, j));
	visited[i][j] = 1;
	ppuS = 1;
	char sign = map[i][j];

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			int nx = cx + dx[a];
			int ny = cy + dy[a];

			if (nx >= 0 && nx <= 11 && ny >= 0 && ny <= 5)
			{
				if (visited[nx][ny] == 0 && map[nx][ny] == sign)
				{
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					bomb.push(make_pair(nx, ny));
					ppuS++;
				}
			}
		}

	}
	return ppuS;
}

void mapBomb()
{
	while (!bomb.empty())
	{
		int i = bomb.front().first;
		int j = bomb.front().second;
		bomb.pop();

		while (i > 0)
		{
			map[i][j] = map[i - 1][j];
			i--;
		}
		map[0][j] = '.';
	}
}


int main()
{
	for (int i = 0; i < 12; i++)
		cin >> map[i];
	
	num = 0;
	bool ppu = true;

	while (ppu)
	{
		ppu = false;

		//visited initialize
		for (int i = 0; i < 12; i++)
			memset(visited[i], 0, sizeof(int)*6);

		//bomb
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.' && visited[i][j] == 0)
				{
					while (!bomb.empty()) bomb.pop();	//bomb clear

					if (bfs(i, j) >= 4)
					{
						ppu = true;

						//map initialize
						mapBomb();
					}	
				}
			}
		}
		if (ppu) num++;

	}

	cout << num;
	
}
