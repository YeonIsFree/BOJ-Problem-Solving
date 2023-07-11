#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, k, a, b, l, c;
char d;
int board[102][102];
queue<pair<int, char>> orders;
deque<pair<int, int>> Q;    // 뱀의 몸통
int sec;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        board[a-1][b-1] = -1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> c >> d;
        orders.push({c, d});
    }

    // 초기 정보
    Q.push_back({0, 0});
    int dir = 1;
    
    // -----
    while(1) {
        // 현재 좌표로 몸 표시
        auto cur = Q.front();
        board[cur.X][cur.Y] = 1;

        // 다음 좌표 구하기
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
  
        // 1초 경과
        sec++;

        // 만약 몸에 닿거나 벽에 닿으면 게임 오버
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;
        if(board[nx][ny] == 1) break;

        // 이동한 칸으로 머리를 늘려준다.
        Q.push_front({nx, ny});

        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.
        if(board[nx][ny] != -1) {
            auto tail = Q.back();
            board[tail.X][tail.Y] = 0;
            Q.pop_back();
        }

        // 때가 되면 회전
        auto order = orders.front();
        if(order.X == sec) {
            if(order.Y == 'L') dir = (dir+3) % 4;
            else if(order.Y == 'D') dir = (dir+1) % 4;
            orders.pop();
        }
    }
    cout << sec;
}