#include <bits/stdc++.h>
using namespace std;

int dp[100002][4];
int mx;

int solution(vector<vector<int> > land)
{
    int len = land.size();
    
    for(int i = 0; i < 4; i++) dp[0][i] = land[0][i];
    
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][0] = max({dp[i-1][1], dp[i-1][2], dp[i-1][3]}) + land[i][0];
            dp[i][1] = max({dp[i-1][0], dp[i-1][2], dp[i-1][3]}) + land[i][1];
            dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][3]}) + land[i][2];
            dp[i][3] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + land[i][3];
        }
    }
    
    for(int i = 0; i < 4; i++)
        mx = max(dp[len-1][i], mx);
    
    return mx;
    
}