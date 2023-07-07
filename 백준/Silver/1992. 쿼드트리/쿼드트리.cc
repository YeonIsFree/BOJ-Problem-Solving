#include <bits/stdc++.h>
using namespace std;

int n;
string board[65];

bool is_all_same(int x, int y, int k) {
    int num = board[x][y];
    for(int i = x; i < x + k; i++)
        for(int j = y; j < y + k; j++)
            if(num != board[i][j]) return false;
    return true;
}

void func(int x, int y, int k) {
    if(is_all_same(x, y, k)) {
        if(board[x][y] == '0') cout << 0;
        else cout << 1;  
        return;
    }

    cout << "(";
    int u = k / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + (i*u), y + (j*u), u);
    cout << ")";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    // -----
    func(0, 0, n);

}