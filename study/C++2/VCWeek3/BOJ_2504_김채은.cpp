#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char arr[32];
stack<char> st;
int tmp = 1, sum = 0;
bool wrong = false;

void Solution()
{
	for (int i = 0; arr[i]; i++) {
		if (arr[i] == '(') {
			tmp *= 2;
			st.push('(');
		} else if (arr[i] == '[') {
			tmp *= 3;
			st.push('[');
		} else if (arr[i] == ')') {
			if (arr[i - 1] == '(')
				sum += tmp;
			if (st.empty()) {
				wrong = true;
				break;
			}
			if (st.top() == '(')
				st.pop();
			tmp /= 2;
		} else {
			if (arr[i - 1] == '[')
				sum += tmp;
			if (st.empty()) {
				wrong = true;
				break;
			}
			if (st.top() == '[')
				st.pop();
			tmp /= 3;
		}
	}
}

void Print()
{
	if (wrong || !st.empty())
		cout << 0;
	else
		cout << sum;
}

int main(void)
{
	cin >> arr;

	Solution();
	Print();

	return 0;
}
