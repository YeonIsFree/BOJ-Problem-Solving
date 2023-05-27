#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > adj[1003];
bool vis[1003];

// okay 간선이 2개일때 오류가 난다!!!!! 합을 매번 pair로 가져가야겠다. 

void func(int st, int en) {
    queue<pair<int, int> > Q;
    Q.push({st, 0});
    vis[st] = true;
    while(!Q.empty()) {
        auto [cur, dist] = Q.front(); Q.pop();
        if(cur == en) {
            cout << dist << '\n';
            return;
        }
        for(auto [nx, nx_dist] : adj[cur]) {
            if(vis[nx]) continue;
            Q.push({nx, dist + nx_dist});
            vis[nx] = true;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n-1; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    while(m--) {
        fill(vis, vis+n+1, false);
        int a, b;
        cin >> a >> b;
        func(a, b);
    }
}