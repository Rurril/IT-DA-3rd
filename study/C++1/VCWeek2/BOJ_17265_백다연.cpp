#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
// 17265

int dx[2] = {1,0};
int dy[2] = {0,1};

int maxvalue = -100000000; //0으로 하니깐 안됨..
int minvalue = 10000000;

char arr[6][6];
int n;

void dfs(int x, int y, int result, int befor)
{
    for(int i = 0; i < 2; i++)
      {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && nx < n && ny >=0 && ny < n)
            {
                if(arr[nx][ny] == '+')
                    dfs(nx,ny,result,'+');
                else if (arr[nx][ny] == '-')
                    dfs(nx, ny, result, '-');
                else if (arr[nx][ny] == '*')
                    dfs(nx, ny, result, '*');
                else  //숫자인경우
                {
                    int sum = 0;
                    if( befor == '+')
                        sum = result + (arr[nx][ny]-'0');
                    else if (befor == '-')
                        sum = result - (arr[nx][ny] - '0');
                    else if (befor == '*')
                        sum = result * (arr[nx][ny] - '0');

                    if(nx==n-1 && ny == n-1)//탐색이끝나면
                    {
                        maxvalue = max(maxvalue,sum);
                        minvalue = min(minvalue, sum);
                        return;
                    }
                    dfs(nx,ny,sum,arr[nx][ny]); //계산한 값부터 다시 
                }
                
            }

        }
}





int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
 

    dfs(0,0,arr[0][0]-'0', arr[0][0]);

    cout << maxvalue << " " << minvalue << endl;

    return 0;
}