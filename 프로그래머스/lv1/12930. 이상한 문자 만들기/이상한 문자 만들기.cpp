#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string ans = "";
    int len = s.size();
    int idx = 0;
    for(int i = 0; i < len; i++) {
        // 공백이라면 idx를 초기화하고, 공백을 이어붙여준다.
        if(s[i] == ' ') {
            ans += ' ';
            idx = 0;
            continue;
        }
        // 짝수 인덱스라면 대문자로
        if(idx % 2 == 0) ans += toupper(s[i]);
        // 홀수 인덱스라면 소문자로
        else ans += tolower(s[i]);
        
        idx++; 
    }
    
    return ans;
}