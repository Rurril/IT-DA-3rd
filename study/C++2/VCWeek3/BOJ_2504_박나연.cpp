#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

string N;
stack<char> s;

int main() {

	cin >> N;
	int temp = 1;
	int result = 0;
	for (int i = 0; i < N.size(); i++) {

		if (N[i] == '(') {
			s.push('(');
			temp = temp * 2;
		}
		else if (N[i] == '[') {
			s.push('[');
			temp = temp * 3;
		}
		else if (N[i] == ')') {
			if (N[i-1] == '(') {
				result = result + temp;
			}
			else if(s.empty() || s.top() != '('){
				cout << "0";
				return 0;
			}
			s.pop();
			temp /= 2;
		}
		else if (N[i] == ']') {
			if (N[i - 1] == '[') {
				result = result + temp;
			}
			else if (s.empty() || s.top() != '[') {
				cout << "0";
				return 0;
			}
			s.pop();
			temp /= 3;
		}
		

	}
	if (!s.empty())
		cout << "0" << endl;
	else
		cout << result << endl;


}