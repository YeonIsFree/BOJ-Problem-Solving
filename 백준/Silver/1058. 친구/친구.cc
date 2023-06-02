#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 0x3f3f3f3f;
string input[53];
int d[53][53];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        fill(d[i], d[i]+n, INF);
    
    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < input[i].size(); j++) {
            if(input[i][j] == 'N') continue;
            d[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) d[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    int mx = -1;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(d[i][j] <= 2 && d[i][j] != 0) cnt++;
        }
        mx = max(mx, cnt);
    }   

    cout << mx;

}