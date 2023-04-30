#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int max_height;
int mx;
int board[103][103];
int vis[103][103];

// -1 : 미방문(안잠김)     0 : 잠김     1 : 안잠긴거 카운팅 

// 물에 잠기는 지역을 표시해주는 BFS
void bfs1(int rain) {
    queue<pair<int, int> > Q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 높아서 안잠기는 곳이나 이미 잠긴 곳은 패스
            if(vis[i][j] != -1 || board[i][j] > rain) continue;
            vis[i][j] = 0;
            Q.push({i, j});
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
            if(vis[nx][ny] != -1 || board[nx][ny] > rain) continue;
            Q.push({nx, ny});
            vis[nx][ny] = 0;
        }
    }
}

// 안잠기는 지역의 갯수를 세어주는 BFS
void bfs2() {
    queue<pair<int, int> > Q;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] != -1) continue;
            cnt++;
            Q.push({i, j});
            vis[i][j] = 1;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
                    if(vis[nx][ny] != -1) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    mx = max(mx, cnt);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] == 1)
                vis[i][j] = -1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_height = max(board[i][j], max_height);
        }
    }
    // 카운팅 한 흔적 초기화 시키기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            vis[i][j] = -1;
    }

    for(int r = 0; r <= max_height; r++) {
        bfs1(r);
        bfs2();
    }
    cout << mx;
}
