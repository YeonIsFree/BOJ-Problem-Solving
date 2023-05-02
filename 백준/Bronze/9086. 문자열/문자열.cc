#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0 ; i < t; i++) {
        cin >> s;
        cout << s[0] << s[s.size() - 1] << '\n';
    }
}