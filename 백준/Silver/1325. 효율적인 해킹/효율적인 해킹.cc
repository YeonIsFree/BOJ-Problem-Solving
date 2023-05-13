#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt_arr[10003];
bool vis[10003];
vector<int> ans;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<vector<int> > adj(n+1);

    while(m--) {
        int a = 0, b = 0;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    queue<int> Q;
    int mx = -1;
    for(int i = 1; i <= n; i++) {
        // 방문 배열, 카운트 초기화
        fill(vis, vis + n+1, 0);
        int cnt = 0;
        Q.push(i);
        vis[i] = true;
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nx : adj[cur]) {
                if(vis[nx]) continue;
                Q.push(nx);
                vis[nx] = 1;
                cnt++;
            }
        }
        cnt_arr[i] = cnt;
        mx = max(mx, cnt);
    }

    for(int i = 1; i <= n; i++) {
        if(cnt_arr[i] != mx) continue;
        ans.push_back(i);
    }

    for(int i : ans)
        cout << i << ' ';
}