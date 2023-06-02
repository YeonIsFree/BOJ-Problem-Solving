#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[103][103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        fill(d[i]+1, d[i]+1+n, INF);

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int i = 1; i <= n; i++) d[i][i] = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
   
    vector<int> score;

    int mn = INF;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += d[i][j];
        }
        if(mn > sum) {
            mn = sum;
            ans = i;
        }
    }
    cout << ans;
}
