#include <bits/stdc++.h>
using namespace std;

int n;
main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int temp = 1;
    for(int i = 0; i < n; i++) {
        temp = temp * 2;
    }
    cout << temp;
}