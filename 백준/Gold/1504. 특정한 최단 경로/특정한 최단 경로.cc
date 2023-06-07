#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int v, e, v1, v2;
vector<pair<int, int>> adj[803];
int d[803];

long long func(int st, int en) {
    fill(d, d+v+1, INF);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
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
    return d[en];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    long long option1 = func(1, v1) + func(v1, v2) + func(v2, v);
    long long option2 = func(1, v2) + func(v2, v1) + func(v1, v);

    long long ans = min(option1, option2);
    if(ans >= INF) cout << -1;
    else cout << ans;
}