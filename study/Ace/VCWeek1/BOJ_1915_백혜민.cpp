#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	char Arr[1000][1000];
	int dp[1000][1000] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Arr[i][j];
			if (Arr[i][j] == '1')
				dp[i][j] = 1;
		}
	}

	//행-1,열-1,행-1&열-1 에서 최솟값 + 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Arr[i][j] == '1')
			{
				int minValue = 0;
				if (Arr[i - 1][j - 1] == '1'&&Arr[i - 1][j] == '1'&&Arr[i][j - 1] == '1')
				{
					minValue = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
					dp[i][j] += minValue;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			answer = (answer < dp[i][j]) ? dp[i][j] : answer;
	}

	cout << answer * answer;
	
	return 0;
}
