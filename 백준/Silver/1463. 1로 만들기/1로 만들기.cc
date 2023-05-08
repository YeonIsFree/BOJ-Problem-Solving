#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    if(n == 1) {
        cout << d[n];
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        // 3으로도, 2로도 안나누어 떨어지는 경우
        d[i] = d[i-1] + 1;

        // 3으로 나누어 떨어지는 경우
        if(i % 3 == 0) 
            d[i] = min(d[i], d[i/3] + 1);

        // 2로 나누어 떨어지는 경우
        if(i % 2 == 0)
            d[i] = min(d[i], d[i/2] + 1);
    }

    cout << d[n];
}