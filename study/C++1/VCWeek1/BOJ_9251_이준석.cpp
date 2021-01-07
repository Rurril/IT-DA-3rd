#include <iostream>
#include <algorithm>
#include <string>
int dp[1001][1001] = { 0 };
using namespace std;
int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}
	cout << dp[str1.length()][str2.length()];
}