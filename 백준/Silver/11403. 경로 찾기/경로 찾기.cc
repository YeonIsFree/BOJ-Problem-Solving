#include <bits/stdc++.h>
using namespace std;

int n, tmp;
vector<vector<int> > adj(103);
bool ans[103][103];
bool vis[103]; // y 좌표 방문했는지 확인하는 배열

void bfs(int st) {
    fill(vis, vis+n, 0);
    queue<int> Q;
    Q.push(st);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
            ans[st][nx] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 0) continue;
            adj[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++) bfs(i);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}