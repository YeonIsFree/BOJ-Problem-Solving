#include <bits/stdc++.h>
using namespace std;

int n, k, temp;
int psum[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    int mx = -10000004;
    for(int i = k; i <= n; i++) {
        mx = max(mx, psum[i] - psum[i - k]);
    }

    cout << mx;
    return 0;
    
}