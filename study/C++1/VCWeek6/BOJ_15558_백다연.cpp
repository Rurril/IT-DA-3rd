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
char map[2][100001];
bool visit[2][100001];

struct info
{
    int x, y, cnt;
};

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++) //i=0에 첫째, 1에 둘째
        {
            cin >> map[i][j];
        }
    }

    bool flag = false;


    queue<info> q;
    
    q.push({0, 0, 0});


    visit[0][0] = 1;

    while (!q.empty())
    {
        info now = q.front();
        q.pop();
        int x = now.x;
        int y = now.y;
        int cnt = now.cnt;

        //앞으로 가기
        if (y + 1 == N)
            flag = true;
        else if (map[x][y + 1] != '0' && visit[x][y + 1] == 0)
        {
            visit[x][y + 1] = 1; 
            q.push({x, y + 1, cnt + 1});
        }

        //뒤로 갈 수 있는지 확인
        if (map[x][y - 1] != '0' && visit[x][y - 1] == 0 && y - 1 > cnt)
        {
            visit[x][y - 1] = 1;
            q.push({x, y - 1, cnt + 1});
        }

        //옆으로 점프 가능
        if (y + K >= N)
            flag = true;
        else if (map[1 - x][y + K] != '0' && visit[1 - x][y + K] == 0)
        {
            visit[1 - x][y + K] = 1;
            q.push({1 - x, y + K, cnt + 1});
        }
    }

    if (flag == false)
        cout << 0;
    else
        cout << 1;
}
