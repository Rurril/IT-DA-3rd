#include <iostream>
#include <string>
using namespace std;

/*
 * L(i, j) : Xi와 Yj의 LCS 길이
 *
 * i=0, j=0 : L(i, j)=0
 * xi = ji : L(i, j) = L(i-1, j-1) + 1
 * xi != ji : L(i, j) = max{ L(i, j-1), L(i-1, j)}
 */

string s1, s2;
int L[1001][1001] = {0, };
int ans;

void LCS(int i, int j) {
	if (i == 0 || j == 0)
		L[i][j] = 0;
	else{
		if (s1[i] == s2[j])
			L[i][j] = L[i-1][j-1] + 1;
		else
			L[i][j] = (L[i][j-1] > L[i-1][j]) ? L[i][j-1] : L[i-1][j];
	}
}

void Solution(){
	unsigned int i, j;

	for(i=1; i <= s1.size(); i++)
		for(j=1; j <= s2.size(); j++)
			LCS(i, j);

	cout << L[s1.size()][s2.size()];
}

int main() {
	cin >> s1 >> s2;

	Solution();

	return (0);
}
