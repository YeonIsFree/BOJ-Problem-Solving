#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int x, y, d, g;
int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void TEST() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void markBoard(int x, int y, int d, int targetVer) {
    vector<int> dirs;
    dirs.push_back(d);
    // 1) targetVer 까지의 모든 경로를 찾는다.
    for(int v = 0; v < targetVer; v++) {
        int len = dirs.size();
        for(int i = len-1; i >= 0; i--) {
            int dir = dirs[i];
            dirs.push_back((dir + 1) % 4);
        }
    }

    // 2) 해당 방향에 맞춰 이동시켜준다.
    for(int i = 0; i < dirs.size(); i++) {
        int nx = x + dx[dirs[i]];
        int ny = y + dy[dirs[i]];

        board[ny][nx] = 1;

        x = nx;
        y = ny;

    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    cin >> n;
    for(int i = 0; i < n; i++)  {
        cin >> x >> y >> d >> g;
        
        board[y][x] = 1;
        
    // ---- g세대까지의 드래곤커브를 보드에 표시한다.
        markBoard(x, y, d, g);
    }

    int cnt = 0;
    // ---- 조건에 맞는 칸을 세어준다
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(!board[i][j]) continue;
            if(board[i][j+1] && board[i+1][j] && board[i+1][j+1]) cnt++;
        }
    }

    cout << cnt << '\n';

}