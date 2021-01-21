#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

char Map[20][20];
bool visited[20][20];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int boom_cnt = 0;
int temp_cnt = 0;

vector<pair<int, int>> boom_tmp, boom_vec;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
			continue;
		if (Map[nx][ny] == '.')
			continue;
		if (visited[nx][ny] == true)
			continue;
		if (Map[x][y] != Map[nx][ny])
			continue;

		temp_cnt++;
		visited[nx][ny] = true;
		boom_tmp.push_back(make_pair(nx, ny));
		dfs(nx, ny);
	}
}

int main() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> Map[i][j];
		}
	}

	bool Flag;
	int Answer = 0;
	while (1) {
		Flag = false;
		memset(visited, false, sizeof(visited));
		boom_vec.clear();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (Map[i][j] != '.' && visited[i][j] == false) {
					temp_cnt = 1;
					boom_tmp.push_back(make_pair(i, j));
					visited[i][j] = true;
					dfs(i, j);

					if (temp_cnt >= 4) {
						Flag = true;
						for (int i = 0; i < boom_tmp.size(); i++)
						{
							boom_vec.push_back(boom_tmp[i]);
						}
					}
					boom_tmp.clear();
				}
			}
		}
	
		for (int i = 0; i < boom_vec.size(); i++) {
			int x = boom_vec[i].first;
			int y = boom_vec[i].second;

			Map[x][y] = '.';

		}

		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (Map[i][j] == '.')
					continue;
				int Tmp = i;
				while (1) {
					if (Tmp == 11 || Map[Tmp + 1][j] != '.')
						break;
					Map[Tmp + 1][j] = Map[Tmp][j];
					Map[Tmp][j] = ',';
					Tmp++;
				}
			}
		}

		if (Flag == true)
			Answer++;
		else 
			break;
	}

	cout << Answer << endl;


}