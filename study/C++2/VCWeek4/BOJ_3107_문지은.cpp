#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':')
			cnt++;
	}

	int tcnt = 0;
	string ns;

	for (int i = 0; i <= s.length(); i++)
	{
		if (s[i] == ':')
		{
			//fill 0
			for (int j = 0; j < 4 - tcnt; j++)
				ns += '0';

			for (int j = tcnt; j >= 1; j--)
				ns += s[i - j];

			ns += ':';

			if (s[i + 1] == ':')
			{
				for (int i = 0; i < 8 - cnt; i++)
					ns += "0000:";

				i++;
			}

			tcnt = -1;
		}
		if (i == s.length())
		{
			for (int j = 0; j < 4 - tcnt; j++)
				ns += '0';

			for (int j = tcnt; j >= 1; j--)
				ns += s[i - j];
		}

		tcnt++;
	}

	cout << ns;

}
