#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > adj[1003];
bool vis[1003];

void bfs(int st, int en) {
    fill(vis, vis+n+1, 0);
    queue<pair<int, int> > Q;
    Q.push({st, 0});
    vis[st] = true;
    while(!Q.empty()) {
        auto [cur, dist] = Q.front(); Q.pop();

        for(auto [nx, nx_dist] : adj[cur]) {
            if(vis[nx]) continue;
            Q.push({nx, dist + nx_dist});
            vis[nx] = true;

            if(nx == en) {
                cout << dist + nx_dist;
                return;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
        cout << '\n';
    }
}