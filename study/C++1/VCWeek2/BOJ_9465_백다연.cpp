#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
// 9465

int main()
{
  int t, m;
  cin >> t;

  while (t--)
  {

    int arr[2][100001];
    int dp[2][100001];

    cin >> m;

    for (int i = 0; i < 2; i++)
      for (int j = 1; j <=m; j++)
      {
        cin >> arr[i][j];
      }

    dp[0][0] = dp[1][0] = 0; 
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];

    for(int i = 2; i <=m; i++)
    {
      dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + arr[0][i]; //´ë°¢¼±
      dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
    }

    cout << max(dp[0][m],dp[1][m]) << endl;

  }
  

  


  

    return 0;
}