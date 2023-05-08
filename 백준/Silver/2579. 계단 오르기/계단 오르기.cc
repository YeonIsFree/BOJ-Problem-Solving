#include <bits/stdc++.h>
using namespace std;

int n;
int dp[303][3];
int score[303];

// dp[i][j] : 현재까지 j개의 계단을 연속으로 밟고 i로 올라옴

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> score[i];
    // 초기값 설정
    dp[1][1] = score[1], dp[1][2] = 0;
    dp[2][1] = score[2], dp[2][2] = score[1] + score[2];

    if(n == 1) {
        cout << score[1];
        return 0;
    }

    for(int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + score[i];
        dp[i][2] = dp[i-1][1] + score[i];
    }

    cout << max(dp[n][1], dp[n][2]);
}