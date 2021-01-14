#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 'm';
		return 0;
	}

	int i = 1;
	int p = 3;
	while (i < n)
	{
		int tp = p;
		if (p <= 3)
		{
			i += 3;
			if (i == n)
			{
				cout << 'm';
				return 0;
			}
		}
		else
		{
			while (tp > 3)
			{
				i += tp;
				tp--;

				if (i == n)
				{
					cout << 'm';
					return 0;
				}

				i += 3;
				if (i == n)
				{
					cout << 'm';
					return 0;
				}
		}
		

		}
		p++;
	}

	cout << 'o';

}
