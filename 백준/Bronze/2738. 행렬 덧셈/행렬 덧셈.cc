#include <bits/stdc++.h>
using namespace std;

int n, m;
int board1[103][103];
int board2[103][103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board1[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board2[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << board1[i][j] + board2[i][j] << ' ';
        cout << '\n';
    } 
}