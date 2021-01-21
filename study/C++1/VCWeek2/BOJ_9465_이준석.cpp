#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[2][100001] = { 0 };
int dp[2][100001] = { 0 };
vector<int>vec;
int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
					dp[j][i] = max(dp[j + 1][i - 1] + arr[j][i], dp[j + 1][i - 2] + arr[j][i]);
				else
					dp[j][i] = max(dp[j - 1][i - 1] + arr[j][i], dp[j - 1][i - 2] + arr[j][i]);
			}
		}
		vec.push_back(max(dp[0][n - 1], dp[1][n - 1]));
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}