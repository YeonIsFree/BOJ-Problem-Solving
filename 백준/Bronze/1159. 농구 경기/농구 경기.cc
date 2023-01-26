#include <bits/stdc++.h>
using namespace std;

int n; // 선수의 수
int cnt[26]; // 카운팅 배열
vector<char> a; // 선수들 성 앞글자를 담은 배열
string s; // 선수의 성


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> s;
        a.push_back(s[0]);
    }
    
    for(auto c : a) cnt[c - 'a']++;
    
    bool checker = false;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            cout << char(i + 'a');
            checker = true;
        }
    }

    if(checker == false) cout << "PREDAJA";
    return 0;
}