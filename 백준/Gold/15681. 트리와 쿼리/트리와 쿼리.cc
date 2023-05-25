#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj[100002];
bool vis[100002];
int subtree_size[100002];

int cnt(int cur) {
    vis[cur] = true;
    for(int nx : adj[cur]) {
        if(vis[nx]) continue;
        subtree_size[cur] += cnt(nx);
    }

    subtree_size[cur] += 1;
    
    return subtree_size[cur];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> q;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cnt(r);

    while(q--) {
        int root;
        cin >> root;
        cout << subtree_size[root] << '\n';
    }
}