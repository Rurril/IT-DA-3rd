#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int arr[1001][1001] = { 0 };
int dp[1001][1001] = { 0 };
int result = 0;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = arr[i][j];
			else if(arr[i][j]==1){
				dp[i][j] = min(dp[i - 1][j]+1, min(dp[i][j - 1]+1, dp[i - 1][j - 1]+1));
			}
			result = max(dp[i][j], result);
		}
	}
	cout << result*result;
}