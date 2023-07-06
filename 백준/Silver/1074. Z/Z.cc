#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int func(int n, int x, int y) {
    // Base condition
    if(n == 0) return 0;
    
    int half = 1 << (n-1);
    // 1
    if(x < half && y < half) return func(n-1, x, y);
    // 2
    else if(x < half && y >= half) return half * half + func(n-1, x, y-half);
    // 3
    else if(x >= half && y < half) return 2 * half * half + func(n-1, x-half, y);
    // 4
    else return 3 * half * half + func(n-1, x-half, y-half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    cout << func(n, r, c);
}