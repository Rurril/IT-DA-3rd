#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
const int MAX_SIZE = 5;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

char arr[MAX_SIZE][MAX_SIZE];
int min_dp[MAX_SIZE][MAX_SIZE]; //최솟값 저장용
int max_dp[MAX_SIZE][MAX_SIZE]; //dp[i][j] = (i,j)일때의 연산 최댓값

void bfs()
{
	queue<pair<pair<int, int>,char>> q; //현재 좌표와 연산자
	q.push({ { 0, 0 },' ' });
	min_dp[0][0] = arr[0][0]-'0';
	max_dp[0][0] = arr[0][0]-'0';

	while (!q.empty())
	{
		int x = q.front().first.first, y = q.front().first.second;
		char oper = q.front().second;	q.pop();

		for (int k = 0; k < 2; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (arr[nx][ny] == '+' || arr[nx][ny] == '-' || arr[nx][ny] == '*')//다음 위치가 연산자인 경우
				{
					min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y]); //단순 값 갱신
					max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y]);
					q.push({ {nx,ny},arr[nx][ny] });//연산자를 포함해서 큐에 넣음
				}
				else
				{
					if (oper != ' ') //큐에 연산자가 들어있는 경우
					{
						if (oper == '+') //연산한 결과와 기존에 저장된 값을 비교
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] + (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] + (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
						else if (oper == '-')
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] - (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] - (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
						else if (oper == '*')
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] * (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] * (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
					}
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	//조건에서 만들어질 수 없는 임의의 최대,최소로 초기화
	memset(min_dp, 9999, sizeof(min_dp));
	memset(max_dp, -9999, sizeof(max_dp));

	bfs();
	
	cout << max_dp[N - 1][N - 1] << " " << min_dp[N - 1][N - 1];

	return 0;
}
