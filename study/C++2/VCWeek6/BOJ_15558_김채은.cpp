#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N,K;
int map[2][100000];
int visited[2][100000];

void Input(){
    cin >> N >> K;
    for (int i=0; i<2; i++)
    {
        string in;
        cin >> in;
        for (int j=0; j < in.size(); j++)
            map[i][j] = in[j] - 48;
    }
}

void BFS()
{
    visited[0][0] = true;
    queue<int> Q;

    while (Q.empty() == 0)
    {}
}

int main()
{
    Input()
    BFS();
    return 0;
}
