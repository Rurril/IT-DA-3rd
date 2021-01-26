#include <iostream>
#include <cstring>
#define Max(x, y)   (x) > (y) ? (x) : (y)
#define Min(x, y)   (x) < (y) ? (x) : (y)

using namespace std;

int T;
char control[510];
int dx[4] = {0, 1, 0, -1}; // 북 동 남 서
int dy[4] = {1, 0, -1, 0};
int curdir;

int main(void)
{
    cin >> T;
    for (int i = 0; i < T; i++) {
        pair<int, int> max {0, 0};
        pair<int, int> min {0, 0};
        pair<int, int> cur {0, 0};
        curdir = 0;

        cin >> control;
        for (int j = 0; j < strlen(control); j++) {
            switch (control[j]) {
                case 'F':
                    cur.first += dx[curdir];
                    cur.second += dy[curdir]; 
                    break;
                case 'B':
                    cur.first -= dx[curdir];
                    cur.second -= dy[curdir];
                    break;
                case 'L':
                    curdir = (curdir + 1) % 4;
                    break;
                case 'R':
                    curdir = (curdir + 3) % 4;
                    break;
            }
            max.first = Max(cur.first, max.first);
            max.second = Max(cur.second, max.second);
            min.first = Min(cur.first, min.first);
            min.second = Min(cur.second, min.second);
        }
        cout << (max.first - min.first) * (max.second - min.second) << endl;
    }

    return 0;
}