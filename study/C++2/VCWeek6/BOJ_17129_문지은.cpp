#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[3001][3001];
int visited[3001][3001] = {0,};

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;

void bfs(int sx, int sy)
{
	queue <pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sx, sy), 0));

	while (!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cNum = q.front().second;
		q.pop();

		if (map[cx][cy] != 0 && map[cx][cy] != 1 && map[cx][cy] != 2)
		{
			cout << "TAK" << endl;
			cout << cNum;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (visited[nx][ny] == 0 && map[nx][ny] != 1)
				{
					visited[nx][ny] = 1;
					q.push(make_pair(make_pair(nx, ny), cNum + 1));
				}
			}
		}

	}
	cout << "NIE";
}

int main()
{
	cin >> n >> m;

	int sx, sy;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j-1] - (int)'0';
			if (s[j-1] - (int)'0' == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}

	bfs(sx, sy);

}
