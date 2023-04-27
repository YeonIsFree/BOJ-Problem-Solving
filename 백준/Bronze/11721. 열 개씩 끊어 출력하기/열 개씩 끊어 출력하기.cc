#include <bits/stdc++.h>
using namespace std;

string s;
// BaekjoonOnlineJudge
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
        int real_idx = i + 1;
        if(real_idx % 10 == 0) {
            cout << '\n';
        }
    }
}