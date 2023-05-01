#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    vector<int> make_team(n, 1);
    for(int i = 0; i < (n/2); i++) {
        make_team[i] = 0;
    }
    int ans = 9876;
    do {
        int diff = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // 나와 내 다음 비교 대상이 서로 다른 팀이면 패스
                if(make_team[i] != make_team[j]) continue;
                if(make_team[i] == 0)
                    diff += (board[i][j] + board[j][i]);
                if(make_team[i] == 1)
                    diff -= (board[i][j] + board[j][i]);
            }
        }
        ans = min(ans, abs(diff));
    } while(next_permutation(make_team.begin(), make_team.end()));
    
    cout << ans;

}