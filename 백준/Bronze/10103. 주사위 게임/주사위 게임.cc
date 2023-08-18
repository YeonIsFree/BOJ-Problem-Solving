#include <bits/stdc++.h>
using namespace std;

int n;
int A = 100, B = 100;
int a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a == b) continue;
        if(a < b) A -= b;
        else if(a > b) B -= a;
    }

    cout << A << '\n';
    cout << B << '\n';
}