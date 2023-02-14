#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[503][503];
bool vis[503][503];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int num = 0;
    int mx = 0;
    // 이중 for 문을 돌면서 bfs의 시작점이 될 수 있는 지점을 찾는다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 이때 이미 방문한 칸이나 그림이 없는 칸은 그냥 지나친다.
            if(vis[i][j] || board[i][j] == 0) continue;
            // 여기에 진입 했다는 것은 새 그림을 발견했다는 뜻
            num++; 
            
            // 이제 bfs를 돌린다.
            queue<pair<int, int> > Q;
            vis[i][j] = 1;
            Q.push({i, j});

            int area = 0;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;
}