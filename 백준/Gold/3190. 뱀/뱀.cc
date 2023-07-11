#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, k, l;
int board[102][102];
deque<pair<int, int>> snake;
queue<pair<int, char>> orders;
int sec;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int cur_x = 0, cur_y = 0;
        cin >> cur_x >> cur_y;
        board[cur_x][cur_y] = -1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        orders.push({x, c});
    }

    // ---
    int dir = 1; // 초기 방향: 오른쪽
    snake.push_back({1, 1});

    while(1) {
        // 현재 좌표에 몸 표시
        auto cur = snake.front();
        board[cur.first][cur.second] = 1;

        // 다음 좌표 결정 + 시간 1초 흐름
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        sec++;

        // 벽에 닿았거나 몸에 닿았으면 탈출
        if(nx < 1 || ny < 1 || nx > n || ny > n) break;
        if(board[nx][ny] == 1) break;

        // 현재 좌표로 머리 늘리기
        snake.push_front({nx, ny});

        // 만약 다음 좌표에 사과가 아니라면 꼬리를 당겨와서 길이를 유지한 채 전진
        if(board[nx][ny] != -1) {
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        // 때가 되면 방향 회전
        int order_time = orders.front().first;
        if(!orders.empty() && sec == order_time) {
            char order = orders.front().second;
            if(order == 'D') dir = (dir + 1) % 4;
            else if(order == 'L') dir = (dir + 3) % 4;
            orders.pop();
        }
    }
    cout << sec;
}