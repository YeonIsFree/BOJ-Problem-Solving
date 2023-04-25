#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, k;
int dist[100002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  fill(dist, dist + 100001, -1);
  dist[n] = 0;

  queue<int> Q;
  Q.push(n);
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(int nx : {cur-1, cur+1, cur*2}) {
      if(nx < 0 || nx > 100000) continue;
      if(dist[nx] != -1) continue;
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  cout << dist[k];
}