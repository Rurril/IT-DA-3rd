#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack <char> st;

	long long int result = 0;
	long long int t = 1;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{

		if (s[i] == '(')
		{
			st.push('(');
			t *= 2;
		}
		else if (s[i] == '[')
		{
			st.push('[');
			t *= 3;
		}
		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << 0;
				return 0;
			}
			else if (st.top() == '(')
			{
				if (s[i - 1] == '(')
					result += t;

				t /= 2;
				st.pop();
			}

		}
		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << 0;
				return 0;
			}
			else if (st.top() == '[')
			{
				if (s[i - 1] == '[')
					result += t;

				t /= 3;
				st.pop();
			}
			
		}
	}
	if (!st.empty()) cout << 0;
	else cout << result;
}
