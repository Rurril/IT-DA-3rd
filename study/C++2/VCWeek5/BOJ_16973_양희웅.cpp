#include <iostream>
#include <queue>

using namespace std;

int N, M, H, W, Sr, Sc, Fr, Fc;
int table[1010][1010] {};
bool visit[1010][1010] {};
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool fail;

void bfs(pair<int, int> start)
{
    queue<pair<pair<int, int>, int>> q; //pair<dot<row, column>, count>
    q.push(make_pair(start, 0));
    visit[start.first][start.second] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> first = q.front();
        q.pop();

        if (first.first.first == Fr && first.first.second == Fc) {
            cout << first.second << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int r = first.first.first + dr[i];
            int c = first.first.second + dc[i];
            fail = false;

            if (r > 0 && c > 0 && r <= N && c <= M) {
                if (visit[r][c] == false) {
                    if (i == 0) {
                        int nc = c + W - 1;
                        if (nc > M) {
                            continue;
                        }
                        for (int j = r; j < r + H; j++) {
                            if (table[j][nc] == 1) {
                                fail = true;
                                break;
                            }
                        }
                    }
                    else if (i == 1) {
                        for (int j = r; j < r + H; j++) {
                            if (table[j][c] == 1) {
                                fail = true;
                                break;
                            }
                        }
                    }
                    else if (i == 2) {
                        int nr = r + H - 1;
                        if (nr > N) {
                            continue;
                        }
                        for (int j = c; j < c + W; j++) {
                            if (table[nr][j] == 1) {
                                fail = true;
                                break;
                            }
                        }
                    }
                    else if (i == 3) {
                        for (int j = c; j < c + W; j++) {
                            if (table[r][j] == 1) {
                                fail = true;
                                break;
                            }
                        }
                    }
                    if (!fail) {
                        visit[r][c] = true;
                        q.push(make_pair(make_pair(r, c), first.second + 1));
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

void solve(void)
{
    bfs(make_pair(Sr, Sc));
}

void input(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> table[i][j];
        }
    }
    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
}

int main(void)
{
    input();
    solve();

    return 0;
}