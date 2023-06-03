#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1026][1026];
int dp[1026][1026];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    while(m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d; 
        int ans = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
        cout << ans << '\n';
    }
}