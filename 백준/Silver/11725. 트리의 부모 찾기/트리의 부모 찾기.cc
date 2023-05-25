#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100002];
int p[100002];

void bfs(int root) {
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(p[cur] == nx) continue;
            Q.push(nx);
            p[nx] = cur;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for(int i = 2; i <= n; i++)
        cout << p[i] << '\n';
}