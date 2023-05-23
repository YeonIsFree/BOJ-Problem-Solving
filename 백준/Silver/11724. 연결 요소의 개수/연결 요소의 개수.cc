#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
vector<vector<int> > adj(1003);
bool vis[1003];

int bfs() {
    int cnt = 0;
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        cnt++;
        Q.push(i);
        vis[i] = true;
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nx : adj[cur]) {
                if(vis[nx]) continue;
                Q.push(nx);
                vis[nx] = true;
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   cout << bfs();
    
}