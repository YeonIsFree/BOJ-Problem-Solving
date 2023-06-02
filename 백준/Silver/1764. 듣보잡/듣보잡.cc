#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> names;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        names[s]++;
    }
    
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        names[s]++;
    }

    vector<pair<string, int> > name_list(names.begin(), names.end());
    vector<string> ans;

    for(auto s : name_list) {
        string n; int cnt;
        tie(n, cnt) = s;
        if(cnt == 2) ans.push_back(n);
    }

    cout << ans.size() << '\n';

    sort(ans.begin(), ans.end());
    for(string name : ans)
        cout << name << '\n';
}