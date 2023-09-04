#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[52];

void TEST() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cout << board[i][j];
        cout << '\n';
    }
}

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return true;
    return false;
}

void fall(int x, int y) {
    while(x+1 < n && board[x+1][y] == '.') {
        swap(board[x][y], board[x+1][y]);
        x++;
    } 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> board[i];
    
    // ----
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            // 사과가 아닌 칸은 넘어간다.
            if(board[i][j] == '#' || board[i][j] == '.') continue;
            // 사과 밑에 빈 칸이 있는지, 혹은 경계를 넘어가는지 확인한다.
            if(OOB(i+1, j) || board[i+1][j] != '.') continue;
            // 여기까지 왔다면 사과 밑에 빈칸이 있다는 뜻이므로 맨 아래까지 떨어뜨린다.
            fall(i, j);
        }
    }

    TEST();
}