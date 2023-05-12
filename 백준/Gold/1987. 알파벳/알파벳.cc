#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;
string board[23];
int vis[26];
int ans;

void dfs(int x, int y, int depth) {
    ans = max(depth, ans);
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        int idx = board[nx][ny] - 'A';
        if(vis[idx] == 1) continue;
        vis[idx] = 1;
        dfs(nx, ny, depth + 1);
        vis[idx] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        cin >> board[i];

    vis[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << ans;
}
