#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1003];
vector<int> result;
int deg[1003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    int prev = 0;
    while(m--) {
        int num = 0;
        cin >> num;

        vector<int> tmp;
        while(num--) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }

        // 전후 관계를 adj 배열에 담고, indegree를 하나씩 증가시킴.
        for(int i = 0; i < tmp.size() - 1; i++) {
            int prev = tmp[i];
            int nxt = tmp[i+1];
            adj[prev].push_back(nxt);
            deg[nxt]++;
        }

    } // 모든 피디들의 제안 종료

    queue<int> Q;
        for(int i = 1; i <= n; i++)
            if(deg[i] == 0) Q.push(i);
        
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            result.push_back(cur);
            for(int nx : adj[cur]) {
                deg[nx]--;
                if(deg[nx] == 0) Q.push(nx);
            }
        }

        if(result.size() != n) cout << 0 << '\n';
        else {
            for(int i : result) 
                cout << i << '\n';
        }
}