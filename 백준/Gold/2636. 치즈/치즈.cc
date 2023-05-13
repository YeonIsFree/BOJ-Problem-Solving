#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int hours, prev_cnt;
int board[103][103];
bool vis[103][103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    queue<pair<int, int> > Q;    // 공기 확산 시킬 큐
    queue<pair<int, int> > nx_Q; // 녹을 치즈, 즉 다음 턴에 공기가 될 큐 
    
    Q.push({0, 0});
    vis[0][0] = 1;

    while(1) {
        // 한 턴 진행
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny]) continue;
                // 다음 칸이 공기인 경우 -> Q에 넣고 진행
                if(board[nx][ny] == 0) {
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
                // 다음 칸이 치즈인 경우 -> 녹을 치즈이므로 nx에 넣고 진행
                else {
                    nx_Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        // 만약 더 이상 썩어서 사라질 치즈가 없다면 종료한다.
        if(nx_Q.empty()) break;
        // 다음 턴에 썩을 치즈가 있다면,
        // 이번 턴에 쌓아둔 nx_Q의 좌표들이 다음 턴에 탐색할 공기 좌표가 된다. --> 따라서 큐 두개를 swap (현재 Q는 비어있음)
        else {
            prev_cnt = nx_Q.size();
            hours++;
            nx_Q.swap(Q);
        }
    } // 전체 반복 종료
    cout << hours << '\n';
    cout << prev_cnt;
}