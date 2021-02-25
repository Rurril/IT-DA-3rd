#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;

	cin >> n;
	cin >> s;

	char arr[3] = { 'B', 'L', 'D' };
	int num = 0;
	int size = s.size();

	while (arr[num % 3] == s[0] || arr[num % 3] == s[size - 1])
	{
		if (arr[num % 3] == s[0])
		{
			for (int i = 0; i < s.size(); i++)
			{
				s[i] = s[i + 1];
			}
			size--;
		}
		else if (arr[num % 3] == s[size - 1])
		{
			s[size - 1] = '\0';
			size--;
		}
		num++;
	}

	cout << num;
}
