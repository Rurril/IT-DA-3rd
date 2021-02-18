#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[51];
bool visited[51];
int answer[51][51];
void dfs(int x,int len,int st)
{
	//cout << x << endl;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			visited[v[x][i]]=true;
			dfs(v[x][i], len + 1,st);
		}
		else if(st==v[x][i])
		{
			cout << x << endl;
			answer[x] = (answer[x] < len) ? len : answer[x];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	int x, y;
	while (cin >> x >> y)
	{
		if (x == -1 && y == -1) break;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, 0, i);
	}
	
	int minV = visited[1];
	for (int i = 2; i <= N; i++)
	{
		if (minV > visited[i]) minV = visited[i];
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (minV == visited[i]) cnt++;
	}

	cout << minV << " " << cnt << "\n";

	for (int i = 1; i <= N; i++)
	{
		if (minV == visited[i]) cout << i << " ";
	}
	
	return 0;
}
