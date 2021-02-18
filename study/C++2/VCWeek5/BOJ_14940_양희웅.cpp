#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1010][1010] {};
int dist[1010][1010] {};
bool visit[1010][1010] {};
pair<int, int> target;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visit[start.first][start.second] = true;
    map[start.first][start.second] = 0;

    while(!q.empty()) {
        pair<int, int> first = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {first.first + dr[i], first.second + dc[i]};
            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
                continue;
            }
            if (visit[next.first][next.second] || !map[next.first][next.second]) {
                continue;
            }
            visit[next.first][next.second] = true;
            dist[next.first][next.second] = dist[first.first][first.second] + 1;
            q.push(next);
        }
    }
}

void solve(void)
{
    bfs(target);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !dist[i][j]) {
                dist[i][j] = -1;
            }
        }
    }
    dist[target.first][target.second] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void input(void)
{
    int tmp;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp == 2) {
                target.first = i;
                target.second = j;
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