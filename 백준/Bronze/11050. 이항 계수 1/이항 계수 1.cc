#include <bits/stdc++.h>
using namespace std;

int n, k;

// nCk
// 5C3 = 5! / (3! * 2!)

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    int ret = 1;
    for(int i = 1; i <= n; i++)
        ret *= i;
    for(int i = 1; i <= k; i++)
        ret /= i;
    for(int i = 1; i <= n-k; i++)
        ret /= i;

    cout << ret;

}