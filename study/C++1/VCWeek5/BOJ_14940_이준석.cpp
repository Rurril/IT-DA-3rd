#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[1001][1001] = { 0 };
int result[1001][1001] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n, m;
	fill(result[0], result[0] + 1001 * 1001, -1);
	cin >> n >> m;
	queue<pair<pair<int, int>, int>> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				q.push(make_pair(make_pair(i, j), 0));
				result[i][j] = 0;
			}
			else if (arr[i][j] == 0)
				result[i][j] = 0;
		}
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m)
			{
				if (arr[x + dx[i]][y + dy[i]] == 0)
					result[x + dx[i]][y + dy[i]] = 0;
				else if (arr[x + dx[i]][y + dy[i]] == 1 && result[x + dx[i]][y + dy[i]] == -1)
				{
					result[x + dx[i]][y + dy[i]] = z + 1;
					q.push(make_pair(make_pair(x + dx[i], y + dy[i]), z + 1));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}