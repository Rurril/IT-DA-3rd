#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
// 1915

int main()
{

  string x;
  string y;

  cin >> x >> y;

  int dp[1001][1001]; // x, y

    for(int i = 1; i <=y.size(); i++)
    {
      for(int j = 1; j <=x.size(); j++)
      {
         if(y[i-1] == x[j-1])  //일치하면 
           dp[i][j] = dp[i-1][j-1] + 1; //대각선+1
          else
          {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 왼쪽 위쪽 최대값
          }
          
      }
    }

    cout << dp[y.size()][x.size()] << endl;

    return 0;
}