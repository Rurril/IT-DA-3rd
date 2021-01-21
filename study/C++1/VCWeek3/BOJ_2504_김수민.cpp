#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
string s; 
vector <int> v; //쌍을 확인할 벡터 v
int result = 0;

int main()
{
	int temp=1; //곱해서 더해줄 값
	int index = 0; //붙어 있는 괄호만 계산하기 위한 인덱스
	cin >> s;
	
	for (int i = 0; i < s.size();i++) {
		if (v.empty()) { //하나의 괄호 계산이 끝나고 새로운 괄호가 시작될 때
			if (s[i] == '(') { temp *= 2; }
			if (s[i] == '[') { temp *= 3; }
			v.push_back(s[i]);
			index = i;
			continue;
		}
		if (s[i] == '(') { temp *= 2; }
		if (s[i] == '[') {temp *= 3;}

		if (v.back() == '(') { //')'이 오면 계산해서 pop하고, 나머지가 오면 벡터에 push
			if (s[i] == ')') {
				if (i - index == 1) {
					result += temp;
				}
				temp /= 2;
				v.pop_back();
				continue;
			}
			else if ((s[i] == '(') or (s[i] == '[') or(s[i]==']')) {
				v.push_back(s[i]);
				index = i;
				continue;
			}
		
		}
		else if (v.back() == '[') { //']'가 오면 계산하고 pop하고, 나머지가 오면 벡터에 push
			if (s[i] == ']') {
				if (i - index == 1) {
					result += temp;
				}
				temp /= 3;
				v.pop_back();
				continue;
			}
			else if ((s[i] == '(') or (s[i] == ')') or (s[i] == '[')) {
				v.push_back(s[i]);
				index = i;
				continue;
			}
			
		}
		else { //시작이 '('나 '['가 아니거나 위에 continue에 걸리지 않을 경우->올바르지 못한 괄호
			cout << "0";
			return 0;
		}
		
	}
	if (!v.empty()) { //벡터가 안비어있으면 짝이 안맞는 괄호
		cout << "0";
		return 0;
	}
	cout << result;
		
	
    
}

