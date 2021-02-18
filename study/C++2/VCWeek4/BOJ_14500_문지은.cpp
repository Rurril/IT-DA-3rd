#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int map[501][501];
int visited[501][501] = { 0, };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int ans;
int n, m;
int temp;

void dfs(int x, int y, int temp, int cnt)
{
	if (cnt == 4)
	{
		ans = max(ans, temp);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		{
			if (visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				dfs(nx, ny, temp + map[nx][ny], cnt + 1);
				visited[nx][ny] = 0;
			}
		}
	}
}

void func(int i, int j)
{
	if (i >= 1 && i + 1 <= n && j >= 1 && j + 2 <= m)
		ans = max(ans, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);

	if (i >= 1 && i+2 <= n && j >= 1 && j+1 <= m)
		ans = max(ans, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j]);

	if (i - 1 >= 1 && i + 1 <= n && j >= 1 && j + 1 <= m)
		ans = max(ans, map[i][j] + map[i - 1][j + 1] + map[i][j + 1] + map[i + 1][j + 1]);

	if (i - 1 >= 1 && i <= n && j >= 1 && j + 2 <= m)
		ans = max(ans, map[i][j] + map[i - 1][j + 1] + map[i][j + 1] + map[i][j + 2]);
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{			
			visited[i][j] = 1;
			dfs(i, j, map[i][j], 1);
			visited[i][j] = 0;
			func(i, j);
		}
	}

	cout << ans;

}
