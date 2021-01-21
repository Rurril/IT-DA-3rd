#include <iostream>

using namespace std;

char gear[4][8] {};
int K;
int score;

void rotate(char gear[], int dir)
{
    char tmp;
    if (dir == 1) { // 시계 방향으로 회전
        tmp = gear[7];
        for (int i = 0; i < 7; i++) {
            gear[7 - i] = gear[6 - i];
        }
        gear[0] = tmp;
    }
    else { // 반시계 방향으로 회전
        tmp = gear[0];
        for (int i = 0; i < 7; i++) {
            gear[i] = gear[i + 1];
        }
        gear[7] = tmp;
    }
}

void solve(void)
{
    int which;
    int dir;

    for (int i = 0; i < 4; i++) {
        cin >> gear[i];
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> which >> dir;
        which--;
        rotate(gear[which], dir);
        switch (which) {
        case 0: // 톱니 A를 돌림
            if (gear[0][2] == gear[1][6]) {
                rotate(gear[1], dir * -1); // B를 돌림
                if (gear[1][2] == gear[2][6]) {
                    rotate(gear[2], dir); // C를 돌림
                    if (gear[2][2] == gear[3][6]) {
                        rotate(gear[3], dir * -1); // D를 돌림
                    }
                }
            }
            break;
        case 1: // 톱니 B를 돌림
            if (gear[1][6] == gear[0][2]) {
                rotate(gear[0], dir * -1); // A를 돌림
            }
            if (gear[1][2] == gear[2][6]) {
                rotate(gear[2], dir * -1); // C를 돌림
                if (gear[2][2] == gear[3][6]) {
                    rotate(gear[3], dir); // D를 돌림
                }
            }
            break;
        case 2: // 톱니 C를 돌림
            if (gear[2][6] == gear[1][2]) {
                rotate(gear[1], dir * -1); // 톱니 B를 돌림
                if (gear[1][6] == gear[0][2]) {
                    rotate(gear[0], dir); // 톱니 A를 돌림
                }
            }
            if (gear[2][2] == gear[3][6]) {
                rotate(gear[3], dir * -1); // 톱니 D를 돌림
            }
            break;
        case 3: // 톱니 D를 돌림
            if (gear[3][6] == gear[2][2]) {
                rotate(gear[2], dir * -1); // C를 돌림
                if (gear[2][6] == gear[1][2]) {
                    rotate(gear[1], dir); // B를 돌림
                    if (gear[1][6] == gear[0][2]) {
                        rotate(gear[0], dir * -1); // A를 돌림
                    }
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == '1') {
            score += (1 << i);
        }
    }
    cout << score << endl;
}

int main(void)
{
    solve();

    return 0;
}