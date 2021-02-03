#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int tc, n;
int result;
int arr[100001];
vector<int> answer;
bool visited[100001];
bool finished[100001];
void dfs(int x) {
	if (!visited[arr[x]]) {
		visited[arr[x]] = true;
		dfs(arr[x]);
	}
	else if (!finished[arr[x]]) {
		for (int i = arr[x]; i != x; i = arr[i]) {
			result++;
		}
		result++;
	}
	finished[x] = true;
	return;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> n;
		result = 0;
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i);
			}
		}
		answer.push_back(n - result);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}
