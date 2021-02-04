#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[100001];
int team[100001];

int teamNum;

void check(int i)
{
	vector <int> v;
	v.clear();

	v.push_back(i);
	int temp = arr[i];

	while (team[temp] != 1)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == temp)
			{
				for (int k = j; k < v.size(); k++)
				{
					teamNum++;
					team[v[k]] = 1;
				}
			}
		}

		v.push_back(temp);
		temp = arr[temp];
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		memset(arr, 0, sizeof(int) * 100001);
		memset(team, 0, sizeof(int) * 100001);
		teamNum = 0;

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			if (arr[i] == i)
			{
				team[i] = 1;
				teamNum++;
			}

		}

		for (int i = 1; i <= n; i++)
		{
			if (team[i] == 0) check(i);
		}

		cout << n - teamNum << endl;
	}
}
