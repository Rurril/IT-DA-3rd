#include <iostream>

#define Max(x, y)   (x) > (y) ? (x) : (y)

using namespace std;

int N, M;
int table[510][510] {};
int maxSum = 0;

const int shape1[4][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}}; // ㅣ
const int shape2[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // ㅁ
const int shape3[4][2] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}}; // ㄱ
const int shape4[4][2] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}}; // 꺾임
const int shape5[4][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 1}}; // ㅗ

pair<int, int> rotation(int r, int c, int angle)
{
    pair<int, int> result;
    if (angle == 0) {
        result = {r, c};
    }
    else if (angle == 90) {
        result = {c, -r};
    }
    else if (angle == 180) {
        result = {-r, -c};
    }
    else if (angle == 270) {
        result = {-c, -r};
    }

    return result;
}

pair<int, int> flip(int r, int c, int axis)
{
    pair<int, int> result;
    if (axis == 0) {
        result = {r, c};
    }
    else if (axis == 1) {
        result = {c, r};
    }

    return result;
}

void trial(const int shape[4][2], int r, int c)
{
    int axis[2] = {0, 1};
    int angle[4] = {0, 90, 180, 270};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                pair<int, int> flipped = flip(shape[k][0], shape[k][1], i);
                pair<int, int> rotated = rotation(flipped.first, flipped.second, j);
                pair<int, int> result = {r + rotated.first, c + rotated.second};
                if (result.first < N && result.first >= 0 && result.second < M && result.second >= 0) {
                    sum += table[result.first][result.second];
                    maxSum = Max(sum, maxSum);
                }
                else {
                    break;
                }
            }
        }
    }
}

void solve(void)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            trial(shape1, i, j);
            trial(shape2, i, j);
            trial(shape3, i, j);
            trial(shape4, i, j);
            trial(shape5, i, j);
        }
    }
    cout << maxSum << endl;
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}