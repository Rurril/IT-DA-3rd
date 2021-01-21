#include <iostream>
#include <string>
using namespace std;

string minS;
char minA;
int minI;

string change(string s, int n)		//뒤집기
{
	string newS;
	for (int i = n; i >= 0; i--)
		newS += s[i];
	
	for (int i = n + 1; i < s.length(); i++)
		newS += s[i];
	
	return newS;	
}

void both(string s, int n)
{
	if (s.compare(minS) < 0)
		minS = s;

	if (n > minI)
		return;

	if (n == s.length())
		return;

	//바꾸기
	both(change(s, n), n+1);

	//그대로
	both(s, n + 1);
}

int main()
{
	string s;
	cin >> s;

	minS = s;
	minA = s[0];


	for (int i = 0; i < s.length(); i++)
	{
		if ((int)minA >= (int)s[i])
		{
			minA = s[i];
			if (minI < i) minI = i;
		}
	}

	if (s.length() == 1)
	{
		cout << s;
		return 0;
	}

	both(s, 1);

	cout << minS;

}
