#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<vector<int> > adj(1003);
bool vis[10003];

void dfs(int num) {
    vis[num] = true;
    cout << num << ' ';
    for(auto nx : adj[num]) {
        if(vis[nx]) continue;
        dfs(nx);
    }
}

void bfs(int num) {
    queue<int> Q;
    Q.push(num);
    vis[num] = true;
    cout << num << ' ';
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
            cout << nx << ' ';
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << '\n';
    fill(vis+1, vis+n+1, false);
    bfs(v);
}