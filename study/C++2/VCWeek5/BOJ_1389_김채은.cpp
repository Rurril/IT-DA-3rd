#include <iostream>
#include <queue>

using namespace std;

int N,M;
int know[101][101];
int connect[101];
int visited[101];
int result[101];

void Input()
{
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b;
		know[a][b]=1;
		know[a][b]=1;
	}
}

void bfs(int n)
{
	queue<int> Q;
	Q.push(n);
	visited[n] = 1;

	while (!Q.empty())
	{
		int j = Q.front();
		Q.pop();

		for(int i=1; i<= N; i++)
		{
			if (know[j][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				Q.push(i);
				connect[i] = connect[j] + 1;
			}
		}
	}
}

void Solution()
{
	for(int i = 1; i<=N; i++)
	{
		bfs(i);
		for(int j = 1; j<=N; j++)
			result[i] = result[i] + connect[j];
	}

	int minConnect = result[1];
	int minPerson = 1;
	for(int i = 2; i<=N; i++)
	{
		if (minConnect > result[i])
		{
			minConnect = result[i];
			minPerson = i;
		}
	}
	cout << minPerson << endl;
}

int main()
{
	Input();
	Solution();
	return 0;
}



