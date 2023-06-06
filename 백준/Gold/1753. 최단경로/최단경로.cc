#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int v, e, k;

vector<pair<int, int> > adj[20005]; // {비용, 정점 번호}
int d[20005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    cin >> k;

    fill(d, d+v+1, INF);

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    d[k] = 0;
    pq.push({d[k], k}); // {0, 시작점}
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nx : adj[cur.Y]) {
            if(d[nx.Y] <= d[cur.Y] + nx.X) continue;
            d[nx.Y] = d[cur.Y] + nx.X;
            pq.push({d[nx.Y], nx.Y});
        }
    }

    for(int i = 1; i <= v; i++) {
        if(d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}