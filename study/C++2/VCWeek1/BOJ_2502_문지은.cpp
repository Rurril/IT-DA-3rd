#include <iostream>
using namespace std;

int main()
{
	int d, k;
	cin >> d >> k;

	pair<int, int> dp[100001];

	dp[1] = make_pair(1, 0);
	dp[2] = make_pair(0, 1);

	for (int i = 3; i <= d; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	int a = 1;
	int b;
	while (1)
	{
		if ((k - dp[d].first * a) % dp[d].second == 0)
		{
			b = (k - dp[d].first * a) / dp[d].second;
			break;
		}
		a++;
	}

	cout << a << endl << b;

}
