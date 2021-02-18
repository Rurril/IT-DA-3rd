#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int map[3002][3002];
int movea[4] = { 0,0,-1,1 };
int moveb[4] = { 1,-1,0,0 };
int result = 9999999;
bool visited[3002][3002];
int tmpmap[3002][3002];
deque <pair<int, int>> q; //시작 지점들 담을 디큐

void bfs(int a, int b) {
	int newa, newb;
	
	for (int i = 0; i < n; i++) { //최소값을 담기 위해 큰 값으로 초기화
		for (int j = 0; j < m; j++) {
			tmpmap[i][j] = 9999999;
		}
	}
	tmpmap[a][b] = 0;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop_front();
		
		for (int i = 0; i < 4; i++) {
			newa = a + movea[i];
			newb = b + moveb[i];
			if ((newa >= 0) && (newa < n) && (newb >= 0) && (newb < m) &&(map[newa][newb]!='1')&&(visited[newa][newb]==false)){
				visited[newa][newb] = true;
				tmpmap[newa][newb] = tmpmap[a][b] + 1; //거리는 전 지점의 거리 +1

				if ((map[newa][newb] == '3') or (map[newa][newb] == '4') or (map[newa][newb] == '5')) { //먹을 것에 도달하면 결과 업뎃
					result = min(result, tmpmap[newa][newb]);
				}
				else if (map[newa][newb] == '0') { //0이면 시작지점 추가
					q.push_back({ newa,newb });
				}
			}
		}
	}
	

}


int main()
{
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == '2') { //시작지점 저장
				q.push_front({ i, j });
			}
		}
	}
	bfs(q.front().first, q.front().second);
	if (result == 9999999) {
		cout << "NIE";
	}
	else {
		cout << "TAK\n"<<result;
	}
    
}

