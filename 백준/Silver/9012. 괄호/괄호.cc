#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        string str;
        cin >> str;

        stack<char> S;

        for(char c : str) {
            if(S.empty()) {
                S.push(c);
                continue;
            }

            if(c == '(') S.push(c);
            else if(c == ')') {
                if(S.top() == '(') S.pop();
                else break;
            }
        }

        if(S.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}