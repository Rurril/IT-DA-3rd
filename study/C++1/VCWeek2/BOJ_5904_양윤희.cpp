#include <iostream>
using namespace std;
int dp[31];
int x;
int moo(int n) {
	if (n == 1) return 'm';
	if (n == 2 || n == 3) return 'o';

	int i = 0; //s 인덱스
	while (dp[i] < n) i++;
	if (dp[i] == n) return 'o'; 
	if (n - dp[i - 1] == 1) return 'm'; // 다음 칸 0가 k+2개 시작하는 m
	if (n - dp[i - 1] <= i + 3) return 'o'; //  moo.... 에서 o 해당하는 칸

	return moo((n - dp[i - 1] - (i + 3)));
}
int main(void) {
	dp[0] = 3;
	for (int i = 1; i < 30; i++) {
		dp[i] = (dp[i - 1] * 2) + (i + 3); //s(i)의 길이 정함
	}

	cin >> x;
	cout<<moo(x);
	
}