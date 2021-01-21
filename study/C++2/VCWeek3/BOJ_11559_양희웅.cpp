#include <iostream>

using namespace std;

char field[12][6] {};

void solve(void)
{

}

void input(void)
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> field[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}