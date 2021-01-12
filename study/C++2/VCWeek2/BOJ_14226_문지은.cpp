#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int visited[1001][1001];

int s;

void bfs()
{
	queue <pair<int, int>> q;

	q.push(make_pair(1, 0));
	arr[1][0] = 0;

	while (!q.empty())
	{
		int m, c, t;
		m = q.front().first;
		c = q.front().second;
		t = arr[m][c];

		q.pop();

		if (m == s)
		{
			cout << t;
			return;
		}

		if (m > 0 && m <= s)
		{
			if (visited[m][m] == 0)
			{
				visited[m][m] = 1;
				q.push(make_pair(m, m));
				arr[m][m] = t + 1;
			}
		}

		if (m + c > 0 && m + c <= s && c > 0 && c <= s)
		{
			if (visited[m + c][c] == 0)
			{
				visited[m + c][c] = 1;
				q.push(make_pair(m + c, c));
				arr[m + c][c] = t + 1;
			}
		}

		if (m - 1 > 0 && m - 1 <= s && c > 0 && c <= s)
		{
			if (visited[m - 1][c] == 0)
			{
				visited[m - 1][c] = 0;
				q.push(make_pair(m - 1, c));
				arr[m - 1][c] = t + 1;
			}
		}

	}

}

int main()
{
	cin >> s;

	bfs();
}
