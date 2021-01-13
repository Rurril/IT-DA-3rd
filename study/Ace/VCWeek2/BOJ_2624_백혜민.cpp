#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, k;
int dp[10001][101];
vector<pair<int,int>> v; //금액, 동전 개수

int sol(int sum,int idx)//매개변수는 토탈 금액과 인덱스
{
	if (sum == T) return 1;
	if (idx >= k) return 0;
	if (dp[sum][idx] != -1) return dp[sum][idx];

	dp[sum][idx] = 0;

	for (int i = 0; i <= v[idx].second; i++)
	{
		if (sum + i * v[idx].first <= T)
		{
			dp[sum][idx] += sol(sum + i * v[idx].first, idx + 1);
		}
	}

	return dp[sum][idx];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T >> k;

	for (int i = 0; i < k; i++)
	{
		int p, n; cin >> p >> n;
		
		v.push_back({ p,n });
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i <= T; i++)
	{
		for (int j = 0; j < k; j++)
			dp[i][j] = -1;
	}

	cout << sol(0, 0);

	return 0;
}
