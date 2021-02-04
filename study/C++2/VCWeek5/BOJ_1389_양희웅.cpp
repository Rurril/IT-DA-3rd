#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int relation[105][105] {};
int user[105] {};
int minimum = 1000000;
int tmp;
int ans;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    user[start]++;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int first = q.front();
            q.pop();
            for (int j = 1; j <= N; j++) {
                if (relation[first][j] != 1 || user[j] >= 0) {
                    continue;
                }
                q.push(j);
                user[j] = user[first] + 1;
            }
        }
    }
}

void solve(void)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            user[j] = -1;
        }
        bfs(i);
        tmp = 0;
        for (int j = 1; j <= N; j++) {
            tmp += user[j];
        }
        if (tmp < minimum) {
            minimum = tmp;
            ans = i;
        }
    }
    cout << ans << endl;
}

void input(void)
{
    int a, b;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}