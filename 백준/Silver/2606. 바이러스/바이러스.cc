#include <bits/stdc++.h>
using namespace std;

int v, e;
int cnt;
vector<int> pc[103];
bool vis[103];

void bfs() {
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cnt++;
        for(int nx : pc[cur]) {
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b = 0;
        cin >> a >> b;
        pc[a].push_back(b);
        pc[b].push_back(a);
    }
    bfs();
    cout << cnt - 1;
}