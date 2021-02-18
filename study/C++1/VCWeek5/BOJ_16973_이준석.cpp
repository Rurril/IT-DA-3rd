#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1002][1002] = { 0 };
int col[1002][1002] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M, H, W, Sr, Sc, Fr, Fc, cnt = 3000;
bool check(int x, int y, int i)
{
	if (i == 0) {
		for (int i = y; i < y + W; i++)
		{
			if (i>M || x + H > N || arr[x + H][i] == 1)
				return false;
		}
	}
	else if (i == 1) {
		for (int i = y; i < y + W; i++)
		{
			if (i>M || x<=1 || arr[x - 1][i] == 1)
				return false;
		}
	}
	else if (i == 2) {
		for (int i = x; i < x + H; i++)
		{
			if (i>N || y+W>M || arr[i][y + W] == 1)
				return false;
		}
	}
	else if (i == 3) {
		for (int i = x; i < x + H; i++)
		{
			if (i>N || y<=1 || arr[i][y - 1] == 1)
				return false;
		}
	}
	return true;
}
int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	queue<pair<int, int>>q;
	queue<int>result;
	q.push(make_pair(Sr, Sc));
	result.push(0);
	col[Sr][Sc] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = result.front();
		q.pop();
		result.pop();
		if (x == Fr && y == Fc)
		{
			cout << z;
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= M && arr[x + dx[i]][y + dy[i]] == 0 && col[x + dx[i]][y + dy[i]] == 0)
			{
				if (check(x,y,i))
				{
					q.push(make_pair(x + dx[i], y + dy[i]));
					col[x + dx[i]][y + dy[i]] = 1;
					result.push(z + 1);
				}
			}	
		}
	}
	cout << -1;
}
	
