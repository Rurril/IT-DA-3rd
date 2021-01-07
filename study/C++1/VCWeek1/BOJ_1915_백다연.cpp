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
  int n,m;

  cin >> n >> m;

  char s;

  int arr[1001][1001];
  int dp[1001][1001];

  for(int i = 1; i <=n; i++)
  {
    for(int j = 1; j <=m; j++)
    {
      cin >> s;
      arr[i][j] = s -'0';
    }
  }


int value = 0;
for(int i = 1; i <= n; i++)
{
  for(int j = 1; j <=m; j++)
  {
    if(arr[i][j] == 1)
    {
      arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
      if (arr[i][j] > value)
        value = arr[i][j];
    }
  }
}

cout << value * value << endl;

  return 0;
}