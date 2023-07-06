#include <bits/stdc++.h>
using namespace std;

int k;
int board[2190][2190];
map<int, int> cnt; // -1, 0, 1

bool is_all_same(int x, int y, int n) {
    int num = board[x][y];
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(num != board[i][j]) return false;
    return true;   
}

void func(int x, int y, int n) {
    // 모두 같은 숫자인지 검사, 맞다면 해당 숫자의 카운트를 하나 올려준다.
    if(is_all_same(x, y, n)) {
        int num = board[x][y];
        cnt[num]++;
        return;
    }

    // 모두 같은 숫자가 아니라면, 9 분할 한다.
    // ----- 여기 이해 잘 안감
    int s = n / 3;  
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            func(x + (i * s), y + (j * s), s);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> k;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            cin >> board[i][j];

    // ----
    func(0, 0, k);

    // 각 숫자의 갯수를 출력
    cout << cnt[-1] << '\n';
    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
}