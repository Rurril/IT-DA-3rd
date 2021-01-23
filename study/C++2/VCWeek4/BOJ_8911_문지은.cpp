#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int nx, ny, nstatus;

void step(char com, int status, int x, int y)
{
	if (com == 'F')
	{
		nstatus = status;
		if (status == 1)
		{
			nx = x + 1;
			ny = y;
		}
		else if (status == 2)
		{
			nx = x;
			ny = y - 1;
		}
		else if (status == 3)
		{
			nx = x;
			ny = y + 1;
		}
		else if (status == 4)
		{
			nx = x - 1;
			ny = y;
		}
	}
	else if (com == 'B')
	{
		nstatus = status;
		if (status == 1)
		{
			nx = x - 1;
			ny = y;
		}
		else if (status == 2)
		{
			nx = x;
			ny = y + 1;
		}
		else if (status == 3)
		{
			nx = x;
			ny = y - 1;
		}
		else if (status == 4)
		{
			nx = x + 1;
			ny = y;
		}
	}
	else if (com == 'L')
	{
		nx = x;
		ny = y;
		if (status == 1) nstatus = 2;
		else if (status == 2) nstatus = 4;
		else if (status == 3) nstatus = 1;
		else if (status == 4) nstatus = 3;
	}
	else if (com == 'R')
	{
		nx = x;
		ny = y;
		if (status == 1) nstatus = 3;
		else if (status == 2) nstatus = 1;
		else if (status == 3) nstatus = 4;
		else if (status == 4) nstatus = 2;
	}
}

int move(string s)
{
	int minX = 0;
	int minY = 0;
	int maxX = 0;
	int maxY = 0;

	//initialize
	int status = 1;
	int x = 0, y = 0;
	for (int i = 0; i < s.length(); i++)
	{
		//move
		step(s[i], status, x, y);

		x = nx;
		y = ny;
		status = nstatus;

		//compare
		minX = min(minX, x);
		minY = min(minY, y);
		maxX = max(maxX, x);
		maxY = max(maxY, y);
	}

	return (maxX - minX) * (maxY - minY);

}

int main()
{
	int n;
	cin >> n;

	vector <int> v;
	string s;
	int ans;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		ans = move(s);
		v.push_back(ans);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	
}
