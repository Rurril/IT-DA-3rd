#include<iostream>
#include<stdio.h>
#include <queue>
using namespace std;
char arr[1501];
char check[4] = {'B','L','D','B' };
int N, big;
////////////////////////////////////////시간초과ㅠㅡㅠㅠㅡㅠㅠㅡㅠ 
queue<pair<int,int>> piv;
queue<pair<int, int>> num;
void eat() {
	while (!piv.empty()) {
		pair<int, int> p = piv.front();
		pair<int, int> n = num.front();
		int p1 = p.first;
		int p2 = p.second;
		int cnt = n.first;
		int t = n.second;
		piv.pop();
		num.pop();
		if (t == 3) t = 0;
		if (cnt > big) {
			big = cnt;
		}
		if (p1 > p2) { break; }
		else if (arr[p1] == check[t] && check[t]==arr[p2]) {
			piv.push(make_pair(p1 + 1, p2));
			num.push(make_pair(cnt + 1, t + 1));

			piv.push(make_pair(p1 , p2-1));
			num.push(make_pair(cnt + 1, t + 1));
		}
		else if (arr[p1] == check[t]) {
			piv.push(make_pair(p1 + 1, p2));
			num.push(make_pair(cnt + 1, t + 1));

		}
		else if (arr[p2] == check[t]) {
			piv.push(make_pair(p1, p2 - 1));
			num.push(make_pair(cnt + 1, t + 1));
		}
		else if (arr[p2] != check[t] && arr[p1] != check[t] ) {
			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 3 * N; i++) {
		cin >> arr[i];
	}

	piv.push(make_pair(0, (3 * N) - 1));
	num.push(make_pair(0, 0));
	eat();
	cout << big;
	return 0;
}
