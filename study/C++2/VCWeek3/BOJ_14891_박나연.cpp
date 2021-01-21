#include<iostream>
using namespace std;

int W[5][205] = { 0, };


void Wheel_turning(int N, int c) {
	if (c == 1)// 시계 방향
	{
		int temp = W[N][8];
		for (int i = 8; i > 1; i--) {
			W[N][i] = W[N][i - 1];
		}
		W[N][1] = temp;

	}
	else {
		int temp = W[N][1];
		for (int i = 1; i < 8; i++) {
			W[N][i] = W[N][i + 1];
		}
		W[N][8] = temp;
	}
}


int main() {




	string a;
	for (int i = 1; i <= 4; i++) {
		cin >> a;
		for (int j = 1; j <= a.length(); j++) {
			W[i][j] = a[j - 1] - '0';

		}
	}

	/*for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			cout << W[i][j];

		}
		cout << endl;
	}*/
	int K;
	cin >> K;


	for (int i = 0; i < K; i++) {
		/*for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			cout << W[i][j];

		}
		cout << endl;
	}*/
		int N;
		int c;
		int ac;

		cin >> N;
		cin >> c;

		if (c == 1) {
			ac = -1;
		}
		else {
			ac = 1;
		}

		if (N == 1) {
			if (W[N][3] != W[N + 1][7]) {
				if (W[N + 1][3] != W[N + 2][7]) {
					if (W[N + 2][3] != W[N + 3][7]) {
						Wheel_turning(N, c);
						Wheel_turning(N + 1, ac);
						Wheel_turning(N + 2, c);
						Wheel_turning(N + 3, ac);
					}
					else {
						Wheel_turning(N, c);
						Wheel_turning(N + 1, ac);
						Wheel_turning(N + 2, c);
					}
				}
				else {
					Wheel_turning(N, c);
					Wheel_turning(N + 1, ac);
				}
			}
			else {
				Wheel_turning(N, c);
			}
		}
		else if (N == 2) {
			if (W[N][7] != W[N - 1][3]) {
				Wheel_turning(N - 1, ac);
			}
			if (W[N][3] != W[N + 1][7]) {
				if (W[N + 1][3] != W[N + 2][7]) {
					Wheel_turning(N, c);
					Wheel_turning(N + 1, ac);
					Wheel_turning(N + 2, c);
				}
				else {
					Wheel_turning(N, c);
					Wheel_turning(N + 1, ac);
				}
			}
			else {
				Wheel_turning(N, c);
			}
		}
		else if (N == 3) {
			if (W[N][3] != W[N + 1][7]) {
				Wheel_turning(N + 1, ac);
			}
			if (W[N][7] != W[N - 1][3]) {
				if (W[N - 1][7] != W[N - 2][3]) {
					Wheel_turning(N, c);
					Wheel_turning(N - 1, ac);
					Wheel_turning(N - 2, c);
				}
				else {
					Wheel_turning(N, c);
					Wheel_turning(N - 1, ac);
				}
			}
			else {
				Wheel_turning(N, c);
			}
		}
		else if (N == 4) {
			if (W[N][7] != W[N - 1][3]) {
				if (W[N - 1][7] != W[N - 2][3]) {
					if (W[N - 2][7] != W[N - 3][3]) {
						Wheel_turning(N, c);
						Wheel_turning(N - 1, ac);
						Wheel_turning(N - 2, c);
						Wheel_turning(N - 3, ac);
					}
					else {
						Wheel_turning(N, c);
						Wheel_turning(N - 1, ac);
						Wheel_turning(N - 2, c);
					}
				}
				else {
					Wheel_turning(N, c);
					Wheel_turning(N - 1, ac);
				}
			}
			else {
				Wheel_turning(N, c);
			}

		}

	}

	int answer = 0;

	/*cout << W[1][1] << endl;;
	cout << W[2][1]<<endl;
	cout << W[3][1] << endl;
	cout << W[4][1] << endl;*/

	answer = W[1][1] + 2 * W[2][1] + 4 * W[3][1] + 8 * W[4][1];

	cout << answer;



}