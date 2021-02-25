#include <iostream>
#include <queue>

using namespace std;

int n, m;
int island[3010][3010] {};
int ans[3010][3010] {};
bool visit[3010][3010] {};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> start;

int bfs(void)
{
    queue<pair<int, int>> q;
    q.push(start);

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);

            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
                continue;
            }
            if (island[next.first][next.second] == '1') {
                continue;
            }
            if (!visit[next.first][next.second]) {
                visit[next.first][next.second] = true;
                ans[next.first][next.second] = ans[cur.first][cur.second] + 1;

                if (island[next.first][next.second] >= '3' && island[next.first][next.second] <= '5') {
                    return ans[next.first][next.second];
                }
                q.push(next);
            }
        }
    }

    return -1;
}

void solve(void)
{
    int result = bfs();

    if (result == -1) {
        cout << "NIE" << endl;
    }
    else {
        cout << "TAK" << endl;
        cout << result << endl;
    }
}

void input(void)
{
    char tmp[3010];

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            island[i][j] = tmp[j];
            if (tmp[j] == '2') {
                start.first = i;
                start.second = j;
            }
        }
    }

}

int main(void)
{
    input();
    solve();

    return 0;
}