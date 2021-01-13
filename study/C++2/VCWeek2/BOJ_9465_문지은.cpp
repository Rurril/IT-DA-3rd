#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int arr[2][100000] = { 0, };
int dp[2][100000] = { 0, };

int main()
{
	vector <int> v;

	int t, n;
	cin >> t;

	while (t--)
	{
		for (int i = 0; i < 2; i++)
		{
			memset(arr[i], 0, 100000);
			memset(dp[i], 0, 100000);
		}

		cin >> n;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (j == 0)
					dp[i][j] = arr[i][j];
				else if (j == 1) {
					if (i == 0)
						dp[i][j] = arr[0][1] + arr[1][0];
					else if (i == 1)
						dp[i][j] = arr[1][1] + arr[0][0];
				}
				else
				{
					if (i == 0)
						dp[i][j] = max( dp[1][j - 1], max(dp[0][j - 2], dp[1][j - 2]) ) + arr[i][j];
					else if (i == 1)
						dp[i][j] = max(dp[0][j - 1], max( dp[0][j - 2], dp[1][j - 2] )) + arr[i][j];
				}

			}
		}

		v.push_back(max(dp[0][n - 1], dp[1][n - 1]));
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
