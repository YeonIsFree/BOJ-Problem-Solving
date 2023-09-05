#include <bits/stdc++.h>
using namespace std;

int t, n;
int board[3][100002];
int dp[3][100002];

void TEST() {
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        // ---- input
        cin >> n;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> board[i][j];
   

        // ---- init
        for(int i = 0; i < 3; i++) fill(dp[i], dp[i]+n+1, 0);

        // ---- dp
        dp[1][1] = board[1][1], dp[2][1] = board[2][1];
        for(int j = 1; j <= n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[2][j-1]);
            dp[1][j] = max(dp[0][j-1], dp[2][j-1]) + board[1][j];
            dp[2][j] = max(dp[0][j-1], dp[1][j-1]) + board[2][j];
        }

        // TEST();

        // --- output
        int mx = -1;
        for(int i = 0; i < 3; i++)
            mx = max(dp[i][n], mx);
        
        cout << mx << '\n';
    }
}