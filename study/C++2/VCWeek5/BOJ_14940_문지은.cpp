#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[1001][1001];
int dp[1001][1001];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;

void bfs(int x, int y)
{
	queue <pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(x, y), 0));

	while (!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (map[nx][ny] == 1 && dp[nx][ny] == -1)
				{
					dp[nx][ny] = cnt + 1;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}

	}
}

int main()
{
	cin >> n >> m;

	int Fx, Fy;

	for (int i = 0; i < 1001; i++)
	{
		memset(dp[i], -1, sizeof(int) * 1001);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				Fx = i;
				Fy = j;
				dp[i][j] = 0;
			}

			if (map[i][j] == 0)
				dp[i][j] = 0;
		}
	}

	bfs(Fx, Fy);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
