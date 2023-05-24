#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > adj(52);
int dist[52];
int score[52];
vector<int> candi;

void bfs(int i) {
    queue<int> Q;
    fill(dist, dist+n+1, -1);
    Q.push(i);
    dist[i] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : adj[cur]) {
            if(dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx); 
        }
    }
    
    int tmp = *max_element(dist+1, dist+n+1);
    if(tmp == 0) score[i] = 99;
    else score[i] = tmp;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) bfs(i);   // score 배열에 각각의 점수가 들어간다.

    int mn = *min_element(score+1, score+n+1);  // 회장이 될 애들 점수
    for(int i = 1; i <= n; i++) {
        if(score[i] != mn) continue;
        candi.push_back(i);
    }

    cout << mn << ' ' << candi.size() << '\n';
    for(int i : candi) cout << i << ' ';
}