#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

struct Info {
    int x;
    int y;
    int dir;
    bool isalive;
};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

Info fishList[17];
int board[4][4];
int n, d;
int ans;        

void TEST() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << "(" << board[i][j] << ", " << fishList[board[i][j]].dir << ")" << ' ';
        cout << '\n';
    }
}

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >= 4 || y >= 4) return true;
    return false;
}

void move_fish() {
    for(int i = 1; i <= 16; i++) {
        // 0) 이미 죽어있는 물고기는 넘아간다.
        if(!fishList[i].isalive) continue;

        Info shark = fishList[0];   // 상어 정보
        
        int cx = fishList[i].x;
        int cy = fishList[i].y;
        int cdir = fishList[i].dir;

        // 1) 다음 좌표를 계산해본다.
        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];
        
        // 2) 다음 좌표가 갈 수 없는 곳이면 (상어이거나 경계 밖),
        //    갈 수 있는 좌표 나올 때까지 45도 반시계 회전을 반복
        while(OOB(nx, ny) || (nx == shark.x && ny == shark.y)) {
            cdir = (cdir + 1) % 8;
            nx = cx + dx[cdir];
            ny = cy + dy[cdir];
        }
        fishList[i].dir = cdir;

        // 3) 자리를 바꾼다.
        int target = board[nx][ny];
        board[nx][ny] = i;
        board[cx][cy] = target;

        fishList[target].x = cx;
        fishList[target].y = cy;

        fishList[i].x = nx;
        fishList[i].y = ny;

        // TEST();
        // cout << '\n';
    }
   
}

void DFS(Info shark, int sum) {
    // 0) 수행 전 정보를 저장
    Info fishList_save[17];
    for(int i = 1; i <= 16; i++) fishList_save[i] = fishList[i];

    int board_save[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board_save[i][j] = board[i][j];
    
    Info shark_save = shark;


    // 1) 물고기를 이동시킨다.
    move_fish();

    // 2) 상어를 이동시킨다.
    int nx = shark.x;
    int ny = shark.y;
    while(1) {
        nx = nx + dx[shark.dir];
        ny = ny + dy[shark.dir];

        if(OOB(nx, ny)) break;                              // 다음 칸이 경계를 넘어가면 멈춘다.
        if(!fishList[board[nx][ny]].isalive) continue;      // 다음 칸이 빈 칸(죽은 물고기) 이면 넘어간다.
        
        // 다음 물고기를 먹는다.
        fishList[0] = fishList[board[nx][ny]];              // 상어 정보를 잡아먹은 물고기의 정보로 갱신
        fishList[board[nx][ny]].isalive = false;            // 잡아먹힌 물고기 죽은 상태로 변경

        // 이번 물고기를 먹은 상태에서 한번 더 들어간다.
        DFS(fishList[0], sum + board[nx][ny]);

        // 복구
        fishList[0] = shark_save;
        fishList[board[nx][ny]].isalive = true;
    } // 상어가 더 이상 이동할 수 없음

    ans = max(ans, sum);

    // 복구
    for(int i = 1; i <= 16; i++) fishList[i] = fishList_save[i];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = board_save[i][j];
    
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> n >> d;
            fishList[n] = {i, j, d-1, true};
            board[i][j] = n;
        }
    }

    // 1. 상어가 (0, 0)에 있는 물고기를 먹는다.
    int first_fish = board[0][0];                        // 여태 먹은 물고기 번호의 합
    fishList[first_fish].isalive = false;       // 해당 물고기를 죽은 상태로 변경
    fishList[0] = fishList[first_fish];         // 상어 정보를 먹은 물고기의 정보로 업데이트

    // 2. DFS
    DFS(fishList[0], first_fish);

    cout << ans;

}