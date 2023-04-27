#include <bits/stdc++.h>
using namespace std;

// dp[k][n] = dp[k-1][n] + dp[k][n-1]
int t, k, n;

int func(int k, int n) {
    // 0층 거주민일 경우
    if(k == 0) return n;
    // 1호 라인 거주민일 경우
    if(n == 1) return 1;
    return func(k-1, n) + func(k, n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> k >> n;
        cout << func(k, n) << '\n';
    }
}