#include <bits/stdc++.h>
using namespace std;

int n;
// ....*
// ...***
// ..*****
// .*******
// *********

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // n = 5
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int blank = n-i;
        int stars = 2*i - 1;
        while(blank--) {
            cout << " " ;
        }
        while(stars--) {
            cout << "*" ;
        }
        cout << '\n';
    }
}