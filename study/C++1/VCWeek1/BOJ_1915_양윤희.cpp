#include <iostream>
#include <stdio.h>
using namespace std;
int dp[1001][1001], arr[1001][1001];
int n, m, result;
void run() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0 || i == 0) {
				arr[i][j] = dp[i][j];
			}
			else if (i >= 1 && j >= 1 && dp[i][j] == 1) {

				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
			}
			result = max(result, arr[i][j]);
		}
	}
}
int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &dp[i][j]);
		}
	}
	run();
	cout << result * result;
}