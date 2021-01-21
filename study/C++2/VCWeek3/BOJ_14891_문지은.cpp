#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string c[5];
vector <pair <int, int>> v;

void roll(int sel, int d)
{
	if (d == -1)
	{
		char temp = c[sel][0];
		for (int i = 0; i <= 6; i++)
		{
			c[sel][i] = c[sel][i + 1];
		}
		c[sel][7] = temp;
	}
	else if (d == 1)
	{
		char temp = c[sel][7];
		for (int i = 7; i >= 1; i--)
		{
			c[sel][i] = c[sel][i - 1];
		}
		c[sel][0] = temp;
	}
}

void func(int sel, int d)
{
	int selT = sel;
	int selL = sel - 1;
	int selR = sel + 1;
	int dT = d;

	v.push_back(make_pair(sel, d));

	//left
	while (selL >= 1)
	{
		if (c[selT][6] == c[selL][2])
		{
			selL = 0;
		}
		else
		{
			if (dT == 1)
			{
				v.push_back(make_pair(selL, -1));
				dT = -1;
			}
			else
			{
				v.push_back(make_pair(selL, 1));
				dT = 1;
			}
			selT = selL;
			selL--;
		}
	}

	selT = sel;
	dT = d;
	//right
	while (selR <= 4)
	{
		if (c[selT][2] == c[selR][6])
		{
			selR = 5;
		}
		else
		{
			if (dT == 1)
			{
				v.push_back(make_pair(selR, -1));
				dT = -1;

			}
			else
			{
				v.push_back(make_pair(selR, 1));
				dT = 1;
			}
			selT = selR;
			selR++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		roll(v[i].first, v[i].second);
	}
}

int main()
{
	int ans = 0;

	for (int i = 1; i <= 4; i++)
	{
		cin >> c[i];
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		v.clear();

		int sel, d;
		cin >> sel >> d;

		func(sel, d);	
	}

	for (int i = 1; i <= 4; i++)
	{
		if (c[i][0] == '1')
			ans += pow(2, i-1);
	}

	cout << ans;
	

}
