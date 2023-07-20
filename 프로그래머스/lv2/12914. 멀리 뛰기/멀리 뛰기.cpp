#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20002];  // dp : i 번째 칸에 도달할 수 있는 방법의 수

ll solution(int n) {

    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    
    return dp[n];
}