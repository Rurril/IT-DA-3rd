#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int visited[1001][1001] = { 0, };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;
int h, w, Sr, Sc, Fr, Fc;

queue <pair <int, pair <int, int>>> q;

int bfs()
{
	while (!q.empty())
	{
		int cnt = q.front().first;
		int Cr = q.front().second.first;
		int Cc = q.front().second.second;
		q.pop();
		//cout << cnt << " " << Cr << " " << Cc << endl;

		if (Cr == Fr && Cc == Fc)
		{
			return cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			bool move = true;

			int Nr = Cr + dx[i];
			int Nc = Cc + dy[i];

			if (visited[Nr][Nc] == 1)
			{
				move = false;
				continue;
			}

			//check
			if (i == 0)
			{
				if (Nr + h - 1 > n)
				{
					move = false;
					continue;
				}

				for (int j = 0; j < w; j++)
				{
					if (map[Nr + h - 1][Nc + j] == 1)
					{
						move = false;
						continue;
					}
				}
			}
			else if (i == 1)
			{
				if (Nr <= 0)
				{
					move = false;
					continue;
				}

				for (int j = 0; j < w; j++)
				{
					if (map[Nr][Nc + j] == 1)
					{
						move = false;
						continue;
					}
				}
			}
			else if (i == 2)
			{
				if (Nc + w - 1 > m)
				{
					move = false;
					continue;
				}
				for (int j = 0; j < h; j++)
				{
					if (map[Nr + j][Nc + w - 1] == 1)
					{
						move = false;
						continue;
					}
				}
			}
			else if (i == 3)
			{
				if (Nc <= 0)
				{
					move = false;
					continue;
				}

				for (int j = 0; j < h; j++)
				{
					if (map[Nr + j][Nc] == 1)
					{
						move = false;
						continue;
					}
				}
			}

			//move
			if (move && visited[Nr][Nc] == 0)
			{
				visited[Nr][Nc] = 1;
				q.push(make_pair(cnt + 1, make_pair(Nr, Nc)));
			}
		}

	}
	return -1;
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
	cin >> h >> w >> Sr >> Sc >> Fr >> Fc;

	q.push(make_pair(0, make_pair(Sr, Sc)));
	visited[Sr][Sc] = 1;

	cout << bfs();

}
