#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
char arr[14][8];
int col[14][8] = { 0 };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int>v;

void drop() {

	fill(col[0], col[0] + 112, 0);
}
int main() {
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			cin >> arr[i][j];
	int cnt = 0, result = 0, answer=0;
	queue <pair<int, int>>q;
	while (1) {
		for (int i = 12; i > 0; i--)
		{
			for (int j = 1; j <= 6; j++)
			{
				cnt = 0;
				vector<int>vt;
				if (arr[i][j] == '.' || col[i][j] == 1)
					continue;
				else if(arr[i][j]!='.' && col[i][j]==0){
					q.push(make_pair(i, j));
					col[i][j] = 1;
					vt.push_back(j);
					cnt++;
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++)
						{
							if (arr[x + dx[k]][y + dy[k]] == arr[x][y] && col[x + dx[k]][y + dy[k]]==0)
							{
								q.push(make_pair(x + dx[k], y + dy[k]));
								col[x + dx[k]][y + dy[k]] = 1;
								vt.push_back(y + dy[k]);
								cnt++;
							}
						}
					}
					if (cnt >= 4)
					{
						result++;
						for (int l = 0; l < vt.size(); l++) {
							for (int m = 12; m >= 2; m--)
								arr[m][vt[l]] = arr[m - 1][vt[l]];
						}
					}
					
				}

			}
		}
		if (result > 0) {
			answer++;
			cnt = 0;
			result = 0;
			drop();
		}
		else {
			
			break;
		}
	}
	
	cout << answer;
	
}