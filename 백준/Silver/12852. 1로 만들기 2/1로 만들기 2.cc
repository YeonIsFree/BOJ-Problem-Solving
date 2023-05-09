#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000003];
int pre[1000003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        // 일단 -1 한 상태로 모두 채워둠
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        // 2로 나누어 떨어질 경우, 그리고 -1 을 하는 것보다 나누기 2 하는게 이득일 경우
        if(i % 2 == 0 && (dp[i] > dp[i/2] + 1)) {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }

        // 3으로 나누어 떨어질 경우, 그리고 -1 을 하는 것보다 나누기 3 하는 것이 더 이득일 경우
        if(i % 3 == 0 && (dp[i] > dp[i/3] + 1)) {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';

    while(1) {
        cout << n << ' ';
        if(n == 1) break;
        n = pre[n];
    }
}