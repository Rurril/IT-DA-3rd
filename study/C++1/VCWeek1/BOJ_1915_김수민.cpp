#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[1002][1002];
char temp;
int anw;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= M; j++) {
			cin >> temp;
			a[i][j] = temp - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i][j] == 1) {
				a[i][j] += min(a[i - 1][j], min( a[i][j - 1], a[i - 1][j - 1]));
				anw = max(anw, a[i][j]);
			}
		}
	}

	cout << anw*anw<<"\n";
}

