#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
int n, k;
string l;
string r;
int g[100001][2];
queue <tuple<int,int,int>> start;
int main()
{	
	int result = 0;
	int index; 
	int way;
	int gone;
	int cnt = 0;
	cin >> n >> k;
	cin >> l;
	cin >> r;
	for (int i = 0; i < n; i++) {
		g[i][0] = l[i];
		g[i][1] = r[i];
	}
	start.push(make_tuple(0, 0, 0));
	while (!start.empty()) {
		index = get<0>(start.front());
		way = get<1>(start.front());
		gone = get<2>(start.front());
		start.pop();
		if (index > n - 1) {
			result = 1;
			break;
		}
		if (g[index + 1][way] == '1') {
				start.push(make_tuple(index + 1, way, gone + 1));
			}
		if (index >= 1) {
				if ((g[index - 1][way] == '1') && (index - 1 >= gone)) {
					start.push(make_tuple(index - 1, way, gone + 1));
				}
			}
		if ((g[index + k][(way + 1) % 2] == '1') && (index + k >= gone)) {
				start.push(make_tuple(index + k, (way + 1) % 2, gone + 1));
			}
		
	}
    cout<< result;
}
