#include <iostream>

using namespace std;

unsigned long long N;

void moo(int n)
{
    if (n == 1) {
        cout << "moo";
    }
    else {
        moo(n - 1); 
        cout << "m";
        for (int i = 0; i < n + 1; i++) {
            cout << "o";
        }
        moo(n - 1);
    }
}

void solve(void)
{

}

void input(void)
{
    cin >> N;
}

int main(void)
{
    moo(5);
    cout << endl;

    return 0;
}