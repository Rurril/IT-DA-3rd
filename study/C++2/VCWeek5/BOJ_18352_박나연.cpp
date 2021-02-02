#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K, X;
int x, y;
vector<int> map[300003];
int minDis[300003];
vector<int> result;

void bfs() {

	for (int i = 0; i < 300003; i++) {
		minDis[i] = -1;
	}

	queue<int> q;
	q.push(X);
	minDis[X] = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();

		for (int i = 0; i < map[c].size(); i++) {
			if (minDis[i] == -1) {
				/*minDis[d] = minDis[c] + 1;
				q.push(d);*/
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (minDis[i] == K)
			result.push_back(i);
	}
	if (result.empty())
		cout << -1;
	else {
		sort(result.begin(), result.end());

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}


}



int main() {

	cin >> N >> M >> K >> X;
	

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x].push_back(y);
	}

	bfs();


}