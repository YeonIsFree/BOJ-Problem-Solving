#include <bits/stdc++.h>
using namespace std;

int v, e;
int cnt;
vector<int> adj[103];
// { [1| 2, 5],  [2| ],  [3| ],  [] ...}
bool vis[103];

void bfs() {
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cnt++;
        for(auto nx : adj[cur]) {
            // 이미 감염된 pc면 패스
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    // 1번 컴퓨터 카운트는 하나 빼주기
    cout << cnt - 1;

}