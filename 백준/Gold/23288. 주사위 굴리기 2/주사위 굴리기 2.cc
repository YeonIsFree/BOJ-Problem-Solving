#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};  // 동 0, 남 1, 서 2, 북 3
int dy[4] = {1, 0, -1, 0};

int BOTTOM = 0, TOP = 1, FRONT = 2, REAR = 3, LEFT = 4, RIGHT = 5;

int n, m, k;
int board[22][22];
int dice[6] = {6, 1, 2, 5, 4, 3};
int total;

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return true;
    return false;
}

int BFS(int target, int x, int y) {
    queue<pair<int, int>> Q;
    bool vis[22][22];
    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+m, false);

    Q.push({x, y});
    vis[x][y] = true;
    int area = 1;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(vis[nx][ny] || board[nx][ny] != target) continue;
            area++;
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
    return area;
}

void rotate(int a, int b, int c, int d) {
    int tmp = dice[d];
    dice[d] = dice[c];
    dice[c] = dice[b];
    dice[b] = dice[a];
    dice[a] = tmp;
}

void roll(int dir, int x, int y) {
    // 동
    if(dir == 0) rotate(BOTTOM, LEFT, TOP, RIGHT);
    // 남
    else if(dir == 1) rotate(BOTTOM, FRONT, TOP, REAR);
    // 서
    else if(dir == 2) rotate(BOTTOM, RIGHT, TOP, LEFT); 
    // 북
    else if(dir == 3) rotate(BOTTOM, REAR, TOP, FRONT);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< m; j++) {
            cin >> board[i][j];
        }
    }

    // ----
    int dir = 0;        // 초기 방향은 동쪽
    int x = 0, y = 0;   // 초기 주사위의 위치는 (0, 0)
    while(k--) {
        // 0. 다음 칸 계산
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 1. 만약 다음 칸이 보드의 경계라면 반대 방향으로
        if(OOB(nx, ny)) {
            if(dir == 0) dir = 2;
            else if(dir == 1) dir = 3;
            else if(dir == 2) dir = 0;
            else if(dir == 3) dir = 1;

            //  좌표를 다시 계산해준다. 
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        //   굴리고
        roll(dir, nx, ny);
        //   다음 칸으로 좌표 갱신 한다.
        x = nx;
        y = ny;

        // 2. 도착한 칸에 대한 점수 획득
        //    --> 도착한 칸에 써있는 숫자로 BFS()를 돌려서 연속 이동 가능한 칸이 곧 점수가 된다.
        int score = BFS(board[x][y], x, y);
        total += score * board[x][y];

        // cout << "=======" << '\n';
        // cout << "이번 스코어: " << score << '\n';
        // cout << "현재 주사위 바닥: " << dice[BOTTOM] << '\n';
        // cout << "아랫면 보드 숫자: " << board[x][y] << '\n';
        // cout << "이전 방향: " << dir << '\n';
        // cout << "주사위 전개도: " << '\n';
        // cout << ' ' << dice[FRONT] << ' ' << '\n';
        // cout << dice[LEFT] << dice[TOP] << dice[RIGHT] << '\n';
        // cout << ' ' << dice[REAR] << ' ' << '\n';
        // cout << ' ' << dice[BOTTOM] << ' ' << '\n';

        // 3. 다음 이동 방향을 결정
        if(dice[BOTTOM] > board[x][y]) dir = (dir + 1) % 4;
        else if(dice[BOTTOM] < board[x][y]) {
            dir = (dir - 1);
            if(dir < 0) dir = 3;
        }

        // cout << "이번 방향: " << dir << '\n';
        // cout << '\n';
    }
   
    cout << total;
}