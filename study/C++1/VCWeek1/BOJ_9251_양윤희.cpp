#include <iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
string one, two;
char arr1[1001];
char arr2[1001];
int count1[1001][1001];
int cnt;
int result;
void run() {
	for (int i = 0; i < two.size(); i++) {
		count1[i + 1][1] = count1[i][1];
		for (int j = 0; j < one.size(); j++) {
			if (arr2[i] == arr1[j]) {
				count1[i + 1][j + 1] = count1[i][j] + 1;
			}
			else {
				count1[i + 1][j + 1] = max(count1[i][j + 1], count1[i + 1][j]);
			}
		}
	}
}

int main(void) {
	cin >> one >> two;
	for (int i = 0; i < one.size(); i++) {
		arr1[i] = one.at(i);
	}
	for (int i = 0; i < two.size(); i++) {
		arr2[i] = two.at(i);
	}
	run();
	cout << count1[two.size()][one.size()];
}