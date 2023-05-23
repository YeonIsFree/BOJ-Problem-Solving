#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int dist[502];
vector<vector<int>> adj(502);

// 친구의 친구까지 초대 ---> dist[i] 가 3인 친구까지

void bfs() {
    queue<int> Q;
    Q.push(1);
    dist[1] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(dist[nx] > 0) continue;
            Q.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();
    
    for(int i = 2; i <= n; i++)
        if(dist[i] != 0 && dist[i] <= 3) cnt++;
    
    cout << cnt;

}