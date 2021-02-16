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
int arr[3001][3001];
int visit[3001][3001];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int a,b;
int cnt[3001][3001];
vector <int> v;

queue <pair<int,int>> q;


int bfs()
{
    bool check =false;
    int val = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ny<=0 || nx <=0 || nx > n || ny > m)
                continue;
            if(arr[nx][ny]==1)
                continue;

            if(!visit[nx][ny])
            {
                visit[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;

                if(arr[nx][ny]>= 3 && arr[nx][ny] <=5)
                    return cnt[nx][ny];
                
                q.push(make_pair(nx,ny));

            }
        }
    }

    if(!check)
        return -1;
    else
    {
        return val;
    }
    
}



int main()
{

    cin >> n >> m;

    for(int i = 1; i <=n; i++)
    {
        string s;
        cin >> s;
    
        for(int j = 0; j < m; j++)
        {
            arr[i][j+1] = s.at(j) -'0';

            if(arr[i][j+1] == 2)
                q.push(make_pair(i,j+1));
             

        }

    }

    int ans = 0;
    ans = bfs();

    if(ans!= -1)
    {
        cout << "TAK" << endl;
        cout << ans << endl;
    }
    else 
        cout << "NIE" << endl;

    return 0;


}
