#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
string S;
int cnt = 0;
vector <char> result;
vector <int> temp;

void Ipv6() { //Ipv6 주소 채우기
	for (int i = 0; i < 4 - temp.size();i++) {
		result.push_back('0');
	}
	for (int i = 0;i < temp.size();i++) {
		result.push_back(temp[i]);
	}
	result.push_back(':');
	temp.clear();
	return;
}

void putZero() { //::일 경우 0 채우기
	for (int i = 0; i < 8 - cnt;i++) {
		for (int j = 0; j < 4; j++) {
			result.push_back('0');
		}
		result.push_back(':');
	}
}
int main()
{
	
	cin >> S;
	
	for (int i = 1; i < S.size();i++) { //생략되는 부분 제외한 덩어리 구하는 
		if (S[i] == ':') {
			if (((S[i - 1] >= '0') && (S[i - 1] <= '9')) or ((S[i - 1] >= 'a') && (S[i - 1] <= 'f'))) {
				cnt++;
			}
		}
		if (i == S.size() - 1) {
			if (((S[i] >= '0') && (S[i] <= '9')) or ((S[i] >= 'a') && (S[i] <= 'f'))) {
				cnt++;
			}
		}
	}
	if (S[0] != ':') {
		temp.push_back(S[0]);
	}
	for (int i = 1; i < S.size();i++) {
		if (S[i] != ':') { //주소면
			temp.push_back(S[i]); 
			if (i==S.size()-1) { //마지막 덩어리 처리
				Ipv6();
			}
		}
		if (S[i] == ':') { //:를 만나면 
			if (S[i - 1] == ':') { //::일 경우
				putZero();
			}
			else {
				Ipv6(); //그 전 숫자들을 Ipv6주소에 넣기
			}
		
		}
	
	}
	for (int i = 0; i < 39; i++) {
		cout << result[i];
	}
}
