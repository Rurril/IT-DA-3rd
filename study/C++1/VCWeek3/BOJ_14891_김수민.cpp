#include <iostream>
#include <algorithm>
#include <cstring>
int t[4][8];
bool turn[4];
int N, ck;
int anw;
using namespace std;


int main()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> t[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		memset(turn, false, sizeof(turn));
		int j;
		cin >> j >> ck;
		j = j - 1;
		turn[j] = true;
		for (int k = j; k > 0; k--) { //왼쪽으로 가며 체크
			if (turn[k] == true) {
				if (t[k][6] == t[k - 1][2]) {
					continue;
				}
				else {
					turn[k - 1] = true;
					if (ck == 1) { //반시계로 돌기
						int tmp;
						tmp = t[j][0];
						for (int i = 0; i < 7; i++) {
							t[j][i] = t[j][i + 1];
						}
						t[j][7] = tmp;
					}

					else if (ck == -1) { //시계로 돌기
						int tmp;
						tmp = t[j][7];
						for (int i = 1; i < 8; i++) {
							t[j][i] = t[j][i - 1];
						}
						t[j][0] = tmp;
					}
				}

			}
			else {
				continue;
			}
		}
		for (int k = j; k < 4; k++) {
			if (turn[k] == true) {
				if (t[k][2] == t[k + 1][6]) {
					continue;
				}
				else {
					// 반대방향 회전
					turn[k + 1] = true;
					if (ck == 1) { //반시계로 돌기
						int tmp;
						tmp = t[j][0];
						for (int i = 0; i < 7; i++) {
							t[j][i] = t[j][i + 1];
						}
						t[j][7] = tmp;
					}

					else if (ck == -1) { //시계로 돌기
						int tmp;
						tmp = t[j][7];
						for (int i = 1; i < 8; i++) {
							t[j][i] = t[j][i - 1];
						}
						t[j][0] = tmp;
					}
				}
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (t[i][0] == 1) {
			if (i == 0) { anw += 1; }
			else if (i == 1) { anw += 2; }
			else if (i == 2) { anw += 4; }
			else { anw += 8; }
		}
	}
	cout << anw;
}
