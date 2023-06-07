#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m, st, en;
vector<pair<int, int>> adj[1003];
int d[1003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(d, d+n+1, INF);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    cin >> st >> en;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    d[st] = 0;
    Q.push({d[st], st});
    while(!Q.empty()) {
        auto cur = Q.top(); Q.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nx : adj[cur.Y]) {
            if(d[nx.Y] <= d[cur.Y] + nx.X) continue;
            d[nx.Y] = d[cur.Y] + nx.X;
            Q.push({d[nx.Y], nx.Y});
        }
    }
    cout << d[en];
}