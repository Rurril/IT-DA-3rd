#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec[101];
int arr[101] = { 0 };
int col[101] = { 0 };
int main() {
	int N, M, cnt = 100000000;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	for (int j = 1; j <= N; j++)
	{
		queue <pair<int, int>> q;
		q.push(make_pair(j, 0));
		col[j] = 1;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < vec[x].size(); i++)
			{
				if (col[vec[x][i]] == 0)
				{
					q.push(make_pair(vec[x][i], y + 1));
					col[vec[x][i]] = y + 1;
					arr[j] += (y + 1);
				}
			}
		}
		if (cnt > arr[j]) {
			cnt = arr[j];
		}
		fill(col, col + N+1, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == cnt)
		{
			cout << i;
			return 0;
		}
	}
}