#include<iostream>
#include<queue>

using namespace std;

int a, b;
int N, M;
int visited[1001];
int parent[1001];
vector<int> adj[1001];

void Input()
{
    cin >> a >> b;
    cin >> N >> M;

    for (int i = 0; i <= N ; i++)
    {
        visited[i] = -1;
        parent[i] = -1;
    }

    for (int i=0; i < M; i++)
    {
        int x, y;

        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void BFS()
{
    queue<int> Q;

    Q.push(a);
    visited[a] = 0;
    parent[a] = 0;

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        if (curr == b)
            break;

        for (int i = 0; i < adj[curr].size(); i++)
        {
            int next = adj[curr][i];

            if (visited[i] == -1)
            {
                Q.push(next);
                parent[next] = curr;
                visited[next] = visited[parent[next]] + 1;
            }
        }
    }

}

int main()
{
    Input();
    BFS();
    cout << visited[b];
    return 0;
}
