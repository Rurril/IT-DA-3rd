#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, k;

int visited[2][100001] = { 0, };
string arr[2];

int bfs()
{
	queue <pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(0, 0), 0));

	while (!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cNum = q.front().second;

		q.pop();

		int nx, ny;

		nx = cx;
		ny = cy + 1;
		if (ny >= n) return 1;
		if (ny > cNum)
		{
			if (visited[nx][ny] == 0 && arr[nx][ny] == '1')
			{
				visited[nx][ny] = 1;
				q.push(make_pair(make_pair(nx, ny), cNum + 1));
			}
		}

		nx = cx;
		ny = cy - 1;
		if (ny >= n) return 1;
		if (ny > cNum)
		{
			if (visited[nx][ny] == 0 && arr[nx][ny] == '1')
			{
				visited[nx][ny] = 1;
				q.push(make_pair(make_pair(nx, ny), cNum + 1));
			}
		}

		nx = (cx + 1) % 2;
		ny = cy+k;
		if (ny >= n) return 1;
		if (ny > cNum)
		{
			if (visited[nx][ny] == 0 && arr[nx][ny] == '1')
			{
				visited[nx][ny] = 1;
				q.push(make_pair(make_pair(nx, ny), cNum + 1));
			}
		}

	}
	return 0;
}

int main()
{
	cin >> n >> k;

	cin >> arr[0];
	cin >> arr[1];

	cout << bfs();
}
