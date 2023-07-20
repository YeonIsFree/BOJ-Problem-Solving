#include <bits/stdc++.h>
using namespace std;

int mx;

int solution(vector<vector<int>> board)
{
    int row_len = board.size();
    int col_len = board[0].size();
    
    int dp[row_len + 1][col_len + 1];
    
    for(int i = 0; i < row_len + 1; i++) fill(dp[i], dp[i] + col_len + 1, 0);
    
    for(int i = 0; i < row_len; i++)
        for(int j = 0; j < col_len; j++)
            dp[i+1][j+1] = board[i][j];
    
    for(int i = 1; i <= row_len; i++) {
        for(int j = 1; j <= col_len; j++) {
            if(dp[i][j] == 0) continue;
            dp[i][j] = min( {dp[i-1][j], dp[i][j-1], dp[i-1][j-1]} ) + 1;
            mx = max(dp[i][j], mx);
        }
    }
    
    return mx * mx;
}