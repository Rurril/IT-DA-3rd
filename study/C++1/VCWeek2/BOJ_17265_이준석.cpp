#include <iostream>
#include <algorithm>
using namespace std;
char arr[7][7];
int maxdp[7][7];
int mindp[7][7];
int xd[2] = { 1,0 };
int yd[2] = { 0,1 };
int main() {
	fill(mindp[0], mindp[0] + 49, 7776);
	fill(maxdp[0], maxdp[0] + 49, -7777);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	maxdp[1][1] = arr[1][1] - '0';
	mindp[1][1] = arr[1][1] - '0';
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == '+'|| arr[i][j] == '-'|| arr[i][j] == '*')
				continue;
			else {
				for (int k = 0; k < 2; k++)
				{
					int x = xd[k];
					int y = yd[k];
					if (arr[i + x][j + y] == '*')
					{
						maxdp[i + x + 1][j + y] = max(maxdp[i + x + 1][j + y], maxdp[i][j] * (arr[i + x + 1][j + y] - '0'));
						maxdp[i + x][j + y + 1] = max(maxdp[i + x][j + y + 1], maxdp[i][j] * (arr[i + x][j + y + 1] - '0'));
						mindp[i + x + 1][j + y] = min(mindp[i + x + 1][j + y], mindp[i][j] * (arr[i + x + 1][j + y] - '0'));
						mindp[i + x][j + y + 1] = min(mindp[i + x][j + y + 1], mindp[i][j] * (arr[i + x][j + y + 1] - '0'));
					}
					else if (arr[i + x][j + y] == '+')
					{
						maxdp[i + x + 1][j + y] = max(maxdp[i + x + 1][j + y], maxdp[i][j] + (arr[i + x + 1][j + y] - '0'));
						maxdp[i + x][j + y + 1] = max(maxdp[i + x][j + y + 1], maxdp[i][j] + (arr[i + x][j + y + 1] - '0'));
						mindp[i + x + 1][j + y] = min(mindp[i + x + 1][j + y], mindp[i][j] + (arr[i + x + 1][j + y] - '0'));
						mindp[i + x][j + y + 1] = min(mindp[i + x][j + y + 1], mindp[i][j] + (arr[i + x][j + y + 1] - '0'));
					}
					else if (arr[i + x][j + y] == '-')
					{
						maxdp[i + x + 1][j + y] = max(maxdp[i + x + 1][j + y], maxdp[i][j] - (arr[i + x + 1][j + y] - '0'));
						maxdp[i + x][j + y + 1] = max(maxdp[i + x][j + y + 1], maxdp[i][j] - (arr[i + x][j + y + 1] - '0'));
						mindp[i + x + 1][j + y] = min(mindp[i + x + 1][j + y], mindp[i][j] - (arr[i + x + 1][j + y] - '0'));
						mindp[i + x][j + y + 1] = min(mindp[i + x][j + y + 1], mindp[i][j] - (arr[i + x][j + y + 1] - '0'));
					}
					
				}
			}
		}
	}
	cout << maxdp[N][N] << " " << mindp[N][N];
}