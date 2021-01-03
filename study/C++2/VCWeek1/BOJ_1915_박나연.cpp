#include<iostream>
#include<algorithm>
using namespace std;
int n, m;

int dp[1005][1005];

int main() {

	cin >> n >> m;

	char a;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			cin >> a;
			dp[i][j] = a - '0';
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j]) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				Max = max(Max, dp[i][j]);
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j];
			
		}
		cout << endl;
	}*/

	cout << Max * Max <<endl;
	return 0;
}

//char to int
//for i 범위 신경 쓰기
//cin >>n; cin >>m; -> false // cin>>n>>m; ->success