#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001] = { 0 };
int main() {
	int S;
	cin >> S;
	fill(arr, arr + 1001, 9999999);
	arr[1] = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 2; j * i <= 1000; j++)
		{
			arr[i * j] = min(arr[i * j], arr[i] + j);
		}
		for (int j = 999; j >= 2; j--)
		{
			arr[j] = min(arr[j], arr[j + 1] + 1);
		}
	}
	cout << arr[S];
}