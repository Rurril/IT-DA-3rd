#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[501][501];

int H, W;
vector<int> block;
int result;

void init() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int len;
		cin >> len;
		block.emplace_back(len);
	}
}
void solve() {
	for (int i = 1; i < W - 2; i++) {

		for (int j = H - block[i]; j > 0; j--) {
			
		}
	}
}
/*
void solve() {
	int start_idx = 0;
	int start = block[0];
	int diff;
	for (int i = 0; i < W - 1; i++) {
		diff = block[i] - block[i + 1];
		if (diff > 0) {
			if (i == W - 2) {
				continue;
			}
			continue;
		}
		else if (diff <= 0 && start > block[i+1]){
			if (i == W - 2) {
				for (int j = start_idx; j < W - 1; j++) {
					int c = block[W - 1] - block[j];
					if (c > 0) {
						result += c;
					}
					
				}
			}
			continue;
		}
		else if (diff <= 0 && start <= block[i + 1]) {
			for (int j = start_idx; j < i + 1; j++) {
				result += (start - block[j]);
			}
			start = block[i + 1];
			start_idx = i + 1;
		}
	}
}
*/
/*
void solve() {
	int maximum = block[0];
	int idx1;
	for (int i = 1; i < H; i++) { // 첫번째 벽보다 크거나 같은 벽이 있는지 찾기
		if (i == H - 1) {
			if (maximum <= block[i]) { // 끝 벽이 첫 벽 보다 크면은 그대로 리턴
				return;
			}
			else { // 끝 벽이 첫벽보다 작으면은 
				result -= ((H - 1) * (maximum - block[i]));
				return;
			}
		}
		if (maximum > block[i]) {
			result += maximum - block[i];
		}
		else {
			idx1 = i;
			maximum = block[i];
			break;
		}
		
	}
	for (int i = idx1; i < H; i++) {

	}
}
*/
int main(void) {
	init();
	solve();
	cout << result;
	return 0;
}
