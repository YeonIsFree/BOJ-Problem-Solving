#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[303][303];
int sum[303][303];
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
    
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;   
        ans = sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
        cout << ans << '\n';
    }
}