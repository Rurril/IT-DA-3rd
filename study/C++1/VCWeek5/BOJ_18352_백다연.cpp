#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
//18352
//X로부터 출발하여 도달할 수 있는 도시 중에서, 최단 거리가 K인 모든 도시의 번호
//수정해야함
int n,m,k,x;
vector <int> answer;
vector <int> v[300001];
int visit[300001];

void bfs(int first)
{
    queue<int> q;
    q.push(first);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i]; //출발점과 연결된 노드
            if(visit[next] == 0) //방문한적 없다면
            {
                visit[next] = visit[now] + 1; // 출발지로부터 거리 저장
                q.push(next);
            }
        }


    }
}



int main()
{
    //도시개수, 도로개수, 거리정보, 출발도시
    cin >> n >> m >> k >> x; 

    for(int i = 0; i <m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    visit[x] = 0; //출발하는 곳
    bfs(x);

    for(int i = 1; i <=n; i++)
    {
        if(visit[i] == k)
            answer.push_back(i);
    }

    if(answer.size()== 0)
        cout << -1 << endl;
    
    else
    {
        sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++)
            cout << answer[i] << endl;
    }
    



    
    return 0;
}