#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[510][510] = { 0 };
int main() {
	int N, M, cnt = 0, cnt_temp = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cnt_temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			cnt = max(cnt, cnt_temp);
			cnt_temp -= arr[i][j + 3];
			for (int k = 0; k < 3; k++)
			{
				cnt_temp += arr[i - 1][j + k];
				cnt = max(cnt, cnt_temp);
				cnt_temp -= arr[i - 1][j + k];
				cnt_temp += arr[i + 1][j + k];
				cnt = max(cnt, cnt_temp);
				cnt_temp -= arr[i + 1][j + k];
			}
			cnt_temp -= arr[i][j + 2];
			for (int k = 0; k < 3; k++)
			{
				cnt_temp = cnt_temp + arr[i - 1][j + k] + arr[i - 1][j + k - 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp = cnt_temp - arr[i - 1][j + k] - arr[i - 1][j + k - 1];
				cnt_temp = cnt_temp + arr[i + 1][j + k] + arr[i + 1][j + k - 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp = cnt_temp - arr[i + 1][j + k] - arr[i + 1][j + k - 1];
			}
			cnt_temp = 0; // 세로

			cnt_temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			cnt = max(cnt, cnt_temp);
			cnt_temp -= arr[i + 3][j];
			for (int k = 0; k < 3; k++)
			{
				cnt_temp += arr[i + k][j - 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp -= arr[i + k][j - 1];
				cnt_temp += arr[i + k][j + 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp -= arr[i + k][j + 1];
			}
			cnt_temp -= arr[i + 2][j];
			for (int k = 0; k < 3; k++)
			{
				cnt_temp = cnt_temp + arr[i + k][j - 1] + arr[i + k - 1][j - 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp = cnt_temp - arr[i + k][j - 1] - arr[i + k - 1][j - 1];
				cnt_temp = cnt_temp + arr[i + k][j + 1] + arr[i + k - 1][j + 1];
				cnt = max(cnt, cnt_temp);
				cnt_temp = cnt_temp - arr[i + k][j + 1] - arr[i + k - 1][j + 1];
			}
			cnt_temp = 0; //가로
		}
	}
	cout << cnt;
}