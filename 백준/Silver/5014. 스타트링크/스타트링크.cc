#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int f, s, g, u, d;
int dist[1000003];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> f >> s >> g >> u >> d;
  fill(dist + 1, dist + f + 1, -1);
  // 현재 위치를 0으로 표시
  dist[s] = 0;

  queue<int> Q;
  // 현재 위치를 시작점으로 하여 BFS를 돌린다.
  Q.push(s);
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(int nx : {cur + u, cur - d}) {
      if(nx <= 0 || nx > f) continue;
      if(dist[nx] != -1) continue;
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  if(dist[g] == -1) {
    cout << "use the stairs";
    return 0;
  }
  cout << dist[g];
}