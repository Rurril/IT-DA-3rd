#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//14496 그대, 그머가 되어

int N, M;
int g[1002][1002];
int result[1002];
bool visited[1002];

void check(int a, int b) {
	queue <int> start; //시작 지점을 담는 큐
	start.push(a);
	visited[a] = true;
	
	while (!start.empty()) {

		int tmpstart = start.front();
		start.pop();
		if (tmpstart== b) { 
			return;
		}
		for (int i = 1; i <= N; i++) {
			if ((visited[i] == false)) {//방문안한 지점이고
				if (g[tmpstart][i] == 1) { //치환 가능하면
					visited[i] = true;
					start.push(i);
					result[i] = result[tmpstart]+1; //최소 치환 횟수 = 시작한 지점의 최소 치환 횟수 + 1 
				}
			}
		}
	}
}
	


int main()
{
	int a,b;
	cin >> a >> b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p, q;
		cin >> p >> q;
		g[p][q] = g[q][p] = 1;
	}
	check(a, b);
	
	if (a == b) {
		cout << 0;
	}
	else if (visited[b]==false) {
		cout << -1;
	}
	else {
		cout << result[b];
	}
    
}
