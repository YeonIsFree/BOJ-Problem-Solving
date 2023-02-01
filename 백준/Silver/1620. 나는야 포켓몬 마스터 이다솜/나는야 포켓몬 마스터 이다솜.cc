#include <bits/stdc++.h>
using namespace std;

//  n : 포켓몬 갯수
//  m : 문제의 갯수

int n, m;
string s;

map<string, int> mp;
map<int, string> mp2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = i + 1;
        mp2[i + 1] = s;

    }

    for(int i = 0; i < m; i++) {
        cin >> s;
        if(atoi(s.c_str()) == 0) cout << mp[s] << '\n';
        else {
            int num = atoi(s.c_str());
            cout << mp2[num] << '\n';
        }
    }
}
