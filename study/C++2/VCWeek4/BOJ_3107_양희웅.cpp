#include <iostream>
#include <cstring>

using namespace std;

char IPv6[40];
char result[40];
int cnt;
int diff;

void insert(int idx, int num)
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < strlen(result) - idx; j++) {
            result[strlen(result) - j] = result[strlen(result) - j - 1];
        }
        result[idx + i] = '0';
    }
}

void solve(void)
{
    for (int i = 0; i < strlen(IPv6); i++) {
        if (IPv6[i] == ':') {
            chunk++;
        }
    }
    chunk++;

    for (int i = 0; i < strlen(IPv6); i++) {
        if (IPv6[i + 1] == '\0') {
            result[i + diff] = IPv6[i];
            insert(i + diff - cnt, 4 - cnt - 1);
            break;
        }
        if (IPv6[i] == ':') {
            result[i + diff] = IPv6[i];
            insert(i + diff - cnt, 4 - cnt);
            diff += 4 - cnt;
            cnt = 0;
            continue;
        }
        result[i + diff] = IPv6[i];
        result[i + diff + 1] = '\0';
        cnt++;
    }
    cout << result << endl;
}

void input(void)
{
    cin >> IPv6;
}

int main(void)
{
    input();
    solve();

    return 0;
}