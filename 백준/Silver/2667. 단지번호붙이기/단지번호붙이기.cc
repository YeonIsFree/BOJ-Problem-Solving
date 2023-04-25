#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
string board[28];
int vis[28][28];
int cnt;
vector<int> ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
  }
  
  queue<pair<int, int> > Q;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '0' || vis[i][j] == 1) continue;
      vis[i][j] = 1;
      cnt++;
      Q.push({i, j});

      int area = 1;
      while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
          Q.push({nx, ny});
          vis[nx][ny] = 1;
          area++;
        }
      }
      ans.push_back(area);
    }
  }
  cout << cnt << '\n';
  sort(ans.begin(), ans.end());
  for(int i : ans) cout << i << '\n';

  return 0;
}
