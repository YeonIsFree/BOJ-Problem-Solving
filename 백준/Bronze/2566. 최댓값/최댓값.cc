#include <bits/stdc++.h>
using namespace std;

int input[9][9];
pair<int, int> a;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> input[i][j];
        }
    }

    int mx = -1;
    int prev_mx = mx;
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            // 현재 만난 수와 mx에 저장되어있는 수를 비교하여 mx를 갱신한다.
            mx = max(prev_mx, input[i][j]);
            // mx가 갱신되었다면 좌표를 저장한다.
            if(prev_mx != mx)
                a = {i+1, j+1};
            // 현재 mx를 잠시 저장해둔다.
            prev_mx = mx;
        }
    }
    cout << mx << '\n';
    cout << a.first << ' ' << a.second;
}