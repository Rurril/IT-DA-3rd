#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, answer;

vector<int> v[100001];
bool visited[100001];
bool finished[100001];

void dfs(int x) //int len)//다음 이동할 학생, 지금까지 이어진 학생 수, 시작점
{
	//cout << x << " " << len << endl;

	if (!visited[v[x][0]])
	{
		visited[v[x][0]] = true;
		dfs(v[x][0]);
	}
	else if (!finished[v[x][0]])
	{
		for (int i = v[x][0]; i != x; i = v[i][0])
			answer++;
		answer += 1;
	}
	finished[x] = true;

	return;
}
void init()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		v[i].clear();
	
	memset(visited, false, sizeof(visited));
	memset(finished, false, sizeof(finished));

	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		v[i].push_back(x);
	}

	answer = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		init();

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				dfs(i);
			}
		}

		cout << n - answer << "\n";
	}

	return 0;
}
