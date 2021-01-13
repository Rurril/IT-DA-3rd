#include <iostream>

using namespace std;

int N;
char map[5][5] {};
int memo[5][5] {};
int Max = -100000;
int Min = 100000;

void dp(int x, int y, int z)
{
    if (x == N - 1 && y == N - 1) {
        Max = Max > z ? Max : z;
        Min = Min < z ? Min : z;
        return;
    }
    for (int i = 0; i < 2; i++) {
        int a = x + i;
        int b = y - i + 1;
        if (a >= N || b >= N) {
            continue;
        }
        if (!memo[a][b]) {
            memo[a][b] = 1;
            if (map[x][y] == '+') {
                dp(a, b, z + map[a][b] - '0');
            }
            else if (map[x][y] == '-') {
                dp(a, b, z - map[a][b] + '0');
            }
            else if (map[x][y] == '*') {
                dp(a, b, z * (map[a][b] - '0'));
            }
            else {
                dp(a, b, z);
            }
            memo[a][b] = 0;
        }
    }
}

void solve(void)
{
    dp(0, 0, map[0][0] - '0');
    cout << Max << ' ' << Min << endl;
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}