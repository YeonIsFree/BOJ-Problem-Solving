#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[22][22];
int dice[6];

int TOP = 0, BOTTOM = 1, FRONT = 2, REAR = 3, LEFT = 4, RIGHT = 5;

int dx[4] = {0, 0, -1, 1}; // 동 서 북 남 순서로.
int dy[4] = {1, -1, 0, 0};

bool isOOB(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void rotate(int a, int b, int c, int d) {
    int tmp = dice[d];
    dice[d] = dice[c];
    dice[c] = dice[b];
    dice[b] = dice[a];
    dice[a] = tmp;
}

// 주사위를 해당 방향으로 굴리고 TOP의 값을 반환하는 함수
int roll(int dir, int x, int y) {
    // 주어진 방향에 따라 주사위를 굴려준다.
    if(dir == 0) // 동쪽
        rotate(BOTTOM, LEFT, TOP, RIGHT);
    else if(dir == 1)// 서쪽
        rotate(BOTTOM, RIGHT, TOP, LEFT);
    else if(dir == 2)// 북쪽
        rotate(BOTTOM, FRONT, TOP, REAR);
    else // 남쪽
        rotate(BOTTOM, REAR, TOP, FRONT);
    
    // 바닥면의 값에 따라,
    //  1) 해당 칸의 값이 0 일 경우, 주사위의 값 -> 보드로
    if(board[x][y] == 0)
        board[x][y] = dice[BOTTOM];
    //  2) 해당 칸의 값이 0 이 아닌 경우, 보드의 값 -> 주사위로, 그 뒤 보드는 0
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
    
    // 각 명령어에 맞춰 주사위를 굴려준다.
    while(k--) {
        int dir = 0;
        cin >> dir;
        dir -= 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // board 범위 안에 들어오는지 검사
        if(!isOOB(nx, ny)) continue;

        // 주사위를 해당 방향에 맞게 굴리고 TOP을 출력 한다.
        int top = roll(dir, nx, ny);
        cout << top << '\n';

        // 다음 턴을 위해 현재 위치 갱신
        x = nx;
        y = ny;
    }    
}