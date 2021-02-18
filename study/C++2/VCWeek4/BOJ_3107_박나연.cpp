#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string ip;
string result;

int main() {

	cin >> ip;

	int count = 0;
	int g = 0; //7개가 있어야 함
	//몇개의 그룹이 있는지
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == ':') {
			//g++;
			if (ip[i + 1] == ':') {
				i++;
				continue;
			}
			g++;
		}
	}
	g++;
	
	for (int i = 0; i < ip.size(); i++) {
		count++;
		if (ip[i] == ':') {
			count--;
			
			for (int j = 0; j < 4-count; j++) {
				result = result + '0';
			}
			for (int j = count; j > 0; j--) {
				result = result + ip[i-j];
			}
			result = result + ':';

			if (ip[i + 1] == ':') {
				int zero = 8 - g-1;
				//cout << zero << endl;
				if (i + 1 != ip.size() - 1) {
					for (int i = 0; i < zero; i++) {
						result = result + "0000:";
					}
				}
				if (i + 1 == ip.size() - 1) {
					for (int i = 0; i < zero; i++) {
						result = result + "0000:";
					}
					result = result + "0000";
				}
				i++;
				//continue;

			}
			count = 0;
		}
		if (ip[i] != ':' && i == ip.size() - 1) {
			for (int j = 0; j < 4 - count; j++) {
				result = result + '0';
			}
			for (int j = count-1; j >= 0; j--) {
				result = result + ip[i - j];
			}
		}
	}
	//cout << g << endl;
	cout << result;

	


}