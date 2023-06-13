#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[2001];
bool ans;
bool vis[2001];

void dfs(int cur, int depth) {
    
    // 깊이가 5가 됐으면 발견 성공. 함수를 종료한다.
    if(depth == 5) {
        ans = true;
        return;
    }  

    // 현재 노드를 방문했다고 표시
    vis[cur] = true;

    // 현재 노드와 연결된 애들 중 방문 안한 것에 대해 DFS 실행
    for(int nx : adj[cur]) {
        if(vis[nx]) continue;
        dfs(nx, depth+1);
    }

    // 여기 도달했다는 것은 함수가 끝나지 못했다는 것
    vis[cur] = false; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        dfs(i, 1);
        if(ans) break;
    }

    if(ans) cout << 1 << '\n';
    else cout << 0 << '\n';
    
}