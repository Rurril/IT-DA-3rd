#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 5;

int answer;
bool visited[SIZE*SIZE];
map<int, char> m;

void compare(const int temp,int& cntS, int& cntY)
{
	if (m[temp] == 'S') cntS++;
	else cntY++;
}
void bfs()
{
	int cntS = 0, cntY = 0;

	vector<int> v;
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		if (visited[i])
		{
			v.push_back(i);
			compare(i, cntS, cntY);
		}
	}
	//v.push_back(5); v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(11); v.push_back(16);
	//compare(5, cntS, cntY); compare(6, cntS, cntY); compare(7, cntS, cntY); compare(8, cntS, cntY);
	//compare(9, cntS, cntY); compare(11, cntS, cntY); compare(16, cntS, cntY);

	if (cntS < 4) return;

	int dx[] = { 5,-5,1,-1 };

	queue<int> q;	q.push(v.front());
	
	bool check[SIZE*SIZE];
	memset(check, false, sizeof(check));
	check[v[0]] = true;

	int cnt = 1; bool flag = false;
	while (!q.empty())
	{
		int x = q.front(); q.pop();

		if (cnt == 7)
		{
			flag = true;
			break;
		}

		for (int k = 0; k < 4; k++)
		{
			if (x % 5 == 4 && k == 2) continue;
			if (x % 5 == 0 && k == 3) continue;

			int nx = x + dx[k];
			if (0 <= nx && nx < SIZE*SIZE)
			{
				if ((find(v.begin(), v.end(), nx) != v.end()) && !check[nx])
				{
					check[nx] = true;
					q.push(nx); cnt++;
				}
			}
		}
	}
	if (flag)
	{
		//for (int i = 0; i < 7; i++)
		//	cout << v[i] << " ";
		//cout << endl;
		answer++;
	}
}
void dfs(int idx, int cnt)
{
	if (cnt == 7)
	{
		bfs(); return;
	}
	for (int i = idx; i < SIZE*SIZE; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < SIZE*SIZE; i++)
	{
		char c; cin >> c;
		m.insert({ i,c });
	}
}
int main()
{
	init();
	dfs(0,0);
	//bfs();
	cout << answer;

	return 0;
}
