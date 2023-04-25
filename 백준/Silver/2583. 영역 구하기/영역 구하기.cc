#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;
pair<int, int> a;
int board[103][103];
int vis[103][103];
int cnt;
vector<int> ans;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;
  for (int t = 0; t < k; t++){
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    for (int y = sy; y < ey; y++) {
      for (int x = sx; x < ex; x++)
        board[y][x] = 1;
    }
  }

  queue<pair<int, int>> Q;

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == 1 || vis[i][j] == 1) continue;
      Q.push({i, j});
      cnt++;
      vis[i][j] = 1;
      int area = 1;
      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
          if (board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
          Q.push({nx, ny});
          vis[nx][ny] = 1;
          area++;
        }
      }
      ans.push_back(area);
    }
  }
  sort(ans.begin(), ans.end());
  cout << cnt << '\n';
  for(int i : ans) 
    cout << i << ' ';
  
}