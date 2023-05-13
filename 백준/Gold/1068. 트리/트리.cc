#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[52]; // 부모 노드 정보 들어있는 배열
bool vis[52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;

    vector<vector<int> > adj(n);

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) continue;
        else if(arr[i] == 0) adj[0].push_back(i);
        else {
            int mother = arr[i];
            adj[mother].push_back(i);
        }
    }

    // BFS를 돌려서 삭제할 노드와 그 자식 노드까지 모두 1이라 표시해준다.
    queue<int> Q;
    Q.push(m);
    vis[m] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        if(adj[i].size() == 1 && adj[i][0] == m) cnt++;
        else if(adj[i].empty()) cnt++;
    }
    cout << cnt;
}