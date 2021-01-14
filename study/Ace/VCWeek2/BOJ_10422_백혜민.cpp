#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long dp[5001] = { 0, };
	dp[0] = 1, dp[2] = 1;
	for (int n = 4; n <= 5000; n += 2)
	{
		for (int i = 0; i <= n - 2; i += 2)
		{
			dp[n] += (dp[i] * dp[n - i - 2]);
			dp[n] %= 1000000007;
		}
	}

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		int n; cin >> n;

		if (n % 2 == 1) cout << 0 << "\n";
		else 
			cout << dp[n] << "\n";
	}
	return 0;
}
