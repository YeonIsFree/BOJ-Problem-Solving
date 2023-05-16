#include <bits/stdc++.h>
using namespace std;

int m, n, cnt;

bool isprime(int n) {
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = m; i <= n; i++)
        if(isprime(i)) cout << i << '\n';
}