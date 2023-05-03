#include <bits/stdc++.h>
using namespace std;

vector<int> arr[103];
bool vis[103];
int v, e, cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v;
    cin >> e;
    for(int i = 0; i < e; i++) {
        int a, b = 0;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cnt++;
        for(int nx : arr[cur]) {
            if(vis[nx]) continue;
            vis[nx] = true;
            Q.push(nx); 
        }
    }

    cout << cnt - 1;
}