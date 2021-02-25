#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;
int N, M;
vector<int> str[1010] {};
bool visit[1010] {};
int cnt;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(q.size()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int now = q.front();
            q.pop();
            if (now == b) {
                cout << cnt  << endl;
                return;
            }
            for (int j = 0; j < str[now].size(); j++) {
                int next = str[now][j];
                if (!visit[next]) {
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
        cnt++;
    }
    cout << -1 << endl;
}

void solve(void)
{
    bfs(a);
}

void input(void)
{
    int tmp1, tmp2;

    cin >> a >> b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        str[tmp1].push_back(tmp2);
        str[tmp2].push_back(tmp1);
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}