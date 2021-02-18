#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[1001][1001];
int answer[1001][1001];

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

void bfs(int i,int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (map[nx][ny] == 1&&answer[nx][ny]==-1)
				{
					answer[nx][ny] = answer[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	memset(answer, -1, sizeof(answer));
}
int main()
{
	init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				answer[i][j] = 0;
				bfs(i, j);
			}
			else if (map[i][j] == 0)
				answer[i][j] = 0;
		}
	}

	print();

	return 0;
}
