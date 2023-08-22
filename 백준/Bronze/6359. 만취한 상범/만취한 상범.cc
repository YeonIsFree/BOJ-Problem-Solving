#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        int cnt = 0;
        for(int i = 1; i * i <= n; i++) {
            cnt++;
        }
        cout << cnt << '\n';
    }
}