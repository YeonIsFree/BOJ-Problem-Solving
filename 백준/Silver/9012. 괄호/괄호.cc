#include <bits/stdc++.h>
using namespace std;

int t;
string s;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        stack<char> S;
        cin >> s;
        for(char c : s) {
            if(S.empty()) {
                S.push(c);
                continue;
            }

            if(c == '(') S.push(c);
            else { // c == ')'
                if(S.top() == '(') S.pop();
                else S.push(c);
            }
        }

        if(S.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

}