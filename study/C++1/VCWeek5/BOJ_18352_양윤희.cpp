#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int N; //도시 개수
int M; //도로 개수
int K; //최단 거리
int X; //출발도시 번호
vector<int> map[300001]; //거리 정보
bool visit[300001];
int dist[300001];
queue<int> que;
priority_queue<int, vector<int>, greater<int>> pq; //우선순위큐 오름차순
int yy, xx;
void bfs() {
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i <map[now].size(); i++) {
			if (visit[map[now][i]] == 0){//방문하지 않은 경우에만 
					visit[map[now][i]] = 1;
					que.push(map[now][i]);
					dist[map[now][i]] = dist[now] + 1; //처음엔 그냥 while문 전체에다가 dist++를 해줘서 4%에서 틀렸었다.
			}
		}
	}	
}

int main(void) {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		cin >> yy >> xx;
		map[yy].push_back(xx);
	}

	que.push(X);//시작점 q에 넣기
	visit[X] = 1; //시작점 방문처리
	bfs();

	for (int i = 0; i <= N; i++) {
		if (dist[i] == K)pq.push(i);
	}
	if (pq.empty()) {
		cout << -1;
		return 0;
	}
	else {
		while (!pq.empty()) {
			cout << pq.top() << endl;
			pq.pop();
		}

	}
	return 0;
}