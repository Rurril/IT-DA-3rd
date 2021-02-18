#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
string S;
int dp[1501][1501][3];
char pill[4] = { 'B','L','D' };

//ret과 dp가 어떻게 연결되어 있는지 잘 모르겠다
int find(int first, int last, int now) {
	if (first > last) { return 0; }
	int& ret = dp[first][last][now]; //??
	if (ret != -1) { return ret; }
	ret = 0;
	if (S[first] == pill[now]) {
		ret = 1 + find(first + 1, last, (now + 1) % 3);
	}
	if (S[last] == pill[now]) {
		ret = max(ret, 1 + find(first, last - 1, (now + 1) % 3));
	}
	return ret;
}

int main()
{
	cin >> N;
	cin >> S;
	N *= 3;
	memset(dp, -1, sizeof(dp));
	cout << find(0, N - 1, 0);
}
