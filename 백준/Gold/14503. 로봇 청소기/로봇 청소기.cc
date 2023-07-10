#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, x, y, d;
int board[52][52];
int cnt;
bool can_clean;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> m;
    cin >> x >> y >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    // ---
    while(1) {
        // (1) 현재 칸이 청소되지 않은 경우, 청소하고 청소 횟수를 세어준다.
        if(board[x][y] == 0) {
            board[x][y] = 2;
            cnt++;
        }

        can_clean = false;

        // (2) 청소할 곳이 있는 경우 : 전진
        for(int i = 0; i < 4; i++) {
            d = (d+3) % 4;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(board[nx][ny] == 0) {
                can_clean = true;
                x = nx;
                y = ny;
                break;
            }
        }
        if(can_clean) continue;

        // (3) 청소할 곳이 없는 경우 : 후진
        int nx = x - dx[d];
        int ny = y - dy[d];
        if(board[nx][ny] == 1) break;
        else {
            x = nx;
            y = ny;
        }
    }
    cout << cnt;
}