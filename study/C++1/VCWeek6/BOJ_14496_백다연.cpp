#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int a,b;
int n,m;
vector <int> v[10001];
queue <int> q;
int visit[10001];
int cnt[10001];

void bfs()
{
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == b)
        {
            cout << cnt[curr] << endl;
            return;
        }

        for (int i = 0; i < v[curr].size(); i++)
        {
            if (cnt[v[curr][i]] == 0)
            {
                q.push(v[curr][i]);
                cnt[v[curr][i]] = cnt[curr] + 1;
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> a >> b;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

    q.push(a);

    bfs();
  

    return 0;
   

}