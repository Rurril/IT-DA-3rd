#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int shape[19][4][2] = {
{ 0,0,0,1,0,2,0,3 }, // ========
{ 0,0,1,0,2,0,3,0 },

{ 0,0,0,1,1,0,1,1 }, //==
					 //==

{ 0,0,1,0,2,0,2,1 }, //==
{ 1,0,1,1,1,2,0,2 }, //== 
{ 0,0,0,1,1,1,2,1 }, //==
{ 0,0,1,0,0,1,0,2 }, //====

{ 0,1,1,1,2,1,2,0 }, //  == 
{ 0,0,0,1,0,2,1,2 }, //  ==
{ 0,0,1,0,2,0,0,1 }, //  == 
{ 0,0,1,0,1,1,1,2 }, //====

{ 0,0,1,0,1,1,2,1 }, //==
{ 1,0,1,1,0,1,0,2 }, //======
{ 2,0,1,0,1,1,0,1 }, //    ==
{ 0,0,0,1,1,1,1,2 },

{ 0,0,0,1,1,1,0,2 }, //========
{ 0,1,1,0,1,1,2,1 }, //   ==
{ 1,0,1,1,0,1,1,2 },
{ 0,0,1,0,2,0,1,1 }
};

int sum, big;
int map[501][501];
int N, M;


int run() {

	int cnt = 19;
	while (cnt-- > 0) {

		for (int y = 0; y < N; y++) {//y축으로 이동
			if (shape[cnt][3][0] + y >= N || shape[cnt][2][0] + y >= N || shape[cnt][0][0] + y >= N || shape[cnt][1][0] + y >= N ) break;
			for (int x = 0; x < M; x++) { //x축으로 움직일 때
				sum = 0;
				if (shape[cnt][2][1] + x >= M || shape[cnt][3][1] + x >= M || shape[cnt][0][1] + x >= M || shape[cnt][1][1] + x >= M) break;


				sum += map[shape[cnt][0][0] + y][shape[cnt][0][1] + x];
				sum += map[shape[cnt][1][0] + y][shape[cnt][1][1] + x];
				sum += map[shape[cnt][2][0] + y][shape[cnt][2][1] + x];
				sum += map[shape[cnt][3][0] + y][shape[cnt][3][1] + x];

				big = max(sum, big);
			}
		}
	}
	return big;
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	cout << run();
}
