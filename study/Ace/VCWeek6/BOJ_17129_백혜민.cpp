#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct position
{
	int x, y;
};
position ddak;
vector<position> food;
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int map[3000][3000];
int visited[3000][3000];

void bfs()
{
	queue<position> q;
	q.push(ddak);

	memset(visited, -1, sizeof(visited));
	visited[ddak.x][ddak.y] = 0;

	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y;
		q.pop();
		
		for (int k = 0; k < 4; k++)
		{
			int nx = cx + dx[k], ny = cy + dy[k];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (visited[nx][ny] == -1 && map[nx][ny] != 1)
				{
					visited[nx][ny] = visited[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
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
		{
			char c; cin >> c;
			map[i][j] = c - '0';

			if (map[i][j] == 2)
				ddak.x = i, ddak.y = j;
			else if (map[i][j] > 2)
				food.push_back({ i,j });
		}
	}
}
int main()
{
	init();
	bfs();
	int min = -1;
	for (int i = 0; i < food.size(); i++)
	{
		if (visited[food[i].x][food[i].y] > 0)
		{
			if (min == -1) min = visited[food[i].x][food[i].y];
			else min = (min > visited[food[i].x][food[i].y]) ? visited[food[i].x][food[i].y] : min;
		}
	}

	if (min == -1) cout << "NIE";
	else cout << "TAK\n" << min;

	return 0;
}
