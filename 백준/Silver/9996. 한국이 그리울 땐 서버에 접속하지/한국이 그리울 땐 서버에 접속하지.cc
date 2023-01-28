#include <bits/stdc++.h>
using namespace std;

int n;
string s, p, pre, suf; // prefix, suffix

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> p;

    int pos = p.find('*');
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);

    while(n--) {
        cin >> s;
        if(s.size() < pre.size() + suf.size()) cout << "NE\n";
        else {
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}