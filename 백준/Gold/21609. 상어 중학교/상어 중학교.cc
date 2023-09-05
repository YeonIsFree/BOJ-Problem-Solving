#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

struct Info {
    int x;
    int y;
    int area;
    int rainbow;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, total;
int board1[22][22];
int board2[22][22];
int biggest[22][22];

void TEST1() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board1[i][j] << ' ';
        }
        cout << '\n';
    }
}

void TEST2() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board2[i][j] << ' ';
        }
        cout << '\n';
    }
}

void TEST_final() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << biggest[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) return true;
    return false;
}

void board_copy() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            biggest[i][j] = board2[i][j];
}

void fall() {
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            // 떨어질 대상이 아닌 것은 (-1이나 -2) 넘어간다.
            if(board1[i][j] == -2 || board1[i][j] == -1) continue;
            // 밑에 칸을 봤을 때 경계를 넘어가거나 빈 공간이 아니라면 넘어간다.
            if(OOB(i+1, j) || board1[i+1][j] != -2) continue;

            int idx = i;
            while(idx+1 < n && board1[idx+1][j] == -2) {
                swap(board1[idx][j], board1[idx+1][j]);
                idx++;
            }
        }
    }
}

void remove() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(biggest[i][j] == 0) continue;
            board1[i][j] = -2;
        }
    }
}

Info BFS(int x, int y) {
    Info group = {0, 0, 1, 0};

    int color = board1[x][y];
    bool vis[22][22];
    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, false);
    queue<pair<int, int>> Q;

    Q.push({x, y});
    board2[x][y] = 1;
    vis[x][y] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board1[nx][ny] == 0 || board1[nx][ny] == color) {
                Q.push({nx, ny});
                board2[nx][ny] = 1;
                vis[nx][ny] = true;
                if(board1[nx][ny] == 0) group.rainbow++;
                group.area++;
            }
        }
    }

    // 기준 블럭 찾기
    vector<pair<int, int>> blocks;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board2[i][j] == 0) continue;
            // 블록 중에서 무지개 블록을 제외한 좌표들을 blocks에 담는다.
            if(board1[i][j] == 0) continue;
            blocks.push_back({i, j});
        }
    }
    sort(blocks.begin(), blocks.end());
    group.x = blocks[0].first;
    group.y = blocks[0].second;

    return group;
}

int find_biggest_group() {
    Info mx_group = {-1, -1, -1, -1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            for(int i = 0; i < n; i++) fill(board2[i], board2[i]+n, 0);
            // 일반 블록을 기준으로 (-1, 0, -2 안됨)
            if(board1[i][j] <= 0) continue;

            Info group = BFS(i, j);

            // TEST2();
            // cout << "area: " << group.area << '\n';
            // cout << "rainbow: " << group.rainbow << '\n';
            // cout << "기준 블록: " << group.x << ' ' << group.y << '\n';
            // cout << '\n';

            if(group.area > mx_group.area) {
                board_copy();
                mx_group = group;
            }
            else if(group.area == mx_group.area) {
                if(group.rainbow > mx_group.rainbow) {
                    board_copy();
                    mx_group = group;
                }
                // 현재 그룹 무지개 블록이 같을 경우
                else if(group.rainbow == mx_group.rainbow) {
                    // 기준 블록의 행을 비교한다.
                    if(group.x > mx_group.x) {
                        board_copy();
                        mx_group = group;
                    }
                    else if(group.x == mx_group.x) {
                        // 기준 블록의 열을 비교한다.
                        if(group.y > mx_group.y) {
                            board_copy();
                            mx_group = group;
                        }
                    }
                }
            } // 비교 완료

        }
    } // 모든 좌표에 대하여 탐색 완료

    return mx_group.area;
}

void rotate90() {
    int tmp[22][22];
    for(int i = 0; i < n; i++) fill(tmp[i], tmp[i]+n, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i][j] = board1[n-j-1][i];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board1[i][j] = tmp[i][j];
        }
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board1[i][j];
    
    // ----
    while(1) {
        for(int i = 0; i < n; i++) fill(biggest[i], biggest[i]+n, 0);
        // 1. 크기가 가장 큰 블록 그룹을 찾기
        // 각 좌표를 돌면서 BFS()를 돌리고, board2에 그 모양을 담아둔다.
        // biggest에는 [영역의 크기 > 무지개블록 갯수 > 기준 블록 행 > 기준 블록 열] 순으로 비교해서
        // 집어넣는다.
        int score = find_biggest_group();

        if(score < 2) {
            cout << total << '\n';
            return 0;
        }

        // 2. 블록을 제거하고 점수를 획득
        remove();
        total += score * score;

        // 3. 중력
        fall();

        // 4. 회전
        for(int i = 0; i < 3; i++) rotate90();

        // 5. 다시 중력
        fall();
    }
}