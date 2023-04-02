#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[1003][1003];
int dist[1003][1003];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;

  // 입력을 받으면서 익은 토마토는 큐에 넣고, 익지 않은 토마토는 dist = -1로 바꾼다.
  // 익은 토마토가 들어있거나 토마토가 아예 안들어있는 곳은 dist = 0 이다.

  // dist 배열에는 안들어있는거에 0, 익은거에 0, 안익은거에 -1 표시 되어 있음

  queue<pair<int, int> > Q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(board[i][j] == 0) dist[i][j] = -1;
      if(board[i][j] == 1) Q.push({i, j});
    }
  }
  
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0) continue;
      Q.push({nx, ny});
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }

  cout << ans;

}