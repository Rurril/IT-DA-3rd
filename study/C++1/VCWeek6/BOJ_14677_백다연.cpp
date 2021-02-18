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

int dp[1501][1501];
int num[1501];

int solve(int l, int r, int now)
{
    if (l > r)
        return 1;

    if (dp[l][r] != -1)
        return dp[l][r];


    int result = 0;
    result = dp[l][r];

	//ret = 1;

    if (now == -1) //첫날
    {
        result = 0;
        now = 0;
    }

    if (now == num[l] && now == num[r]) 
    {
        result += max(solve(l + 1, r, (now + 1) % 3), solve(l, r - 1, (now + 1) % 3)); //양쪽비교
    }
    else if (now != num[l] && now == num[r]) //무조건 맨끝에 뜯는경우
    {
        result += solve(l, r - 1, (now + 1) % 3);
    }
    else if (now == num[l] && now != num[r]) //왼쪽
    {
        result += solve(l + 1, r, (now + 1) % 3);
    }

    return result;
}

int main()
{

    int n;
    cin >> n;


    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n * 3; i++)
    {
        char a;
        cin >> a;

        if (a == 'B')
        {
            num[i] = 0;
        }
        else if (a == 'L')
        {
            num[i] = 1;
        }
        else if (a == 'D')
        {
            num[i] = 2;
        }
    }

    int ans = 0;
    ans = solve(0, n * 3 - 1, -1); //맨왼쪽과 오른쪽
    cout << ans << endl;
}