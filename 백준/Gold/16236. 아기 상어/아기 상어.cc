#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int INF = 0x7f7f7f7f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int x, y;
int shark_size = 2;
int board[22][22];
int dist[22][22];

tuple<int, int, int> get_dist(int x, int y) {
    tuple<int, int, int> mn_dist = {INF, INF, INF};     // {거리, x, y}
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);  // dist 배열 -1로 초기화
    queue<pair<int, int> > Q;
    Q.push({x, y});
    dist[x][y] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 9) {
                dist[i][j] = 0;
                board[i][j] = 0;
            } 
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int dist_cur = get<0>(mn_dist);
        if(dist[cur.X][cur.Y] >= dist_cur) break;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] > shark_size || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            if(board[nx][ny] != 0 && board[nx][ny] < shark_size)
                mn_dist = min(mn_dist, {dist[nx][ny], nx, ny});
            Q.push({nx, ny});
        }
    }

    return mn_dist;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            // 초기 상어의 위치 좌표는 따로 저장한다.
            if(board[i][j] == 9) {
                x = i;
                y = j;
                board[i][j] = 0;
            }
        }
    }

    // ----
    int time = 0, cnt = 0;

    queue<pair<int, int> > Q;

    while(1) {
        tuple<int, int, int> mn_dist = get_dist(x, y);
        int dist = 0, nx = 0, ny = 0;
        tie(dist, nx, ny) = mn_dist;

        // 1) 잡아먹을 물고기가 하나도 없는 경우
        if(dist == INF) break;
        // 2) 하나 이상 있는 경우 물고기를 먹는다.
        cnt++;
        //   2-1) 만약 먹은 물고기 개수가 현재 상어 크기와 같다면,
        //        상어 크기를 올려주고 cnt 를 초기화 시켜 준다.
        if(cnt == shark_size) {
            cnt = 0;
            shark_size++;
        }

        time += dist;
        Q.push({nx, ny});
        
        // 다음 턴으로 넘어가기 전에 상어의 위치 갱신
        board[nx][ny] = 9;
        x = nx;
        y = ny;
    }  

    cout << time;
    
}