#include <bits/stdc++.h>
using namespace std;

int n;
int board[130][130];
int cnt[2]; // 0 1 

bool is_all_same(int x, int y, int k) {
    int target = board[x][y];
    for(int i = x; i < x + k; i++)
        for(int j = y; j < y + k; j++)
            if(target != board[i][j]) return false;
    return true;
}

void func(int x, int y, int k) {
    if(is_all_same(x, y, k)) {
        cnt[board[x][y]]++;
        return;
    }

    int u = k / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i*u, y + j*u, u);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    // ----
    func(0, 0, n);

    // 출력
    for(int i = 0; i < 2; i++)
        cout << cnt[i] << '\n';
}