#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> plist;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string url = "";
        string password = "";
        cin >> url >> password;
        plist[url] = password;
    }

    for(int i = 0; i < m; i++) {
        string s = "";
        cin >> s;
        cout << plist[s] << '\n';
    }
}