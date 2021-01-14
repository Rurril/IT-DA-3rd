#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
// 5904
int dp[100000];
int n;
char s;
bool check = false;

void dfs(int k, int n)
{

    cout << "k" << k << endl;
    cout << "n" << n << endl;

    if(check)
        return;
    if(k==0) 
    { 
        cout << "k는 0" << endl;

        if(n==1)
            s = 'm';
        else
        {
            s = 'o';
        }
        check = true;
        return;
    }
    if (n <= dp[k - 1]) //앞에포함, 뒤에는 전부 제거
        dfs(k - 1, n);
    else if (n > dp[k - 1] && n < dp[k - 1] + k + 3) //o가 k에 속하는 경우
    {
        if (n == dp[k - 1] + 1)
            s = 'm';
        else
            s = 'o';
            
        check = true;
        return;
    }
    else //뒤에 포함하여 앞으로 당김
    {
        cout << "x";
        dfs(k-1,n-dp[k-1]-k-3); 
        return;
    }
    
    
}


int main()
{
    dp[0] = 3; 
    int i = 0;

    cin >> n;

    for(i=0; dp[i] < n; i++)
    {
        dp[i+1] = 2 * dp[i] + (i + 4);
    }

    dfs(i,n);

    cout << s << endl;



    return 0;
}