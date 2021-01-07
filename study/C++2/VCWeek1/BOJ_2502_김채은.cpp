#include <iostream>

using namespace std;

int day, k;
int one, two;

int fibo(int i, int j, int day)
{
	int three;

	one = i;
	two = j;
	day = day-2;
	while(day--)
	{
		three = one + two;
		one = two;
		two = three;
	}
	return three;
}

int main(){
	int ans;

	cin >> day >> k;

	for(int i=1; i<=k; i++)
	{
		for(int j=i; j<=k; j++)
		{
			ans = fibo(i, j, day);
			if (ans == k){
				cout << i <<endl;
				cout << j <<endl;
				return (0);
			}
		}
	}

	return (0);
}


