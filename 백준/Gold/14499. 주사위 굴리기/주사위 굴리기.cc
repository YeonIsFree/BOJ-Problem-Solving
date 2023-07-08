#include <bits/stdc++.h>
using namespace std;

int TOP = 0, BOTTOM = 1, FRONT = 2, REAR = 3, LEFT = 4, RIGHT = 5;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m, x, y, k;
int board[22][22];
int dice[6];

void rotate(int a, int b, int c, int d) {
    int tmp = dice[d];
    dice[d] = dice[c];
    dice[c] = dice[b];
    dice[b] = dice[a];
    dice[a] = tmp;
}

void roll(int dir, int x, int y) {
    // 주사위를 굴린다.
    if(dir == 0) // 동
        rotate(BOTTOM, LEFT, TOP, RIGHT);
    else if(dir == 1) // 서
        rotate(BOTTOM, RIGHT, TOP, LEFT);
    else if(dir == 2) // 북
        rotate(BOTTOM, FRONT, TOP, REAR);
    else if(dir == 3)// 남
        rotate(BOTTOM, REAR, TOP, FRONT);

    // 보드의 상태에 따른 액션
    if(board[x][y] == 0) {
        board[x][y] = dice[BOTTOM];
    }
    else {
        dice[BOTTOM] = board[x][y];
        board[x][y] = 0;
    }

    cout << dice[TOP] << '\n';
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    // ---
    for(int i = 0; i < k; i++) {
        int dir = 0;
        cin >> dir;
        dir -= 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        roll(dir, nx, ny);

        x = nx;
        y = ny;
    }
}