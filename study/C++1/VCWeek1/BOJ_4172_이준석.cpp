#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int arr[1000001] = { 0 };
int main() {
	arr[0] = 1;
	int s;
	for (int i = 1; i <= 1000000; i++)
	{
		double a, b, c;
		a = floor(i - sqrt(i));
		b = floor(log(i));
		c = floor(i * sin(i) * sin(i));

		arr[i] = (arr[(int)a] + arr[(int)b] + arr[(int)c])%1000000;
	}
	vector<int>vec;
	while (cin >> s)
	{
		if (s == -1)
			break;
		else {
			vec.push_back(arr[s]);
		}
	}
	for (int i = 0; i<vec.size(); i++)
		cout << vec[i]<<endl;
}