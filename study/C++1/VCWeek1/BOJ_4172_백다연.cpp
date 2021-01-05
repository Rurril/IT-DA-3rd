#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
// 4172

int main()
{
  int dp[1000001];

  dp[0] = 1;
  for (int i = 1; i <= 1000000; i++)
  {
    int sqrtn = (int)floor(i - sqrt(i));
    int logn = (int)log(i);
    int sinn = (int)(i * sin(i) * sin(i));

    dp[i] = (dp[sqrtn] + dp[logn] + dp[sinn]) % 1000000;
  }

  while(true)
  {
    int x;
    cin >> x;
  
    if(x == -1)
      break;

    cout << dp[x] << endl;
    
  }

  return 0;
}