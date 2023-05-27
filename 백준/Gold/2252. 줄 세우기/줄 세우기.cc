#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32002];
vector<int> result;
int indegree[32002];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // n = 3 --> 학생은 1, 2, 3 이 있다.
    queue<int> Q;
    while(m--) {
        int a, b;
        cin >> a >> b; // a가 b 앞에 서야 한다.
        adj[a].push_back(b);
        indegree[b]++;
        // 1은 3 앞에 서야 한다.  1 --> 3
        // 2는 3 앞에 서야 한다.  2 --> 3

        // 4는 3 앞에 서야 한다.  4 --> 2
        // 3은 1 앞에 서야 한다.  3 --> 1
    }

    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) Q.push(i);
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        result.push_back(cur);
        for(int nx : adj[cur]) {
            indegree[nx]--;
            if(indegree[nx] == 0) Q.push(nx);
        }
    }

    for(int i : result)
        cout << i << ' ';
}