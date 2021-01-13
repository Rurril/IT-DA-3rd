#include <iostream>
using namespace std;
pair<int,int> arr[31];
int main() {
	int D, K,A=0,B=0;
	cin >> D >> K;
	arr[1] = make_pair(1, 0);
	arr[2] = make_pair(0, 1);
	for (int i = 3; i <= D; i++)
		arr[i] = make_pair(arr[i - 1].first + arr[i - 2].first, arr[i - 1].second + arr[i - 2].second);
	int x = arr[D].first;
	int y = arr[D].second;
	for (int i = 1; i <= K / x; i++)
	{
		if ((K - x * i) % y != 0)
			continue;
		else {
			cout << i<<endl<< (K - x * i) / y;
			break;
		}
	}
	
}