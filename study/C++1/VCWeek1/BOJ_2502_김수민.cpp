#include <iostream>
using namespace std;
int D, K;
int day1cnt, day2cnt;
int day1, day2;
int fibo(int cnt) {
	if (cnt <= 1) {
		return 1;
	}
	else {
		return fibo(cnt - 1) + fibo(cnt - 2);
	}

}
int main()
{
	cin >> D >> K;
	int day1cnt = fibo(D - 3);
	int day2cnt = fibo(D - 2);
	for (day1 = 0; day1 < D; day1++) {
		for (day2 = 0; day2 < D; day2++) {
			if (day1cnt * day1 + day2cnt * day2 == K) {
				cout << day1<<"\n";
				cout << day2;
				return 0;
			}
			return 0;
		}
	}
}
