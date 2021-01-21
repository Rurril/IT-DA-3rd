#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int arr[32] = { 0 };
vector<int> vec(16,1);

int main() {
	bool tf = true;
    stack<int> st;
	string str;
	int a = 0, _a = 0, result=0, k=0,v=0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			arr[i] = 2;
			st.push(2);
		}
		else if (str[i] == '[')
		{
			arr[i] = 3;
			st.push(3);
		}
		else
		{
			arr[i] = 0;
			if (str[i] == ')' && st.top() == 2)
				st.pop();
			else if (str[i] == ']' && st.top() == 3)
				st.pop();
		}
	}
	if (!st.empty())
		cout << 0;
	else {
		a = 1;
		_a = 0;
		for (int i = 1; i < str.length(); i++)
		{
			if (a == _a)
			{
				k = i;
				a++;
				continue;
			}
				
			if (arr[i] == 0) {
				if (arr[i - 1] != 0)
				{
					_a++;
					vec[v] *= arr[k];
					v++;
				}
				else
					_a++;
			}
			else {
				a++;
				vec[v] *= arr[i];
			}
			
		}
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == 1)
				break;
			result += vec[i];
		}
		cout << result;
	}
}