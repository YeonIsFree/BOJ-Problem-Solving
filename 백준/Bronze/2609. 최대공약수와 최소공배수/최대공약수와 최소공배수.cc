#include <bits/stdc++.h>
using namespace std;

int x, y;

int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b % a, a);
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    cout << GCD(x, y) << '\n';
    cout << LCM(x, y);


}