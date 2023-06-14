#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<vector<int> > adj(1002);
bool vis[1002];

void dfs(int x) {
    cout << x << ' ';
    vis[x] = true;
    for(int nx : adj[x]) {
        if(vis[nx]) continue;
        dfs(nx);
    }
}

void bfs(int x) {
    fill(vis, vis+n, false);

    queue<int> Q;

    Q.push(x);
    vis[x] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for(int nx : adj[cur]) {
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> m >> st;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 방문할 수 있는 정점이 여러 개일 때 작은 정점부터 방문하기 위해 sort
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

    // DFS
    dfs(st);
    cout << '\n';

    // BFS 하기 전 vis 배열 초기화
    fill(vis+1, vis+1+n, false);
    
    // BFS
    bfs(st);

}