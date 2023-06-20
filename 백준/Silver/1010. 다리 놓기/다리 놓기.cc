#include <bits/stdc++.h>
using namespace std;

int t;
long long ans;
long long dp[32][32];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int i = 1; i <= 30; i++) {
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}
