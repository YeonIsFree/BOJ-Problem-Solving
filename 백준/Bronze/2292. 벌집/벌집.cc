#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 1;
    int stage_mx = 1;

    while(n > stage_mx)
        stage_mx = stage_mx + (6 * cnt++);
    
    cout << cnt;
}