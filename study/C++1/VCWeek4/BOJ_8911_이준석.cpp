#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int>result;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;
		int x = 0, y = 0, pointer = 0;
		int WW = 0, HH = 0, W = 0, H = 0; //WW,HH는 양수, W,H는 음수
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'R')
			{
				pointer += 1;
				if (pointer == 4)
					pointer = 0;
			}
			else if (str[j] == 'L')
			{
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
			}
			else if (str[j] == 'F')
			{
				if (pointer == 0)
					y += 1;
				else if (pointer == 1)
					x += 1;
				else if (pointer == 2)
					y -= 1;
				else if (pointer == 3)
					x -= 1;
			}
			else if (str[j] == 'B')
			{
				if (pointer == 0)
					y -= 1;
				else if (pointer == 1)
					x -= 1;
				else if (pointer == 2)
					y += 1;
				else if (pointer == 3)
					x += 1;
			}
			if (x < 0)
				W = min(W, x);
			else if (x >= 0)
				WW = max(WW, x);

			if (y < 0)
				H = min(H, y);
			else if (y >= 0)
				HH = max(HH, y);
		}
		result.push_back((WW - W) * (HH - H));
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	
}