#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

vector<pair<int,int>> v[1001];
bool visited[1001];
int dist[1001];

int stp, edp;

int sol()
{
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,stp }); dist[stp] = 0;

	while (!pq.empty())
	{
		int x = pq.top().second; pq.pop();

		if (!visited[x])
		{
			visited[x] = true;

			for (int i = 0; i < v[x].size(); i++)
			{
				int nx = v[x][i].second, val = v[x][i].first;

				if (dist[nx] > dist[x] + val)
				{
					dist[nx] = dist[x] + val;
					pq.push({ dist[nx],nx });
				}
			}
		}
	}

	return dist[edp];
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, d, t; cin >> s >> d >> t;
		v[s].push_back({ t,d });
	}
	cin >> stp >> edp;
	memset(dist, 1000000, sizeof(dist));
}
int main()
{
	init();
	cout << sol();

	return 0;
}
