#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[12][6];
bool vis[12][6];
bool is_puyo;
int cnt;

void puyo(int x, int y) {
    // bfs로 같은 색 뿌요를 찾는다.
    queue<pair<int, int>> Q;
    vector<pair<int, int>> p;
    Q.push({x, y});
    vis[x][y] = true;
    p.push_back({x, y});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if(vis[nx][ny] || board[nx][ny] == '.') continue;
            if(board[nx][ny] != board[cur.X][cur.Y]) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
            p.push_back({nx, ny});
        }
    }

    // 4개 이상 뭉쳐있는 뿌요 삭제
    if(p.size() >= 4) {
        is_puyo = true;
        for(auto cur : p) board[cur.X][cur.Y] = '.';
    }
}

void fall() {
    for(int j = 0; j < 6; j++) {
        for(int i = 10; i >= 0; i--) {
            int tmp = i;
            while(tmp < 11 && board[tmp+1][j] == '.') {
                swap(board[tmp][j], board[tmp+1][j]);
                tmp++;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 6; j++)
            cin >> board[i][j];
    
    // 더이상 터질 뿌요가 없을 때까지 
    do {
        is_puyo = false;
        // 뿌요 아래에 있는 애들은 떨어뜨린다.
        fall();

        // BFS로 같은 색깔 애들을 표시하고
        // 4개 이상 모여있으면 터뜨린다.
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(vis[i][j] || board[i][j] == '.') continue;
                puyo(i, j);
            }
        }
        if(is_puyo) cnt++;

        for(int i = 0; i < 12; i++) 
            for(int j = 0; j < 6; j++)
                vis[i][j] = false;

    } while(is_puyo);

    cout << cnt;
    
}