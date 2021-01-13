#include <iostream>

using namespace std;

/*
    a(C) = xa(1) + ya(2) = D
*/

int C, D;
int x, y;
long long memo[50] {};

long long fibo(int n)
{
    if (memo[n] != 0) {
        return memo[n];
    }

    for (unsigned int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

void solve(void)
{
    x = fibo(C - 3);
    y = fibo(C - 2);
    
    for (int i = 1; i <= D / x; i++) {
        if ((D - x * i) % y == 0) {
            cout << i << endl;
            cout << (D - x * i) / y << endl;
            break;
        }
    }
}

void input(void)
{
    memo[0] = 1;
    memo[1] = 1;

    cin >> C >> D;
}

int main(void)
{
    input();
    solve();

    return 0;
}