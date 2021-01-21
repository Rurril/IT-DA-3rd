#include <iostream>
#include <algorithm>
using namespace std;

int n;

int dx[] = { 1, 0};
int dy[] = { 0, 1};

int arr[6][6];
int visited[6][6];

int maxA = -4000;
int minA = 4000;

void dfs(int a, int x, int y, int s)
{
	visited[x][y] = 1;

	//cout << a << ' ' << x << ' ' << y << ' ' << s << endl;

	if (x == n && y == n)
	{
		minA = min(minA, a);
		maxA = max(maxA, a);
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
		{
			if (visited[nx][ny] == 0)
			{
				if (s == -1)
				{
					dfs(a, nx, ny, arr[nx][ny]);
					visited[nx][ny] = 0;
				}
				else
				{
					if (s == (int)'+') { dfs(a + arr[nx][ny], nx, ny, -1); visited[nx][ny] = 0; }
					else if (s == (int)'-') { dfs(a - arr[nx][ny], nx, ny, -1); visited[nx][ny] = 0; }
					else if (s == (int)'*') { dfs(a * arr[nx][ny], nx, ny, -1); visited[nx][ny] = 0; }
				}
			}
		}
	}
}


int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin >> c;

			if ((int)c >= (int)'0' && (int)c <= (int)'5')
				arr[i][j] = (int)c - (int)'0';
			else
				arr[i][j] = (int)c;

		}
	}

	dfs(arr[1][1], 1, 1, -1);

	cout << maxA << ' ' << minA;


}
