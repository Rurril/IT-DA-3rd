#include<iostream>
using namespace std;
int n, sum;
char map[5][5];
int i = 0, j = 0;


// 최대는 연산자 우선순위를 고려해서 * + - 순으로 가면 되겠네
// 최소는 그 반대로


char getMin(int y, int x) {
	if (x >= n - 1) {
		i++;
		return map[y+1][x];
	}
	if (y >= n - 1) {
		j++;
		return map[y][x+1];
	}
	if (map[y][x + 1]  < map[y + 1][x]  ) { j++; return map[y][x+1]; }
	else { i++; return map[y + 1][x]; }
}


char getMax(int y, int x) {
	if (x >= n - 1) {
		i++;
		return map[y+1][x];
	}
	if (y >= n - 1) {
		j++;
		return map[y][x+1];
	}
	if (map[y][x + 1] > map[y + 1][x]) { j++; return map[y][x + 1];}
	else { i++; return map[y + 1][x]; }
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	i = 0;j = 0;
	sum = map[0][0] -'0';
	while (i < n && j< n) {//최댓값
		char op = getMin(i, j);
		int q = getMax(i, j)-'0';
		if (op == '+') sum += q;
		else if (op == '-') sum -= q;
		else if (op == '*') sum *= q;
	}
	cout << sum<<endl;
	sum = map[0][0] - '0';i = 0;j = 0;
	while ((j < n && i < n)) {//최솟값
		char op = getMax(i,j);
		int q = getMin(i, j) -'0';
		if (op == '+') sum += q;
		else if (op == '-') sum -= q;
		else if (op == '*') sum *= q;
	}
	cout << sum;
}