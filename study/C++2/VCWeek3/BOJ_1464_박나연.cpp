#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//success
string S;
string answer;

int main() {

	cin >> S;
	answer = S[0];
	for (int i = 1; i < S.length(); i++) {
	
		if (S[i] <= answer[0])
		{
			answer = S[i] + answer;
		}
		else {
			answer += S[i];
		}
	}
	
	cout << answer << endl;

}

