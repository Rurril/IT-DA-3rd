#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

char bracket[40];
stack<char> s;
int score = 0;
int tmp = 1;
bool err;

void solve(void)
{
    for (int i = 0; i < strlen(bracket); i++) {
        if (bracket[i] == '(') {
            s.push('(');
            tmp *= 2;
        }
        else if (bracket[i] == '[') {
            s.push('[');
            tmp *= 3;
        }
        else if (bracket[i] == ')') {
            if (s.empty()) {
                err = true;
                break;
            }
            if (s.top() == '(') {
                if (bracket[i - 1] == '(') {
                    score += tmp;
                }
                s.pop();
                tmp /= 2;
            }
            else {
                err = true;
                break;
            }
        }
        else if (bracket[i] == ']') {
            if (s.empty()) {
                err = true;
                break;
            }
            if (s.top() == '[') {
                if (bracket[i - 1] == '[') {
                    score += tmp;
                }
                s.pop();
                tmp /= 3;
            }
            else {
                err = true;
                break;
            }
        }        
    }

    if (err || !s.empty()) {
        cout << 0 << endl;
    }
    else {
        cout << score << endl;
    }
}

void input(void)
{
    cin >> bracket;
}

int main(void)
{
    input();
    solve();

    return 0;
}