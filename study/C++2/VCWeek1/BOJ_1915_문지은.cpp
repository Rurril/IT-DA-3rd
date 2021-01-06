#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1000][1000];
int dp[1000][1000];

int main()
{
	int n, m;
	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = (int)(s[j] - '0');
		}
	}

	int maxl = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = arr[i][j];
			else
			{
				if (arr[i][j] == 1)
				{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
					if (dp[i][j] > maxl) maxl = dp[i][j];
				}
			}
		}
	}
	
	cout << maxl * maxl;


}
