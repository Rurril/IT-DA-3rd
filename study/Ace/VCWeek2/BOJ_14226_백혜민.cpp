#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int S;
bool visited[1001][1001];

int bfs()
{
	queue<pair<pair<int,int>,int>> q;
	q.push({ {1,0}, 0 });
	visited[1][0] = true;

	while (!q.empty())
	{
		int screen = q.front().first.first; int clipboard = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (screen == S)	return time;

		if (!visited[screen][screen]) //1
		{
			visited[screen][screen] = true;
			q.push({ { screen,screen }, time + 1 });
		}
		if (clipboard > 0 && screen + clipboard <= S && !visited[screen + clipboard][clipboard])
		{
			visited[screen + clipboard][clipboard] = true;
			q.push({ { screen + clipboard,clipboard }, time + 1 });
		}
		if (screen > 0 && !visited[screen - 1][clipboard])
		{
			visited[screen - 1][clipboard] = true;
			q.push({ { screen - 1,clipboard }, time + 1 });
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;
}
int main()
{
	init();
	cout << bfs();

	return 0;
}
