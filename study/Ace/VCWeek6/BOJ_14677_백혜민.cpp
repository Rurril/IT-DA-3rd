#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s; string m = "BLD";
int dp[1500][1500][3];

int sol(int low,int high,int idx)
{
	if (low > high) return 0;

	int &temp = dp[low][high][idx];
	if (temp > 0) return temp;
		
	if (s[low] == m[idx])
		temp = sol(low + 1, high, (idx + 1) % 3)+1;
	if (s[high] == m[idx])
		temp = max(temp, sol(low, high - 1, (idx + 1) % 3)+1);
	
	return temp;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> s;
}
int main()
{
	init();
	cout << sol(0, 3 * N - 1, 0);

	return 0;
}
