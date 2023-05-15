#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int, int> > cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int x, int y, int dir) {
    // 와 대박, 
    // 밑에서 함수가 func(x, y, dir+2) 처럼 불릴때 dir = 3 이어서 func(x, y, 5) 처럼 들어올 때도 고려해야 한다.
    // 따라서 여기서 5를 4로 나눈 나머지를 사용
    dir = dir % 4;
    while(1) {
        // 처음에 나는 nx, ny라는 새로운 변수를 뒀는데, 그러면 앞으로 한칸씩 점진적으로 나아가질 못한다.
        x += dx[dir];
        y += dy[dir];
        // 
        if(x < 0 || x >= n || y < 0 || y >= m || board2[x][y] == 6) return;
        // 다른 cctv는 지나친다.
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 입력 받기
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            // cctv 위치는 따로 저장해둔다.
            if(board1[i][j] == 6 || board1[i][j] == 0) continue;
            cctv.push_back({i, j});
        }
    }
    
    // 초기 사각 지대 최소 크기 = 입력 받은 상태 그대로의 0 갯수
    int mn_cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(board1[i][j] == 0) mn_cnt++;
    }

    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
        // board2 초기화
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        }
        
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++) {
            // 4진법으로 변환
            int dir = brute % 4; // 지금 쓸 방향이 된다.
            brute /= 4;

            int x = cctv[i].X;
            int y = cctv[i].Y;

            if(board1[x][y] == 1) {
                func(x, y, dir);
            }
            else if(board1[x][y] == 2) {
                func(x, y, dir);
                func(x, y, dir + 2);
            }
            else if(board1[x][y] == 3) {
                func(x, y, dir);
                func(x, y, dir + 1);
            }
            else if(board1[x][y] == 4) {
                func(x, y, dir);
                func(x, y, dir + 1);
                func(x, y, dir + 2);
            }
            else {
                func(x, y, dir);
                func(x, y, dir + 1);
                func(x, y, dir + 2);
                func(x, y, dir + 3);
            }
        } // 모든 cctv에 대한 검토 완료
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board2[i][j] == 0) cnt++;
            }
        }
        mn_cnt = min(mn_cnt, cnt);
    
    } // 모든 방향 경우의 수에 대한 탐색 완료

    cout << mn_cnt;
}