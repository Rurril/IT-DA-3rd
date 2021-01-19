#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int R = 12, C = 6;
char arr[R][C];
bool visited[R][C];

vector<pair<int, int>> v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];

			if (0 <= nx && nx < R & 0 <= ny && ny < C)
			{
				if (arr[nx][ny] == arr[i][j] && !visited[nx][ny])//뿌요 색이 같고 방문하지 않았으면
				{
					v.push_back({ nx,ny });
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void bomb(vector<pair<int,int>> t) //터지기
{
	for (int i = 0; i < t.size(); i++)
	{
		arr[t[i].first][t[i].second] = '.';
	}
}
int move()
{
	int min = C - 1;
	for (int i = 0; i < C; i++)//열 탐색
	{
		for (int j = R - 2; j >= 0; j--)
		{
			if (arr[j][i] == '.') continue;
			min = (min > i) ? i : min;
			for (int k = R - 1; k > j; k--)
			{
				if (arr[k][i] == '.')
				{
					arr[k][i] = arr[j][i];
					arr[j][i] = '.';
					break;
				}
			}
		}
	}

	return min;
}
void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	bool flag = false;

	vector<pair<int, int>> tmp;
	while (!flag)
	{
		memset(visited, false, sizeof(visited));
		tmp.clear();

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] == '.') continue;

				if (!visited[i][j])
				{
					v.clear(); v.push_back({ i,j });
					bfs(i, j);

					if (v.size() >= 4)
					{
						for (int k = 0; k < v.size(); k++)
							tmp.push_back(v[k]);
						flag = true; // 폭발할 게 있다
					}
				}
			}
		}
		if (!flag) break;
		else
		{
			//print();
			bomb(tmp);
			//print();
			move();
			//print();
			answer++;
			flag = false;
		}
	}

	cout << answer;
	
	return 0;
}
