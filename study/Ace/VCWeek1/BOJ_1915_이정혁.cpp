#include<iostream>
#include<algorithm>

using namespace std;

char arr[1001][1001];
int N, M, result;
int copy_arr[1001][1001];
int d[1001][1001];

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '1') {
				copy_arr[i][j] = 1;
			}
		}
	}
}

void dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (copy_arr[i][j] == 1) {
				d[i][j] = min(min(d[i - 1][j], d[i][j - 1]),d[i-1][j-1]) + 1;
				result = max(result, d[i][j]);
			}
		}
	}
}

int solution() {
	init();
	dp();
	return result * result;
}

int main(void) {
	cout << solution();
	return 0;
}
