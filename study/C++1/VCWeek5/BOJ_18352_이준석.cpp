#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec[300001];
vector<int> result;
int col[300001] = { 0 };
int main() {
	int N, M, K, X, d = 0;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	queue<int>q;
	q.push(X);
	col[X] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); i++)
		{
			if (col[vec[x][i]] == 0)
			{
				q.push(vec[x][i]);
				col[vec[x][i]] = col[x] + 1;
				if (col[vec[x][i]] - 1 == K)
					result.push_back(vec[x][i]);
			}
		}
	}
	if (result.size() == 0)
		cout << -1;
	else {
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) 
				cout << result[i] << endl;
		
	}
}
