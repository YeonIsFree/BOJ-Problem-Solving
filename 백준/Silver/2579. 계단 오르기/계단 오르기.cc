#include <bits/stdc++.h>
using namespace std;

int n;
int score[303];
int dp[303];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <=n; i++)
        cin >> score[i];
    
    dp[1] = score[1], dp[2] = score[1] + score[2];
    for(int i = 3; i <= n; i++) 
        dp[i] = max(dp[i-2], dp[i-3] + score[i-1]) + score[i];
    
    cout << dp[n];

}