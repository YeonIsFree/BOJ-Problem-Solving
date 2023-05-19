#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name = "", log = "";
        cin >> name >> log;
        if(log == "enter") s.insert(name);
        else s.erase(name); 
    }

    vector<string> ans(s.begin(), s.end()); // 오 이렇게도 옮겨 담을 수 있구나.
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto name : ans) cout << name << '\n';
}