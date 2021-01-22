#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int W, H; cin >> W >> H;
	int arr[500];
	for (int i = 1; i <= H; i++)
		cin >> arr[i];

	int answer = 0;

	int sti = -1, edi = -1;
	for (int i = 1; i <= H; i++)
	{
		if (sti == -1 && edi == -1 && arr[i] > 0)
			sti = i;
		else if (sti!=-1&&edi == -1 && arr[i] >= arr[sti] || sti != -1 && i==H&&arr[i]>0)
		{
			edi = i;

			int width = edi - sti + 1;
			int height = (arr[edi] < arr[sti]) ? arr[edi] : arr[sti];

			for (int j = sti + 1; j < edi; j++)
				answer += height - arr[j];
			//cout << sti << " " << edi << " " << answer << endl;

			sti = -1, edi = -1;
		}
	}

	cout << answer;

	return 0;
}
