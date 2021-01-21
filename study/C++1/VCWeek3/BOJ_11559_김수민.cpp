#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char g[12][6];
char visited[12][6];
int anw = 0;
bool flag;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
vector <pair<int, int>> wlist;

void dfs(int a, int b) { //dfs 돌며 터질만한 뿌요들 wlist에 넣기
	for (int i = 0; i < 4; i++) {
		int newa = a + x[i];
		int newb = b + y[i];
		if ((g[a][b] == g[newa][newb]) && (newa >= 0) && (newa < 12) && (newb >= 0) && (newb < 6)&&(visited[newa][newb]==false)&&(g[newa][newb]!='.')) {
			visited[newa][newb] = true;
			wlist.push_back(make_pair(newa, newb));
			dfs(newa, newb);
		}
	}
}

void dropBuyo() { //뿌요 터지고 밑에 비어있음으면 끌어 내리는 함수
	for (int i = 0; i < 6; ++i) {
		for (int j = 11; j >= 0; --j) {
			if (g[j][i] != '.') continue;

			int move = j; //.인 부분 높이 저장
			while (true) {
				if (move < 0) break;
				if (g[move][i] != '.') { //뿌요 있는 부분 찾아서
					g[j][i] = g[move][i]; //.인 부분에 넣어주고
					g[move][i] = '.'; //넣어준 부분은 .으로 바꿔준다
					break;
				}
				move--;
			}
		}
	}
}


int main()
{
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> g[i][j];
		}
	}
	while (true) {
		flag = false;
		wlist.clear();
		memset(visited, false, sizeof(visited));
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; ++j) {
				if ((g[i][j] != '.') && (visited[i][j] == false)) {
					wlist.push_back(make_pair(i, j));
					visited[i][j] = true;
					dfs(i, j); //모든 점들에 대해 dfs 돌기

					if (wlist.size() >= 4) { //터질 게 4개 이상이면
						flag = true; //한번에 두개 터지면 연쇄 하나로 세야되니까 바로 연쇄에 더해주면 안된다.
						for (int k = 0; k < wlist.size(); k++) { //뿌요 터뜨리기
							int p = wlist[k].first;
							int q = wlist[k].second;
							g[p][q] = '.';

						}
					}
					wlist.clear();
					
				}
			}
		}
		dropBuyo(); //한바탕 터지고 뿌요 내려주기

		if (flag == true) { anw++; }
		else break;

	}
	
    cout << anw <<endl;
}

