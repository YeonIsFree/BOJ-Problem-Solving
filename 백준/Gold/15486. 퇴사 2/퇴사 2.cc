#include <bits/stdc++.h>
using namespace std;

int n, sum, mx;
vector<int> T = {0, };
vector<int> P = {0, };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        T.push_back(a);
        P.push_back(b);
    }

    // ----
    int dp[n+2];    // n일째에 하루짜리 일을 하면 n+1일째가 최대 수익이기 때문에 n+2로 배열의 크기를 정해준다.
    fill(dp, dp+n+2, 0);
    
    for(int i = 1; i <= n; i++) {
        // 오늘 작업의 결과 반영
        int nx = i + T[i];
        if(nx <= n+1) dp[nx] = max(dp[i] + P[i], dp[nx]);
        dp[i+1] = max(dp[i], dp[i+1]);
    }

    mx = dp[n+1];

    cout << mx;

}