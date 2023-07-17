#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int board[10][10];
bool vis[10][10];
int ans, mx;
vector<pair<int, int>> blanks;

int find_safe_area() {
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(vis[i][j] == false && board[i][j] == 0) cnt++;
    return cnt;
}

// BFS 는 바이러스를 퍼뜨리는 함수
void bfs() {
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + 10, false);
    queue<pair<int, int> > Q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 2) {
                Q.push({i, j});
            }
        }
    }
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        vis[cur.first][cur.second] = true;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 0) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) blanks.push_back({i, j});
        }
    }
    
    // -----
    // 1) *** 벽 3개를 설치할 위치를 결정한다.
    // 이 3가지 조합들을 어떻게 구해낼까...!  --> 아 그냥 3중 for 문 돌면 되네...!
    int safe_area = blanks.size();
    for(int i = 0; i < blanks.size(); i++) {
        board[blanks[i].first][blanks[i].second] = 1;
        for(int j = i+1; j < blanks.size(); j++) {
            board[blanks[j].first][blanks[j].second] = 1;
            for(int k = j+1; k < blanks.size(); k++) {
                board[blanks[k].first][blanks[k].second] = 1;
                bfs();
                mx = max(mx, find_safe_area());
                board[blanks[k].first][blanks[k].second] = 0;
            }
            board[blanks[j].first][blanks[j].second] = 0;
        }
        board[blanks[i].first][blanks[i].second] = 0;
    }
    // 2) 각 경우의 수 마다의 안전 영역을 구한다.
    //  2-1) 먼저 BFS로 바이러스를 퍼뜨린다.
    //  2-2) 
    // 3) 안전 영역의 최대 크기를 갱신해준다.

    cout << mx;

}