#include<iostream>
#include<cmath>
using namespace std;
int dp[1000001];

int main(){

	
	for (int i = 0; i <= 1000000; i++) {
		dp[i] = -1;
	}
	dp[0] = 1;

	for (int i = 1; i < 1000000; i++) {
		int first = floor(i - sqrt(i));
		int second = floor(log(i));
		int third = floor(i * sin(i) * sin(i));
		
		dp[i] = (dp[first] + dp[second] + dp[third]) % 1000000;
	}

	while (true) {
		int N;
		cin >> N;
		if (N == -1)
			break;
		cout << dp[N] << endl;
	}



}