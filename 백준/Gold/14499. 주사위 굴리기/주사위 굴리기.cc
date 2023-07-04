#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};  // 동 0, 서 1, 북 2, 남 3
int dy[4] = {1, -1, 0, 0};

int BOTTOM = 0, TOP = 1, FRONT = 2, REAR = 3, LEFT = 4, RIGHT = 5;

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

int roll(int dir, int x, int y) {
    // 각 방향에 따른 회전
    if(dir == 0) // 동
        rotate(BOTTOM, LEFT, TOP, RIGHT);
    else if(dir == 1)  // 서
        rotate(BOTTOM, RIGHT, TOP, LEFT);
    else if(dir == 2)  // 북
        rotate(BOTTOM, FRONT, TOP, REAR);
    else if(dir == 3)  // 남
        rotate(BOTTOM, REAR, TOP, FRONT);

    // 지도에 써있는 숫자가
    //  1) 0 이면 주사위 -> 지도
    if(board[x][y] == 0) board[x][y] = dice[BOTTOM];
    //  2) 0 이 아니면 지도 -> 주사위, 지도는 0 이 됨
    else {
        dice[BOTTOM] = board[x][y];
        board[x][y] = 0;
    }

    return dice[TOP];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    // ---------
    while(k--) {
        int dir = 0;
        cin >> dir;
        dir -= 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        int top = roll(dir, nx, ny);
        cout << top << '\n';

        x = nx;
        y = ny;
    }
}