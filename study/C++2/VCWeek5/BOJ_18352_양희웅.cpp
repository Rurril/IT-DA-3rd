#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<int> graph[300010] {};
int route[300010] {};

void bfs(int start)
{
    queue<int> q;

    q.push(start);
    route[start] = 0;
    while (!q.empty()) {
        int first = q.front();
        q.pop();
        for (int i = 0; i < graph[first].size(); i++) {
            int next = graph[first][i];
            if (route[next] == 0) { //방문X
                route[next]= route[first] + 1;
                q.push(next);
            }
        }
    }
}

void solve(void)
{
    vector<int> ans;

    bfs(X);
    for (int i = 0; i < N; i++) {
        if (route[i + 1] == K) {
            ans.push_back(i + 1);
        }
    }

    if (ans.size() == 0) {
        cout << -1 << endl;
    }
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
}

void input(void)
{
    int A, B;

    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}