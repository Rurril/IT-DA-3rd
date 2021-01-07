#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, r1, r2, K, result = 987654321;
vector<int> order;
int d[21];

void init() {
	cin >> N >> r1 >> r2 >> K;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		order.emplace_back(x);
	}
}

void dp(int o1, int o2, int cnt, int answer) {
	if (cnt == K) {
		result = min(answer, result);
		return;
	}
	dp(o1, order[cnt], cnt + 1, answer + abs(o2 - order[cnt]));
	dp(order[cnt], o2, cnt + 1, answer + abs(o1 - order[cnt]));
}

int main(void) {
	init();
	dp(r1, r2, 0, 0);
	cout << result;
	return 0;
}
