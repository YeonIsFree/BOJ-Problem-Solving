#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[503][503];
bool vis[503][503];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int> > Q;
    int cnt = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || vis[i][j] == true) continue;
            Q.push({i, j});
            vis[i][j] = true;
            cnt++;

            int area = 0;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue; 
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            mx = max(mx, area);
        }
    }
    cout << cnt << '\n' << mx;

}