#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;

long long int arr[1000001] = { 0, };

int f1(double i) { return (int)floor(i - sqrt(i)); }
int f2(double i) { return (int)floor(log10(i)); }
int f3(double i) { return (int)floor(i * pow(sin(i), 2)); }
void cal(int i)
{
	for (int j = 1; j <= i; j++)
	{
		if (arr[j] == 0)
		{
			arr[j] = ((arr[f1(j)] + arr[f2(j)] + arr[f3(j)])%1000000);
		}
	}
}

int main()
{
	double i;
	cin >> i;

	arr[0] = 1;
	vector <int> v;

	while (i != -1)
	{
		if (i == 0)
			v.push_back(1);
		else
		{
			if (arr[f1(i)] == 0) cal(f1(i));
			if (arr[f2(i)] == 0) cal(f2(i));
			if (arr[f3(i)] == 0) cal(f3(i));
			cout << arr[f1(i)] << " "<< arr[f2(i)]<<" " << arr[f3(i)] << endl;
			v.push_back((arr[f1(i)] + arr[f2(i)] + arr[f3(i)]) % 1000000);
		}
		
		cin >> i;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}