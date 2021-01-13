#include<iostream>
#include<algorithm>
using namespace std;

int dp[3][100005];
int S[3][100005];

int main() {

	int T;
	cin >> T;

	while (T > 0) {

		int n;
		cin >> n;

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> S[i][j];
			}
		}

		dp[1][1] = S[1][1];
		dp[2][1] = S[2][1];

		for (int i = 2; i <= n; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + S[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + S[2][i];
		}

		/*for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cout <<  dp[i][j] << endl;
			}
		}*/

		int result;
		result = max(dp[1][n], dp[2][n]);
		cout << result << endl;
		T--;
	}



}