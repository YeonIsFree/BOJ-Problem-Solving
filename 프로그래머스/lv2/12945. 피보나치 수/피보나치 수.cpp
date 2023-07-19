#include <bits/stdc++.h>
using namespace std;

long long dp[100002];

int solution(int n) {
    // DP
    // (A + B) % C = (A % C) + (B % C) 를 이용
 
    // 초기값 
    dp[0] = 0; dp[1] = 1; 
    for(int i = 2; i <= 100000; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;

    return dp[n];
    

}