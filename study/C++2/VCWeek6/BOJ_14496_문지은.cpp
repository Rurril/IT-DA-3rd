#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector <int> v[10001];
int ans[10001] = {0,};
int visited[10001] = { 0, };

int bfs(int start, int finish)
{
	queue <pair<int, int>> q;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int c = q.front().first;
		int cNum = q.front().second;
		q.pop();

		if (c == finish)
		{
			return ans[finish];
		}

		for (int i = 0; i < v[c].size(); i++)
		{
			if (visited[v[c][i]] == 0)
			{
				ans[v[c][i]] = cNum + 1;
				visited[v[c][i]] = 1;
				q.push(make_pair(v[c][i], cNum+1));
			}
		}
	}

	return -1;
}

int main()
{
	int a, b;
	cin >> a >> b;
	ans[a] = 0;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int f, s;
		cin >> f >> s;

		v[f].push_back(s);
		v[s].push_back(f);
	}

	cout << bfs(a, b);

}
