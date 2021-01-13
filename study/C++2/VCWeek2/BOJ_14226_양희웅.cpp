#include<iostream>
#include<queue>
 
using namespace std;
 
int S;
bool memo[2000][2000];

typedef struct emoji
{
    int display;
    int clipboard;
} emoji;
 
int BFS()
{
    queue<pair<emoji, int> > q;
    q.push(make_pair(emoji{1, 0}, 0));
    memo[1][0] = true;  
 
    while (q.empty() == 0) {
        int display = q.front().first.display;
        int clipboard = q.front().first.clipboard;
        int time = q.front().second;
        q.pop();
 
        if (display == S) {
            return time;
        }
        
        if (display > 0 && display < 2000) {
            if (memo[display][display] == false) {
                memo[display][display] = true;
                q.push(make_pair(emoji{display, display}, time + 1));
            }
 
            if (memo[display - 1][clipboard] == false) {
                memo[display - 1][clipboard] = true;
                q.push(make_pair(emoji{display - 1, clipboard}, time + 1));
            }
        }
 
        if (clipboard > 0 && display + clipboard < 2000) {
            if (memo[display + clipboard][clipboard] == false) {
                memo[display + clipboard][clipboard] = true;
                q.push(make_pair(emoji{display + clipboard, clipboard}, time + 1));
            }
        }
    }
}
 
 
void solve(void)
{
    cout << BFS() << endl;
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