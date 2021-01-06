#include <iostream>
#include <cmath>

#define MAX_SIZE 1000001
using namespace std;

int arr[MAX_SIZE];

void Init() {
	arr[0] = 1;

	for (int i = 1; i < MAX_SIZE; i++) {
		int sqrtNum = (int)floor(i - sqrt(i));
		int logNum = (int)log(i);
		int sinNum = (int)(i * sin(i) * sin(i));

		arr[i] = (arr[sqrtNum] + arr[logNum] + arr[sinNum]) % (MAX_SIZE - 1);
	}
}

void Solution() {
	while (true) {
		int num;
		cin >> num;

		if (num == -1)
			break;

		cout << arr[num] << endl;
	}
}

int main() {

	Init();

	Solution();

	return 0;
}
