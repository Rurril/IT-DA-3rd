#include<iostream>
#include<cstring>
using namespace std;
int dp[1005][1005];
string str1;
string str2;
int main() {

	string s1, s2;

	cin >> s1 >> s2;

	str1 = '0' + s1;
	str2 = '0' + s2;

	int str1_len = str1.length();
	int str2_len = str2.length();
	//cout << str1 << "," << str2 << endl;
	//cout << str1_len << "," << str2_len << endl;
	for (int i = 0; i < str1_len; i++) {
		for (int j = 0; j < str2_len; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}

			if (str1[i] == str2[j])// 현재 비교하는게 같다면
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	}

	cout << dp[str1_len - 1][str2_len - 1] << endl;



}