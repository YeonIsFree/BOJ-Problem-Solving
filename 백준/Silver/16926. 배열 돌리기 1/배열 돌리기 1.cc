#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int board[302][302];

void rotate(int x1, int y1, int x2, int y2) {
    int tmp = board[x1][y1];
    for(int j = y1; j < y2; j++) board[x1][j] = board[x1][j+1];
    for(int i = x1; i < x2; i++) board[i][y2] = board[i+1][y2]; 
    for(int j = y2; j > y1; j--) board[x2][j] = board[x2][j-1];
    for(int i = x2; i > x1; i--) board[i][y1] = board[i-1][y1];
    board[x1+1][y1] = tmp;
}

void rotate() {
    int x1 = 0, y1 = 0;
    int x2 = n-1, y2 = m-1;
    while(x1 < x2 && y1 < y2) rotate(x1++, y1++, x2--, y2--);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //--- input
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    //----
    while(r--) {
        rotate();
    }

    //--- output
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}