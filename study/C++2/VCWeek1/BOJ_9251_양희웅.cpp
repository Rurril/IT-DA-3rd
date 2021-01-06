#include<iostream>
#include<cstring>
 
#define MAX(x, y)   ( (x)>(y)?(x):(y) )

using namespace std;
 
char A[1001] {};
char B[1001] {};
int memo[1001][1001] {};
 
void solve(void)
{ 
    int lenA = strlen(A);
    int lenB = strlen(B);

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else {
                memo[i][j] = MAX(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    cout << memo[lenA][lenB] << endl;
}

void input(void)
{
    cin >> A >> B;
}
 
int main(void)
{
    input();
    solve();
 
    return 0;
}