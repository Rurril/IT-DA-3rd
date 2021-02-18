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

int n,m;
int h,w,sr,sc,fr,fc;
int arr[1001][1001];
int ans = 1001;

bool check[1000][1000] = {false,};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct square {
    int x, y, num;
};

square value;

bool visit(int y, int x, int dir)
{

    //dy,dx방향에따라
    if (dir == 0) //위
    {
        for (int i = x; i < x + w; i++) //
        {
            if (arr[y][i] == 1)
                return false;
        }
    }
    else if (dir == 1) //오른쪽
    { 
        int nx = x + w - 1;
        if (nx >= m)
            return false;
        for (int i = y; i < y + h; i++)
            if (arr[i][nx] == 1)
                return false;
    }
    else if (dir == 2) //아래
    { 
        int ny = y + h - 1;
        if (ny >= n)
            return false;
        for (int i = x; i < x + w; i++)
        {
            if (arr[ny][i] == 1)
                return false;
        }
    }
    else if (dir == 3) //왼쪽
    { 
        for (int i = y; i < y + h; i++)
            if (arr[i][x] == 1)
                return false;
    }
    return true;
}




int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    
    cin >> h >> w >> sc >> sr >> fc >> fr;
    //직사각형 크기, 시작좌표, 도착좌표

    sr--;
    sc--;
    fr--;
    fc--;

    queue<square> q;
    value.x = sr;
    value.y = sc;
    value.num = 0;

    q.push(value);

    while(!q.empty())
    {
        int ax = q.front().x;
        int ay = q.front().y;
        int av = q.front().num;
        q.pop();

        if(ax == fr && ay == fc) //도착이면
        {
            ans = av; 
            break;
        }
        for(int i = 0 ; i < 4; i++)
        {
            int nx = ax + dx[i];
            int ny = ay + dy[i];

            //갈수 있는경우
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !check[ny][nx])
            {
                check[ny][nx] = true;
                if(visit(ny,nx,i))
                {
                    value.x = nx;
                    value.y = ny;
                    value.num = av + 1;
                    q.push(value);
                }
            }
        }

    }

    if(ans == 1001)
        ans = -1;
    cout << ans;

    return 0;



    

}