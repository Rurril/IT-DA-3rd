#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int N, result;
string str;
int visited[1505][1505];
queue<pair<int, int>> q;
char d[] = { 'B', 'L', 'D' };

void bfs() {

	int time = 0;
	result = -1;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!q.empty()) {
		int size_ = q.size();
		while (size_--) {
			int l = q.front().first;
			int r = q.front().second;
			q.pop();

			if (l + r < 3 * N) {
				if (str[l] == d[time] && visited[l + 1][r]==0) { //앞에서 부터 먹는 부분
					q.push(make_pair(l + 1, r));
					visited[l + 1][r] = 1;
				}
				if (str[3*N-1-r] == d[time] && visited[l][r + 1] == 0) { //뒤에서 부터 먹는 부분
					q.push(make_pair(l, r + 1));
					visited[l][r + 1] = 1;
				}
			}
		}

		result++;
		time = (time + 1) % 3;
	}


}


int main() {

	cin >> N;
	cin >> str;

	bfs();

	cout << result << endl;


}