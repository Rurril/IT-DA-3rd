#include<iostream>
#include <queue>
using namespace std;

int N, M, H, W, SR, SC, FR, FC, ans;
//직사각형의 크기 H,W 시작좌표 SR,SC, 도착좌표 FR,FC
int map[1001][1001];
int visit[1001][1001];
int direct[4][2] = { 1,0,0,-1,-1,0,0,1 }; //위 왼 아래 오

struct Node {
	int x, y, cnt;
};
queue<Node> q;
Node* node;

queue<int> res;

bool move(int y, int x, int direct) {

	if (direct == 0) { //위
		y = y + H - 1;
		if (y >= N)return false;
		for (int i = x; i < W + x; i++) {
			if (map[y][i] == 1 ) return false;
		}
	}
	if (direct == 1) {
		for (int i = y; i < y + H; i++) { //왼
			if (map[i][x] == 1) return false;
		}
	}
	if (direct == 2) {

		for (int i = x; i < W + x; i++) {//아래
			if (map[y][i] == 1)return false;
		}
	}
	if (direct == 3) {
		x = x + W - 1;
		if (x >= M) return false;
		for (int i = y; i < H + y; i++) { //오른
			if (map[i][x] == 1) return false;
		}
	}
	return true;
}
void bfs() {
	while (!q.empty()) {
		Node* now = new Node;
		*now = q.front();
		q.pop();
		int xx = now->x;
		int yy = now->y;
		int go = now->cnt;

		if (yy == FR - 1 && xx == FC - 1) {
			min
		}

		for (int i = 0; i < 4; i++) {
			int ny = yy + direct[i][0];
			int nx = xx + direct[i][1];
			if (visit[ny][nx] == 0 && ny >= 0 && ny < N && nx >= 0 && nx < M) {
				visit[ny][nx] = 1;
				if(move(ny, nx, i)){
					node->x = nx;
					node->y = ny;
					node->cnt = go + 1;
					q.push(*node);
				}
			}
		}
	}
}


int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> H >> W >> SR >> SC >> FR >> FC;
	node = new Node;
	node->x = SC-1;
	node->y = SR-1;
	node->cnt = 0;
	q.push(*node);
	visit[SR-1][SC-1] = 1;
	bfs();
	int min = 999;
	if (res.empty()) {
		cout << -1;
		return 0;
	}
	while (!res.empty()) {
		if (res.front() < min) {
			min = res.front();
			res.pop();
		}
		else { res.pop(); }
	}
	cout << min;
}