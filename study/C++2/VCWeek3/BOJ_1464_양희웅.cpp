#include <iostream>
#include <cstring>

using namespace std;

/*
    맨 앞자리 문자 저장해둠

    앞부터 진행하다가
    1. 맨 앞자리보다 앞서거나 같은 문자 발견하면 
    2. 우선 그 전에 swap
    3. 앞선 문자 자리에서 한번 더 swap 
*/

char S[10000] {};
char first;

void swap(int index)
{
    char tmp;

    for (int i = 0; i <= index / 2; i++) {
        tmp = S[i];
        S[i] = S[index - i];
        S[index - i] = tmp;
    }
}

void solve(void)
{
    if (strlen(S) == 1) {
        cout << S;
        return;
    }
    first = S[0];
    for (int i = 1; i < strlen(S); i++) {
        if (S[i] <= first) {
            first = S[i];
            swap(i - 1);
            swap(i);
        }
    }
    cout << S << endl;;
}

void input(void)
{
    cin >> S;
}

int main(void)
{
    input();
    solve();

    return 0;
}