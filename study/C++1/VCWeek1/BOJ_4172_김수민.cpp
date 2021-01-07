#include <iostream>
#include <cmath>
using namespace std;

long long x[1000001];
int i;


int main()
{
	
	x[0] = 1;
	for (int j=1; j<1000000; j++){
			int v1 = floor(j - sqrt(j));
			int v2 = floor(log(j));
			int v3 = floor( j * sin(j) * sin(j));
			x[j] = (x[v1] + x[v2]  + x[v3])%1000000;
	}
	while (true) {
		cin >> i;
		if (i == -1) {
			break;
		}
		cout << x[i]<<"\n";
	}
}

