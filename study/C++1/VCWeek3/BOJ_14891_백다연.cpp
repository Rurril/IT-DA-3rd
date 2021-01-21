#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
//14891
//n극 0, s극 1
//1시계방향, -1반시계방향

bool visit[5];
vector<pair<int, int>> v;
int k;
deque<int> dq[5]; //톱니바퀴 정보 저장

void rotate(int num, int direct)
{
    if (direct == 1) //시계방향
    {
        int value = dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(value);
    }
    else if (direct == -1)
    {
        int value = dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(value);
    }
}

void check(int num, int direct)
{
    visit[num] = true;

    int pre = num - 1;
    int next = num + 1;

    if (pre > 0 && !visit[pre])
    {
        if (dq[pre][2] != dq[num][6]) //서로 반대면 돌아야함
            check(pre, direct * -1);
    }

    //다음
    if (next < 5 && !visit[next])
    {
        if (dq[next][6] != dq[num][2])
            check(next, direct * -1); //
    }

    rotate(num, direct);
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            int num = s[j] - '0';
            dq[i + 1].push_back(num);
        }
    }
    cin >> k; //총 횟수

    for (int i = 0; i < k; i++)
    {
        int changenum;
        int direct;

        cin >> changenum >> direct;
        v.push_back(make_pair(changenum, direct));
    }

    for (int i = 0; i < v.size(); i++) //회전
    {
        check(v[i].first, v[i].second);
        memset(visit, false, sizeof(visit));
    }

    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        if (dq[i][0] == 1)
            ans += pow(2, i - 1);
    }

    cout << ans << endl;

    return 0;
}
