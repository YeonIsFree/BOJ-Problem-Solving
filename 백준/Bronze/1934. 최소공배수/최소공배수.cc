#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b % a, a); // gcd(a, b) = (a % b, b)
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b; // a * b = gcd(a, b) * lcm(a, b)
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << LCM(a, b) << '\n';
    }

}