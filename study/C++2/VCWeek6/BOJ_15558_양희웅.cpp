#include <iostream>
#include <queue>

using namespace std;

int N, k;
int map[2][100010] {};
bool visit[2][10010] {};

bool bfs(void)
{
    queue<pair<pair<int, int>, int>> q;
    int dx[3] = {-1, 1, k};

    q.push(make_pair(make_pair(0, 0), 0));
    visit[0][0] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<pair<int, int>, int> next = make_pair(make_pair(cur.first.first + dx[i], cur.first.second ), cur.second);
            if (i == 2) {
                if (cur.first.first == 1) {
                    next.first.second = 0;
                }
                else {
                    next.first.second = 1;
                }
            }
            if (next.first.first >= N) {
                return true;
            }
            if (next.first.first <= k) {
                continue;
            }
            if (visit[next.first.first][next.first.second]) {
                continue;
            }
            if (map[next.first.first][next.first.second] == 0) {
                continue;
            }
            visit[next.first.first][next.first.second] = true;
            q.push(make_pair(make_pair(next.first.first, next.first.second), next.second + 1));
        }
    }
    return false;
}

void solve(void)
{
    if (bfs()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void input(void)
{   
    char tmp[100010];

    cin >> N >> k;
    for (int i = 0; i < 2; i++) {
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}