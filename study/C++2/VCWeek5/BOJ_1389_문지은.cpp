#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int visited[101] = {0,};
vector <int> v[100];

queue <pair<int, int>> ans;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int minValue = 9999999;
	int minAns = -1;

	for (int i = 1; i <= n; i++)
	{
		int num = 0;

		memset(visited, 0, sizeof(int) * 101);
		while (!ans.empty()) ans.pop();

		visited[i] = 1;

		for (int j = 0; j < v[i].size(); j++)
		{
			ans.push(make_pair(v[i][j], 1));
			visited[v[i][j]] = 1;
			num += 1;
		}

		while (!ans.empty())
		{
			int c = ans.front().first;
			int ccnt = ans.front().second;
			ans.pop();

			for (int j = 0; j < v[c].size(); j++)
			{
				if (visited[v[c][j]] == 0)
				{
					visited[v[c][j]] = 1;
					ans.push(make_pair(v[c][j], ccnt + 1));
					num += ccnt + 1;
				}
			}
		}

		if (minValue > num)
		{
			minValue = num;
			minAns = i;
		}
		else if (minValue == num)
		{
			if (minAns > i) 
				minAns = i;
		}

	}

	cout << minAns;
}
